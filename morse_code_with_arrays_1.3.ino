const int buttonPin = 2;
int x = 0;
const int dot = 1;
const int dash = 2;
//int a = 12000; set for letter "a"
int Position1 = 0;
int Position2 = 0;
int Position3 = 0;
int Position4 = 0;
int Position5 = 0;
int allPositions[5] = {
  Position1, Position2, Position3, Position4, Position5
};
int buttonState = 0;     // current state of the button
int lastButtonState = 0; // previous state of the button
int startPressed = 0;    // the time button was pressed
int endPressed = 0;      // the time button was released
int timeHold = 0;        // the time button is hold
int timeReleased = 0;    // the time button is released
char words[10];
char* dotsandDashes[5] = {};


char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};
char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....",
                   "--...", "---..", "----."
                  };

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  // initialize serial communication:
  Serial.begin(9600);
}
 int a = Position1 && Position2 && Position3 && Position4 && Position5;
void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  if (x < 5) {
    // button state changed
    if (buttonState != lastButtonState) {
      // the button was just pressed
      if (buttonState == LOW) {
        startPressed = millis();
        timeReleased = startPressed - endPressed;


        if (timeReleased >= 600) {
          Serial.print("^");
          if (Position1 == 1)
          {
            Serial.print("a");
            //
            switch(Position1, Position2, Position3, Position4, Position5){
              case 12000: Serial.print("a");
              break;
              
            }
            
            /* allPositions[0]={0};
             allPositions[1]={0};
             allPositions[2]={0};
             allPositions[3]={0};
             allPositions[4]={0};
             x=0;*/
          }

        }

        if (timeReleased >= 1000) {
          Serial.println(" ");
          x = 0;
        }

        // the button was just released
      } else {
        endPressed = millis();
        timeHold = endPressed - startPressed;

        if (timeHold <= 250 && timeHold > 40) {
          Serial.print(".");
          allPositions[x] = 1;
          x++;
          
        }


        if (timeHold >= 251) {
          Serial.print("-");
          allPositions[x] = 2;
          x++;
        }
      }Serial.print(Position1);
      Serial.print(Position2);
      Serial.print(Position3);
      Serial.print(Position4);
      Serial.print(Position5);


    }



  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState ;

}

