
// name all 4 led pins output in a list [0:3]                 
int ledpins[4] = {2, 3, 4, 5};//{blue, yellow, red, green}

// name all 4 botton pins (input out?) in a list [0:3]
int btnpins[4] = {7, 8, 9, 10};//{blue, yellow, red, green}

// name buzzer pin output
int buzzer = 6; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //add pinmode to each pin
  for(int i = 0; i < 4; i++){
    pinMode(ledpins[i], OUTPUT);
  }
  
  for(int i = 0; i < 4; i++){
    pinMode(btnpins[i], );
  }

  // make an empty list {} name the_sequince
}

void loop() {
  // put your main code here, to run repeatedly:

  // make a random number from 0 to 3
  // add this number to the_sequince

  // light the leds in the sequince using list the_sequince
  // wait for user to add the same sequince as the_sequince

  // if user sucssed go back to line 15
  // elif user failed or made an error, delete the_sequince and go back to line 15 with an empty sequince

}
