#include <Wire.h>
#include <PCA9685.h>

PCA9685 pwmController(Wire, PCA9685_PhaseBalancer_Weaved); // Library using Wire1 and weaved phase balancing scheme
PCA9685_ServoEvaluator pwmServo1;
int tangankanan=0;
void setup() {
    Serial.begin(115200);

    Wire.begin();                      // Wire must be started first
    Wire.setClock(400000);             // Supported baud rates are 100kHz, 400kHz, and 1000kHz

    pwmController.resetDevices();       // Software resets all PCA9685 devices on Wire line

    pwmController.init(B000000);        // Address pins A5-A0 set to B000000
    pwmController.setPWMFrequency(50);  // 50Hz provides 20ms standard servo phase length
}

void loop() {
  pwmController.setChannelPWM(tangankanan, pwmServo1.pwmForAngle(180));
  delay(1000);
  pwmController.setChannelPWM(tangankanan, pwmServo1.pwmForAngle(0));
  delay(1000);
}
