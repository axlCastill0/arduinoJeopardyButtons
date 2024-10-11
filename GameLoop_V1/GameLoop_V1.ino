bool isQuestionState = false;
bool isAnswerState = false;
unsigned int firstPin = -1;
unsigned int answerTimeout = 7000;

unsigned int player1Led = 2;
unsigned int player2Led = 3;
unsigned int player3Led = 4;
unsigned int player4Led = 5;
unsigned int player5Led = 6;
unsigned int player6Led = 7;

unsigned int player1Btn = A0;
unsigned int player2Btn = A1;
unsigned int player3Btn = A2;
unsigned int player4Btn = A3;
unsigned int player5Btn = A4;
unsigned int player6Btn = A5;

unsigned int hostPin = 8;
unsigned int buzzerPin = 12;

void setup() {
  Serial.begin(9600);

  pinMode(player1Led, OUTPUT);
  pinMode(player2Led, OUTPUT);
  pinMode(player3Led, OUTPUT);
  pinMode(player4Led, OUTPUT);
  pinMode(player5Led, OUTPUT);
  pinMode(player6Led, OUTPUT);
  pinMode(hostPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if(isQuestionState) {
    if(!isAnswerState) {
      turnOffPlayerButtons();
    }
  } else {
    turnOnPlayerButtons();
  }

  if(digitalRead(hostPin) == 0 && !isQuestionState) {
    isQuestionState = true;
  } else {
    digitalWrite(buzzerPin, HIGH);
    isAnswerState = true;
    turnOnPlayerButtons();
  }

  if(isAnswerState) {
    if(firstPin == -1) {
      readPins()
    } else {
      Serial.print(String(firstPin));
      delay(2000);
    }
  }
}

void turnOnPlayerButtons() {
  digitalWrite(player1Led, HIGH);
  digitalWrite(player2Led, HIGH);
  digitalWrite(player3Led, HIGH);
  digitalWrite(player4Led, HIGH);
  digitalWrite(player5Led, HIGH);
  digitalWrite(player6Led, HIGH);
}

void turnOffPlayerButtons() {
  digitalWrite(player1Led, LOW);
  digitalWrite(player2Led, LOW);
  digitalWrite(player3Led, LOW);
  digitalWrite(player4Led, LOW);
  digitalWrite(player5Led, LOW);
  digitalWrite(player6Led, LOW);
}

void readPins() {
  if (firstPin == -1) {
    if (digitalRead(player1Btn) == HIGH) {
      firstPin = player1Led;
    } else if (digitalRead(player2Btn) == HIGH) {
      firstPin = player2Led;
    } else if (digitalRead(player3Btn) == HIGH) {
      firstPin = player3Led;
    } else if (digitalRead(player4Btn) == HIGH) {
      firstPin = player4Led;
    } else if (digitalRead(player5Btn) == HIGH) {
      firstPin = player5Led;
    } else if (digitalRead(player6Btn) == HIGH) {
      firstPin = player6Led;
    }
    
    if (firstPin != -1) {
      Serial.print("First signal received from pin: ");
      Serial.println(firstPin);
    }
}
