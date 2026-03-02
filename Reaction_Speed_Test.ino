//#define 
const int startLED = 12;
const int redLED = 7;
const int yellowLED = 4;
const int greenLED = 2;
const int button = A5;



void setup() {
  pinMode(startLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(button, INPUT_PULLUP);
  randomSeed(analogRead(A0));
}


bool gameIsPlaying = true;
void loop() {
  while(gameIsPlaying){

    int waitTime = random(4000) + 1000; // random number between 1000 and 5000
    delay(waitTime); // wait that many milliseconde

    digitalWrite(startLED, HIGH); //turn on start led
    unsigned long startTime = millis();

    while(digitalRead(button) == HIGH){ //the button is naturally high, this pauses the program 
    }                                   //untill the user hits the button

    unsigned long endTime = millis();
    unsigned long timeElapsed = endTime - startTime;//this records thier reaction time

    if(timeElapsed > 400){digitalWrite(redLED, HIGH);}
    else if(timeElapsed > 200){digitalWrite(yellowLED, HIGH);}
    else{digitalWrite(greenLED, HIGH);}


    delay(5000);
    gameIsPlaying = false;

    digitalWrite(startLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }
}
