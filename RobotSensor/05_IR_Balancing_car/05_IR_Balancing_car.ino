#define PIN_IR_L 12
#define PIN_IR_R 13

#define LINE 1
#define NO_LINE 0

#define GET_IR_L digitalRead(PIN_IR_L)
#define GET_IR_R digitalRead(PIN_IR_R)

#define WHEEL_DIFF_VALUE -15

int iSpeed = 150;
int leftWheelSpeed = iSpeed;
int rightWheelSpeed = leftWheelSpeed + WHEEL_DIFF_VALUE;

#define ENA 5
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define ENB 10

#define OUTPUT_TEAPOT 1
#define MIN_ABS_SPEED 160
#define OUTPUT_READABLE_YAWPITCHROLL
#define INTERRUPT_PIN 2

#include <PID_v1.h>
#include "LMotorController.h"
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

MPU6050 mpu;
bool dmpReady = false;
uint8_t mpuIntStatus;
uint8_t devStatus;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];

Quaternion q;
VectorFloat gravity;
float ypr[3];
double input, output;
double originalSetpoint = 185.0;
double setpoint = originalSetpoint;
double movingAngleOffset = 0.3;
PID pid(&input, &output, &setpoint, 60., 200., 1.5, DIRECT);

LMotorController motorController(ENA, IN1, IN2, ENB, IN3, IN4, 1, 1);

volatile bool mpuInterrupt = false;

void dmpDataReady() {
    mpuInterrupt = true;
}

void setup() {
    Wire.begin();
    Wire.setClock(400000);
    Serial.begin(115200);
    while (!Serial);

    mpu.initialize();
    pinMode(PIN_IR_L, INPUT);
    pinMode(PIN_IR_R, INPUT);
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    devStatus = mpu.dmpInitialize();
    mpu.setXAccelOffset(-2921);
    mpu.setYAccelOffset(-38);
    mpu.setZAccelOffset(855);
    mpu.setXGyroOffset(-195);
    mpu.setYGyroOffset(56);
    mpu.setZGyroOffset(9);

    if (devStatus == 0) {
        mpu.setDMPEnabled(true);
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
        pid.SetMode(AUTOMATIC);
        pid.SetSampleTime(10);
        pid.SetOutputLimits(-255, 255);
    } else {
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
}

void loop() {
    if (!dmpReady) return;

    while (!mpuInterrupt && fifoCount < packetSize) {
        pid.Compute();
        motorController.move(output, MIN_ABS_SPEED);
    }

    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();

    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));
    } else if (mpuIntStatus & 0x02) {
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        fifoCount -= packetSize;

        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        input = ypr[1] * 180/M_PI + 180;

        if (GET_IR_L == LINE && GET_IR_R == NO_LINE) {
            left();
        } else if (GET_IR_R == LINE && GET_IR_L == NO_LINE) {
            right();
        } else if (GET_IR_L == LINE && GET_IR_R == LINE) {
            stop();
        } else {
            forward();
        }
    }
}

void carMove(int aa, int ab, int ba, int bb) {
    analogWrite(ENA, aa);
    analogWrite(IN1, ab);
    analogWrite(IN2, ba);
    analogWrite(IN3, bb);
}

void forward() {
    carMove(leftWheelSpeed, 0, rightWheelSpeed, 0);
}

void backward() {
    carMove(0, leftWheelSpeed, 0, rightWheelSpeed);
}

void left() {
    carMove(0, leftWheelSpeed, rightWheelSpeed * 0.8, 0);
}

void right() {
    carMove(leftWheelSpeed * 0.8, 0, 0, rightWheelSpeed);
}

void stop() {
    carMove(0, 0, 0, 0);
}