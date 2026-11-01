
const int BUT1 = D0;
const int BUT2 = D1;
const int BUT3 = D2;
const int LED1 = D3;
const int LED2 = D4;
const int LED3 = D5;

const int MAX_LEVEL = 50;
int sequence[MAX_LEVEL];
int level = 0;


void setAll(int state) {
  digitalWrite(LED1, state);
  digitalWrite(LED2, state);
  digitalWrite(LED3, state);
}

void waitForRelease(int pin) {
  while (digitalRead(pin) == LOW) { }
  delay(30);  
}


void setup() {
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}


void loop() {
  waitForLongPressToStart(); //basically waits for player to click the first button (long press) to start the game
  randomSeed(micros());  
  level = 0;

  while (true) {
    
    if (level >= MAX_LEVEL) {
      winSequence();  //if player reaches level 50 the win sequence plays
      delay(1000);
      continue;
    }

   //adds one more led light to memorize as level increases
    sequence[level] = random(1, 4);
    level++;

    delay(1000);

    
    for (int i = 0; i < level; i++) {
      playLED(sequence[i]);
      delay(300);
    }

    delay(500);

    
    bool failed = false;

    for (int i = 0; i < level; i++) {
      int playerChoice = waitForButtonPress();//stores wtv button was pressed by the player into this variable

      if (playerChoice == -99) {
        quitGameSequence();
        return;  // back to the start screen
      }
      //if it dont match the acc sequence its game over 
      if (playerChoice != sequence[i]) {
        gameOverSequence();  // sets level = 0 because they didnt match the seq
        failed = true;
        break;
      }
    }

    if (failed) {
      delay(1000);
      continue;  // new game begins right after u miss the sequence
    }

    delay(1000);
  }
}


void waitForLongPressToStart() {
  waitForRelease(BUT1);  
//shows game is ready to start
  for (int i = 0; i < 2; i++) {
    setAll(HIGH); delay(150);
    setAll(LOW);  delay(150);
  }

  while (true) {
    if (digitalRead(BUT1) == LOW) {
      unsigned long start = millis();
      while (digitalRead(BUT1) == LOW) {
        if (millis() - start >= 1000) { //checks if button 1 is pressed for >1 second go start
          digitalWrite(LED1, HIGH);
          delay(500);
          digitalWrite(LED1, LOW);
          waitForRelease(BUT1);
          delay(500);
          return; //goes into game part now
        }
      }
    }
  }
}


void playLED(int ledNum) {
  int pin = (ledNum == 1) ? LED1 : (ledNum == 2) ? LED2 : LED3; //if its 1 its LED1 if its 2 its LED2 and if its 3 its LED3
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
}//whicever leds chosen that one lights up


int waitForButtonPress() {
  while (true) {
    //basically if but 1 is pressed for >2 seconds itll quit the game (but1 is used for starting and quitting the game)
    if (digitalRead(BUT1) == LOW) {
      unsigned long pressTime = millis();
      while (digitalRead(BUT1) == LOW) {
        if (millis() - pressTime >= 2000) {
          waitForRelease(BUT1);
          return -99;
        }
      }
      
      digitalWrite(LED1, HIGH); delay(200); digitalWrite(LED1, LOW);
      waitForRelease(BUT1);
      return 1;
    }

    
    if (digitalRead(BUT2) == LOW) {
      digitalWrite(LED2, HIGH); delay(200); digitalWrite(LED2, LOW);
      waitForRelease(BUT2);
      return 2;
    }

    
    if (digitalRead(BUT3) == LOW) {
      digitalWrite(LED3, HIGH); delay(200); digitalWrite(LED3, LOW);
      waitForRelease(BUT3);
      return 3;
    }
  }
}

//all leds turn on then off and u go back to level 0 to show that u lost
void gameOverSequence() {
  for (int i = 0; i < 3; i++) {
    setAll(HIGH); delay(200);
    setAll(LOW);  delay(200);
  }
  level = 0;
}

//only led 2 and 3 turn on and off for distinction to show that u quit the game
void quitGameSequence() {
  digitalWrite(LED2, HIGH); digitalWrite(LED3, HIGH);
  delay(400);
  digitalWrite(LED2, LOW);  digitalWrite(LED3, LOW);
  level = 0;
}

// when player wins all leds light up
void winSequence() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED1, HIGH); delay(150);
    digitalWrite(LED2, HIGH); delay(150);
    digitalWrite(LED3, HIGH); delay(150);
    setAll(LOW);
    delay(150);
  }
  level = 0;
}