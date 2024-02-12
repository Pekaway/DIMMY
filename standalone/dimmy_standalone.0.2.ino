#define buttonPin 0
#define ledPin 8
#define pcbLed 1
#include "FaBoPWM_PCA9685.h"
//CHANGE IN LIB
///** PCA9685 Slave Address register */
//#define PCA9685_SLAVE_ADDRESS 0x55


//Dimmy Standalone Version v0.0.1

#define DEBUG

FaBoPWM faboPWM;

bool counterRun = false;
int interval = 5;
int timerCounter = 0;
unsigned long previousMillis = 0;
boolean light0 = false;
boolean light1 = false;
boolean light2 = false;
boolean light3 = false;
boolean light4 = false;
boolean light5 = false;
boolean light6 = false;
boolean hold = false;
byte pwm0 = 100; // Default brightness
byte pwm1 = 100; // Default brightness
byte pwm2 = 100; // Default brightness
byte pwm3 = 100; // Default brightness
byte pwm4 = 100; // Default brightness
byte pwm5 = 100; // Default brightness
byte pwm6 = 100; // Default brightness
boolean pwm0Direction = 0;
boolean pwm1Direction = 0;
boolean pwm2Direction = 0;
boolean pwm3Direction = 0;
boolean pwm4Direction = 0;
boolean pwm5Direction = 0;
boolean pwm6Direction = 0;
int pwmPCA = 0;
boolean rampReady0 = false;
boolean rampReady1 = false;
boolean rampReady2 = false;
boolean rampReady3 = false;
boolean rampReady4 = false;
boolean rampReady5 = false;
boolean rampReady6 = false;
double dimmerstep = 2.55;

// Heartbeat
byte pcbLedpwm = 0;
boolean upward = true;
// Timer
int forCounter = 0;
int channelselect = 10;
int pressed = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("START");

  pinMode(0, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);

  if (faboPWM.begin()) {
    Serial.println("Find PCA9685");

    // Initialize 6 channels
    for (int a = 0; a < 6; a++) {
      faboPWM.init(a);
    }
    Serial.println("initialized");
  }
  faboPWM.set_hz(300);

  // turn all slightly on and off again for setup
  for (int a = 0; a < 7; a++) {
    faboPWM.set_channel_value(a, 3);
    delay(1);
  }
  for (int a = 0; a < 7; a++) {
    faboPWM.set_channel_value(a, 3);
    delay(1);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  //check button
  if (digitalRead(0) == LOW )
  {
    channelselect = 7;
    pressed = 1;
  }
  if (digitalRead(2) == LOW )
  {
    channelselect = 0;
    pressed = 1;
  }
  if (digitalRead(4) == LOW )
  {
    channelselect = 1;
    pressed = 1;
  }
  if (digitalRead(5) == LOW )
  {
    channelselect = 2;
    pressed = 1;
  }
  if (digitalRead(17) == LOW )
  {
    channelselect = 3;
    pressed = 1;
  }
  if (digitalRead(18) == LOW )
  {
    channelselect = 4;
    pressed = 1;
  }
  if (digitalRead(19) == LOW )
  {
    channelselect = 5;
    pressed = 1;
  }
  if (digitalRead(32) == LOW )
  {
    channelselect = 6;
    pressed = 1;
  }

  //CHECKS
  if (pressed == 1) {
    counterRun = true;
    Serial.print("channel: ");
    Serial.println(channelselect);
  }
  else {
    counterRun = false;
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (counterRun == true) timerCounter++;

    // Brightness control --- this is where the dimming happens!
    if (channelselect == 0  && rampReady0 == true && light0 == true && hold == true) {
      if (pwm0Direction == 0 && pwm0 <= 253) {
        pwm0 = pwm0 + dimmerstep;
        Serial.println(pwm0);
      }
      else if (pwm0Direction == 1 && pwm0 >= 6) {
        pwm0 = pwm0 - dimmerstep;
        Serial.println(pwm0);
      }
    }
    if (channelselect == 1  && rampReady1 == true && light1 == true && hold == true) {
      if (pwm1Direction == 0 && pwm1 <= 253) {
        pwm1 = pwm1 + dimmerstep;
        Serial.println(pwm1);
      }
      else if (pwm1Direction == 1 && pwm1 >= 6) {
        pwm1 = pwm1 - dimmerstep;
        Serial.println(pwm1);
      }
    }
    if (channelselect == 2  && rampReady2 == true && light2 == true && hold == true) {
      if (pwm2Direction == 0 && pwm2 <= 253) {
        pwm2 = pwm2 + dimmerstep;
        Serial.println(pwm2);
      }
      else if (pwm2Direction == 1 && pwm2 >= 6) {
        pwm2 = pwm2 - dimmerstep;
        Serial.println(pwm2);
      }
    }
    if (channelselect == 3  && rampReady3 == true && light3 == true && hold == true) {
      if (pwm3Direction == 0 && pwm3 <= 253) {
        pwm3 = pwm3 + dimmerstep;
        Serial.println(pwm3);
      }
      else if (pwm3Direction == 1 && pwm3 >= 6) {
        pwm3 = pwm3 - dimmerstep;
        Serial.println(pwm3);
      }
    }
    if (channelselect == 4  && rampReady4 == true && light4 == true && hold == true) {
      if (pwm4Direction == 0 && pwm4 <= 253) {
        pwm4 = pwm4 + dimmerstep;
        Serial.println(pwm4);
      }
      else if (pwm4Direction == 1 && pwm4 >= 6) {
        pwm4 = pwm4 - dimmerstep;
        Serial.println(pwm4);
      }
    }
    if (channelselect == 5  && rampReady5 == true && light5 == true && hold == true) {
      if (pwm5Direction == 0 && pwm5 <= 253) {
        pwm5 = pwm5 + dimmerstep;
        Serial.println(pwm5);
      }
      else if (pwm5Direction == 1 && pwm5 >= 6) {
        pwm5 = pwm5 - dimmerstep;
        Serial.println(pwm5);
      }
    }
    if (channelselect == 6  && rampReady6 == true && light6 == true && hold == true) {
      if (pwm6Direction == 0 && pwm6 <= 253) {
        pwm6 = pwm6 + dimmerstep;
        Serial.println(pwm6);
      }
      else if (pwm6Direction == 1 && pwm6 >= 6) {
        pwm6 = pwm6 - dimmerstep;
        Serial.println(pwm6);
      }
    }
  }

  // Ramping up the Brightness
  if (channelselect == 0) {
    if (light0 == true && rampReady0 == false) {
      for (int a = 0; a < pwm0; a++) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(10);
      }
      rampReady0 = true;
    }
  }
  if (channelselect == 1) {
    if (light1 == true && rampReady1 == false) {
      for (int a = 0; a < pwm1; a++) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(5);
      }
      rampReady1 = true;
    }
  }
  if (channelselect == 2) {
    if (light2 == true && rampReady2 == false) {
      for (int a = 0; a < pwm2; a++) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(5);
      }
      rampReady2 = true;
    }
  }
  if (channelselect == 3) {
    if (light3 == true && rampReady3 == false) {
      for (int a = 0; a < pwm3; a++) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(5);
      }
      rampReady3 = true;
    }
  }
  if (channelselect == 4) {
    if (light4 == true && rampReady4 == false) {
      for (int a = 0; a < pwm4; a++) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(5);
      }
      rampReady4 = true;
    }
  }
  if (channelselect == 5) {
    if (light5 == true && rampReady5 == false) {
      for (int a = 0; a < pwm5; a++) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(5);
      }
      rampReady5 = true;
    }
  }
  if (channelselect == 6) {
    if (light6 == true && rampReady6 == false) {
      for (int a = 0; a < pwm6; a++) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(5);
      }
      rampReady6 = true;
    }
  }

  // Ramping down the Brightness
  if (channelselect == 0) {
    if (light0 == false && rampReady0 == false) {
      for (int a = pwm0; a > 1; a--) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(3);
      }
      rampReady0 = true;
    }
  }
  if (channelselect == 1) {
    if (light1 == false && rampReady1 == false) {
      for (int a = pwm1 ; a > 1; a--) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(3);
      }
      rampReady1 = true;
    }
  }
  if (channelselect == 2) {
    if (light2 == false && rampReady2 == false) {
      for (int a = pwm2 ; a > 1; a--) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(3);
      }
      rampReady2 = true;
    }
  }
  if (channelselect == 3) {
    if (light3 == false && rampReady3 == false) {
      for (int a = pwm3 ; a > 1; a--) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(3);
      }
      rampReady3 = true;
    }
  }
  if (channelselect == 4) {
    if (light4 == false && rampReady4 == false) {
      for (int a = pwm4 ; a > 1; a--) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(3);
      }
      rampReady4 = true;
    }
  }
  if (channelselect == 5) {
    if (light5 == false && rampReady5 == false) {
      for (int a = pwm5 ; a > 1; a--) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(3);
      }
      rampReady5 = true;
    }
  }
  if (channelselect == 6) {
    if (light6 == false && rampReady6 == false) {
      for (int a = pwm6 ; a > 1; a--) {
        pwmPCA = a * 16;
        faboPWM.set_channel_value(channelselect, pwmPCA);
        delay(3);
      }
      rampReady6 = true;
    }
  }

  // Shutting on / off after ramping done
  if (light0 == false && rampReady0 == true) {
    faboPWM.set_channel_value(0, 0);
    delay(15);
  }
  if (light1 == false && rampReady1 == true) {
    faboPWM.set_channel_value(1, 0);
    delay(15);
  }
  if (light2 == false && rampReady2 == true) {
    faboPWM.set_channel_value(2, 0);
    delay(15);
  }
  if (light3 == false && rampReady3 == true) {
    faboPWM.set_channel_value(3, 0);
    delay(15);
  }
  if (light4 == false && rampReady4 == true) {
    faboPWM.set_channel_value(4, 0);
    delay(15);
  }
  if (light5 == false && rampReady5 == true) {
    faboPWM.set_channel_value(5, 0);
    delay(15);
  }
  if (light6 == false && rampReady6 == true) {
    faboPWM.set_channel_value(6, 0);
    delay(15);
  }

  if (light0 == true && rampReady0 == true && channelselect == 0) {
    pwmPCA = pwm0 * 16;
    faboPWM.set_channel_value(channelselect, pwmPCA);
    delay(15);
  }
  if (light1 == true && rampReady1 == true && channelselect == 1) {
    pwmPCA = pwm1 * 16;
    faboPWM.set_channel_value(channelselect, pwmPCA);
    delay(15);
  }
  if (light2 == true && rampReady2 == true && channelselect == 2) {
    pwmPCA = pwm2 * 16;
    faboPWM.set_channel_value(channelselect, pwmPCA);
    delay(15);
  }
  if (light3 == true && rampReady3 == true && channelselect == 3) {
    pwmPCA = pwm3 * 16;
    faboPWM.set_channel_value(channelselect, pwmPCA);
    delay(15);
  }
  if (light4 == true && rampReady4 == true && channelselect == 4) {
    pwmPCA = pwm4 * 16;
    faboPWM.set_channel_value(channelselect, pwmPCA);
    delay(15);
  }
  if (light5 == true && rampReady5 == true && channelselect == 5) {
    pwmPCA = pwm5 * 16;
    faboPWM.set_channel_value(channelselect, pwmPCA);
    delay(15);
  }
  if (light6 == true && rampReady6 == true && channelselect == 6) {
    pwmPCA = pwm6 * 16;
    faboPWM.set_channel_value(channelselect, pwmPCA);
    delay(15);
  }

  // short push
  if (pressed == 0 && timerCounter < 45 && timerCounter > 2 ) {
    if (channelselect == 0) {
      if (light0 == false) {
        if (pwm0 < 128) pwm0Direction = 0;
        light0 = true;
        rampReady0 = false;
      } else {
        pwm0Direction = 1;
        light0 = false;
        rampReady0 = false;
      }
    }
    if (channelselect == 1) {
      if (light1 == false) {
        if (pwm1 < 128) pwm1Direction = 0;
        light1 = true;
        rampReady1 = true;
      } else {
        pwm1Direction = 1;
        light1 = false;
        rampReady1 = false;
      }
    }
    if (channelselect == 2) {
      if (light2 == false) {
        if (pwm2 < 128) pwm2Direction = 0;
        light2 = true;
        rampReady2 = false;
      } else {
        pwm2Direction = 1;
        light2 = false;
        rampReady2 = false;
      }
    }
    if (channelselect == 3) {
      if (light3 == false) {
        if (pwm3 < 128) pwm3Direction = 0;
        light3 = true;
        rampReady3 = false;
      } else {
        pwm3Direction = 1;
        light3 = false;
        rampReady3 = false;
      }
    }
    if (channelselect == 4) {
      if (light4 == false) {
        if (pwm4 < 128) pwm4Direction = 0;
        light4 = true;
        rampReady4 = false;
      } else {
        pwm4Direction = 1;
        light4 = false;
        rampReady4 = false;
      }
    }
    if (channelselect == 5) {
      if (light5 == false) {
        if (pwm5 < 128) pwm5Direction = 0;
        light5 = true;
        rampReady5 = false;
      } else {
        pwm5Direction = 1;
        light5 = false;
        rampReady5 = false;
      }
    }
    if (channelselect == 6) {
      if (light6 == false) {
        if (pwm6 < 128) pwm6Direction = 0;
        light6 = true;
        rampReady6 = false;
      } else {
        pwm6Direction = 1;
        light6 = false;
        rampReady6 = false;
      }
    }
    if (channelselect == 7) {
      if (light0 == 1 || light1 == 1 || light2 == 1 || light3 == 1  || light4 == 1 || light5 == 1 || light6 == 1) {
        light0 = 0;
        light1 = 0;
        light2 = 0;
        light3 = 0;
        light4 = 0;
        light5 = 0;
        light6 = 0;
        faboPWM.set_channel_value(0, 0);
        faboPWM.set_channel_value(1, 0);
        faboPWM.set_channel_value(2, 0);
        faboPWM.set_channel_value(3, 0);
        faboPWM.set_channel_value(4, 0);
        faboPWM.set_channel_value(5, 0);
        faboPWM.set_channel_value(6, 0);
        Serial.println("all off");
      }
      else if (light0 == 0 || light1 == 0 || light2 == 0 || light3 == 0  || light4 == 0 || light5 == 0 || light6 == 0) {
        light0 = 1;
        light1 = 1;
        light2 = 1;
        light3 = 1;
        light4 = 1;
        light5 = 1;
        light6 = 1;

        for (int a = 0; a < pwm0; a = a + 2) {
          pwmPCA = a * 16;
          faboPWM.set_channel_value(0, pwmPCA);
        }
        for (int a = 0; a < pwm1; a = a + 2) {
          pwmPCA = a * 16;
          faboPWM.set_channel_value(1, pwmPCA);
        }
        for (int a = 0; a < pwm2; a = a + 2) {
          pwmPCA = a * 16;
          faboPWM.set_channel_value(2, pwmPCA);
        }
        for (int a = 0; a < pwm3; a = a + 2) {
          pwmPCA = a * 16;
          faboPWM.set_channel_value(3, pwmPCA);
        }
        for (int a = 0; a < pwm4; a = a + 2) {
          pwmPCA = a * 16;
          faboPWM.set_channel_value(4, pwmPCA);
        }
        for (int a = 0; a < pwm5; a = a + 2) {
          pwmPCA = a * 16;
          faboPWM.set_channel_value(5, pwmPCA);
        }
        for (int a = 0; a < pwm6; a = a + 2) {
          pwmPCA = a * 16;
          faboPWM.set_channel_value(6, pwmPCA);
        }

        //  faboPWM.set_channel_value(0, pwm0 * 16);
        //  faboPWM.set_channel_value(1, pwm1 * 16);
        //  faboPWM.set_channel_value(2, pwm2 * 16);
        //  faboPWM.set_channel_value(3, pwm3 * 16);
        //  faboPWM.set_channel_value(4, pwm4 * 16);
        //  faboPWM.set_channel_value(5, pwm5 * 16);
        //  faboPWM.set_channel_value(6, pwm6 * 16);
        Serial.println("all on");
      }
      delay(100);
    }

#if defined(DEBUG)
    Serial.println("SHORT PUSH");
    Serial.print("pwm0Direction: "); Serial.println(pwm0Direction);
    Serial.print("timerCounter: "); Serial.println(timerCounter);
    Serial.print("Light0: "); Serial.println(light0);
    Serial.print("Light1: "); Serial.println(light1);
    Serial.print("Light2: "); Serial.println(light2);
    Serial.print("Light3: "); Serial.println(light3);
    Serial.print("Light4: "); Serial.println(light4);
    Serial.print("Light5: "); Serial.println(light5);
    Serial.print("Light6: "); Serial.println(light6);
    Serial.print("PWM0:"); Serial.println(pwm0);
    Serial.print("PWM1:"); Serial.println(pwm1);
    Serial.print("PWM2:"); Serial.println(pwm2);
    Serial.print("PWM3:"); Serial.println(pwm3);
    Serial.print("PWM4:"); Serial.println(pwm4);
    Serial.print("PWM5:"); Serial.println(pwm5);
    Serial.print("PWM6:"); Serial.println(pwm6);
#endif

    timerCounter = 0;
  }

  // hold button start
  if (pressed == 1 && timerCounter > 45) {
    hold = true;
  } else {
    hold = false;
  }

  // hold button end
  if (pressed == 0 && timerCounter > 45) {
    timerCounter = 0;
    pwm0Direction = (pwm0 < 128) ? 0 : 1;
    pwm1Direction = (pwm1 < 128) ? 0 : 1;
    pwm2Direction = (pwm2 < 128) ? 0 : 1;
    pwm3Direction = (pwm3 < 128) ? 0 : 1;
    pwm4Direction = (pwm4 < 128) ? 0 : 1;
    pwm5Direction = (pwm5 < 128) ? 0 : 1;
    pwm6Direction = (pwm6 < 128) ? 0 : 1;

#if defined(DEBUG)
    Serial.println("HOLD END");
    Serial.print("pwm0: "); Serial.println(pwm0);
    Serial.print("pwm1: "); Serial.println(pwm1);
    Serial.print("pwm2: "); Serial.println(pwm3);
    Serial.print("pwm3: "); Serial.println(pwm3);
    Serial.print("pwm4: "); Serial.println(pwm4);
    Serial.print("pwm5: "); Serial.println(pwm5);
    Serial.print("pwm6: "); Serial.println(pwm6);
    Serial.print("pwm0Direction: "); Serial.println(pwm0Direction);
    Serial.print("pwm1Direction: "); Serial.println(pwm1Direction);
    Serial.print("pwm2Direction: "); Serial.println(pwm2Direction);
    Serial.print("pwm3Direction: "); Serial.println(pwm3Direction);
    Serial.print("pwm4Direction: "); Serial.println(pwm4Direction);
    Serial.print("pwm5Direction: "); Serial.println(pwm5Direction);
    Serial.print("pwm6Direction: "); Serial.println(pwm6Direction);
    Serial.print("Light0: "); Serial.println(light0);
    Serial.print("Light1: "); Serial.println(light1);
    Serial.print("Light2: "); Serial.println(light2);
    Serial.print("Light3: "); Serial.println(light3);
    Serial.print("Light4: "); Serial.println(light4);
    Serial.print("Light5: "); Serial.println(light5);
    Serial.print("Light6: "); Serial.println(light6);
    Serial.print("rampReady0: "); Serial.println(rampReady0);
    Serial.print("rampReady1: "); Serial.println(rampReady0);
    Serial.print("rampReady2: "); Serial.println(rampReady0);
    Serial.print("rampReady3: "); Serial.println(rampReady0);
    Serial.print("rampReady4: "); Serial.println(rampReady0);
    Serial.print("rampReady5: "); Serial.println(rampReady0);
    Serial.print("rampReady6: "); Serial.println(rampReady0);
#endif
  }
  pressed = 0;
}
