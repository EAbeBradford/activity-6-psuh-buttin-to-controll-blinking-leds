#define RED_LED 12
#define YELLOW_LED 11
#define GREEN_LED 10
#define PUSH_PIN 2
boolean yellowStart = true;//should yellow be the next one that blinks

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //set up red led
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);

  //set up Yellow led
  pinMode(YELLOW_LED, OUTPUT);
  digitalWrite(YELLOW_LED, LOW);

   //set up green led
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, LOW);

  //set up push pin
  pinMode(PUSH_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //if pushed stop blinking lights
  //if not pushed 
    //red and green  power on, yellow off for 300ms
    //red and green  power off, yellow on for 300ms
  if(digitalRead(PUSH_PIN) == LOW){ //check if led is not pushed 
      if(yellowStart==true){
        //Red and green on
        digitalWrite(RED_LED, HIGH);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
        delay(300);
        yellowStart = false;
      }
  }

  if(digitalRead(PUSH_PIN) == LOW){ //check if led is not pushed 
      if(yellowStart == false){
        //yellow on
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
        delay(300);
        yellowStart = true;
      }
  } 

}
