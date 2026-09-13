// name all 4 led pins output in a list [0:3]                 
int ledpins[4] = {2, 3, 4, 5};//{blue, yellow, red, green}

// name all 4 botton pins (input out?) in a list [0:3]
int btnpins[4] = {7, 8, 9, 10};//{blue, yellow, red, green}

// name buzzer pin output
int buzzer = 6; 

long timeb = 0;
long timea = 0;
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

  // make an empty list {} name the_sequince and putting vars
  const int max_num_rounds = 6;
  int the_sequence[max_num_rounds] = {9,9,9,9,9,9};
  int user_sequence[max_num_rounds] = {9,9,9,9,9,9};
  bool user_error = false;

  // main simon says loop for 10 times
  for (int i = 0; i < max_num_rounds;i++){

    // make a random number from 0 to 3 and add to the sequence
    the_sequence[i] = random(4);

    
    // light the leds in the sequince using list the_sequence
    for (int j = 0; j < (i+1);j++){
      digitalWrite(ledpins[the_sequence[j]], HIGH);
      delay(300);
      digitalWrite(buzzer, 2); 
      delay(300);
      digitalWrite(buzzer, LOW);
      delay(500);
      digitalWrite(ledpins[the_sequence[j]], LOW);
      delay(100);
    }

    // wait for user to add the same sequince as the_sequence
    int btns_on[4] = {false, false, false, false};
    int user_sequence_number = 0;
    while ( !are_list_equal(the_sequence, user_sequence, max_num_rounds) || user_error){
      // if btn change from off to on add it
      for(int k = 0;k < 4;k++){
        if(digitalRead(btnpins[k]) == LOW && !btns_on[k]){
          btns_on[k] = true;
          user_sequence[user_sequence_number] = btnpins[k] - 7;

          Serial.println(user_sequence[user_sequence_number]);
          Serial.println(the_sequence[user_sequence_number]);
          
          user_sequence_number++;
          
          Serial.println(btnpins[k]);
          Serial.println(user_sequence_number);
          Serial.println("on");

          digitalWrite(buzzer, HIGH);
          delay(200);
          digitalWrite(buzzer, LOW);
          
          if(!are_list_equal(user_sequence, the_sequence, user_sequence_number)){
            lost();
          }
        }
        else if(btns_on[k] && digitalRead(btnpins[k]) == HIGH){
          Serial.println("off");
          btns_on[k] = false;
        } 
      }
      
    }
    Serial.println("good job");
  }
  win();

}

void loop() {

}
// function when player loses
void lost(){
  digitalWrite(buzzer, HIGH);
  delay(3000);
  digitalWrite(buzzer, LOW);

  while (true){

  }
}

void win(){
  while(true){
    for(int i = 0; i < 4;i++){
      digitalWrite(ledpins[i], HIGH);
      Serial.println(ledpins[i]);
      delay(200);
      digitalWrite(ledpins[i], LOW);
    }
  }
}

// Helper function to compare arrays element-by-element
bool are_list_equal(int l1[], int l2[], int size){
  for(int i = 0; i < size;i++){
    if(l1[i] != l2[i]){
      return false;
    }
  }
  return true;
}
