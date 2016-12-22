#include <Keyboard.h>
#include <elapsedMillis.h>
elapsedMillis timeElapsed;


int LED_GREEN = 4;  
int LED_RED = 2;
int LED_YELLOW = 3;

int SW_KEY = 16;
int SW_BUTT = 10;

//See codes from: https://www.arduino.cc/en/Reference/KeyboardModifiers
char pressThis = KEY_F11;

int bs_key = 0;
int bs_butt = 0;
int counter = 0;

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  pinMode(SW_KEY, INPUT);
  pinMode(SW_BUTT, INPUT);

  //Keyboard.begin();
  //Serial.begin(9600); //For debug only

  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  delay(1000);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
}

void loop() {
  bs_key = digitalRead(SW_KEY);
  bs_butt = digitalRead(SW_BUTT);

  if(bs_key == HIGH){
    digitalWrite(LED_GREEN, HIGH);

    if(bs_butt == HIGH){
      //Serial.println(timeElapsed);
      
      if(timeElapsed > 500){
        digitalWrite(LED_YELLOW, HIGH);
      }
      
      if(timeElapsed > 1000){
        digitalWrite(LED_RED, HIGH);
        //Keyboard.print("boom"); //For debug
        Keyboard.press(pressThis);
        Keyboard.release(pressThis);
        
        delay(2000);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_GREEN, LOW);
        delay(2000);
        timeElapsed = 0;
      } 
    }else{
      timeElapsed = 0;
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
    }
    
  }else{
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
  }
}
