
// name all 4 led pins output in a list [0:3]                 
int ledpins[4] = {2, 3, 4, 5};//{blue, yellow, red, green}

// name all 4 botton pins (input out?) in a list [0:3]
int btnpins[4] = {7, 8, 9, 10};//{blue, yellow, red, green}

// name buzzer pin output
int buzzer = 6; 

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(A0));
  Serial.begin(9600);
  //add pinmode for leds
  for(int i = 0; i < 4; i++){
    pinMode(ledpins[i], OUTPUT);
  }
  //add pinmode for btns
  for(int i = 0; i < 4; i++){
    pinMode(btnpins[i], INPUT_PULLUP);
  }
  pinMode(buzzer, OUTPUT);

  // make an empty list {} name the_sequince
  const int max_num_rounds = 10;

  // putting imprtant vars
  int the_sequence[max_num_rounds] = {};
  int user_sequence[max_num_rounds] = {};
  bool no_user_error = true;

  // main simon says loop for 10 times
  for (int i = 0; i < 10;i++){
    // put your main code here, to run repeatedly:

    // make a random number from 0 to 3
    // add this number to the_sequence
    the_sequence[i] = random(4);

    // light the leds in the sequince using list the_sequince
    for (int j = 0; j < (i+1);j++){
      digitalWrite(ledpins[the_sequence[j]], HIGH);
      delay(1000);
      digitalWrite(ledpins[the_sequence[j]], LOW);
      delay(1000);
    }

    // wait for user to add the same sequince as the_sequence
    int btns_on[4] = {false, false, false, false};
    int user_sequence_number = 0;
    while (user_sequence != the_sequence || no_user_error){
      // if btn change from off to on add it
      if(digitalRead(btnpins[0]) == LOW && !btns_on[0]){
        btns_on[0] = true;
        user_sequence[user_sequence_number] = 0;
        user_sequence_number++;
        Serial.println(btns_on[0]);
        Serial.println(btnpins[0]);
        Serial.println(user_sequence_number);
        Serial.println(user_sequence[0]);
        Serial.println("on");
      }
      if(btns_on[0] && digitalRead(btnpins[0]) == HIGH){
        Serial.println("off");
        btns_on[0] = false;
      } 
      
    }

   
    // elif user failed or made an error, delete the_sequince and go back to line 15 with an empty sequince

    
  }
}

void loop() {
  
  // if (round_num > max_num_rounds){
  //   exit(0);
  // }
}
