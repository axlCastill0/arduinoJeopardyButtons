bool isQuestionState = false;
bool isAnswerState = false;
unsigned int firstPin = -1;
unsigned int answerTimeout = 7000;
unsigned int time;

unsigned int player1Pwr = 2;
unsigned int player2Pwr = 3;
unsigned int player3Pwr = 4;
unsigned int player4Pwr = 5;
unsigned int player5Pwr = 6;
unsigned int player6Pwr = 7;

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

  time = millis();

  pinMode(player1Pwr, OUTPUT);
  pinMode(player2Pwr, OUTPUT);
  pinMode(player3Pwr, OUTPUT);
  pinMode(player4Pwr, OUTPUT);
  pinMode(player5Pwr, OUTPUT);
  pinMode(player6Pwr, OUTPUT);

  pinMode(player1Btn, INPUT_PULLUP);
  pinMode(player2Btn, INPUT_PULLUP);
  pinMode(player3Btn, INPUT_PULLUP);
  pinMode(player4Btn, INPUT_PULLUP);
  pinMode(player5Btn, INPUT_PULLUP);
  pinMode(player6Btn, INPUT_PULLUP);

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
      isAnswerState = false;
      isQuestionState = false;
      firstPin = -1;
    }
  }
}

void turnOnPlayerButtons() {
  digitalWrite(player1Pwr, HIGH);
  digitalWrite(player2Pwr, HIGH);
  digitalWrite(player3Pwr, HIGH);
  digitalWrite(player4Pwr, HIGH);
  digitalWrite(player5Pwr, HIGH);
  digitalWrite(player6Pwr, HIGH);
}

void turnOffPlayerButtons() {
  digitalWrite(player1Pwr, LOW);
  digitalWrite(player2Pwr, LOW);
  digitalWrite(player3Pwr, LOW);
  digitalWrite(player4Pwr, LOW);
  digitalWrite(player5Pwr, LOW);
  digitalWrite(player6Pwr, LOW);
}

void readPins() {
  if (firstPin == -1) {
    if (digitalRead(player1Btn) == HIGH) {
      firstPin = player1Pwr;
    } else if (digitalRead(player2Btn) == HIGH) {
      firstPin = player2Pwr;
    } else if (digitalRead(player3Btn) == HIGH) {
      firstPin = player3Pwr;
    } else if (digitalRead(player4Btn) == HIGH) {
      firstPin = player4Pwr;
    } else if (digitalRead(player5Btn) == HIGH) {
      firstPin = player5Pwr;
    } else if (digitalRead(player6Btn) == HIGH) {
      firstPin = player6Pwr;
    }
    
    if (firstPin != -1) {
      Serial.print("First signal received from pin: ");
      Serial.println(firstPin);
    }
}
