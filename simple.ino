
int LED_GREEN = 4;  
int LED_RED = 2;
int LED_YELLOW = 3;

int SW_KEY = 16;
int SW_BUTT = 10;

int bs_key = 0;
int bs_butt = 0;

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  pinMode(SW_KEY, INPUT);
  pinMode(SW_BUTT, INPUT);
}

void loop() {
  bs_key = digitalRead(SW_KEY);
  bs_butt = digitalRead(SW_BUTT);

  if(bs_key == HIGH){
    digitalWrite(LED_GREEN, HIGH);

    if(bs_butt == HIGH){
      digitalWrite(LED_YELLOW, HIGH);
      delay(1000);
      digitalWrite(LED_RED, HIGH);
      delay(1000);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      delay(500);
    }
  }else{
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
  }
}
