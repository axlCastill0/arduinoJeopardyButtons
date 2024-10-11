bool isQuestionState = false;
bool isAnswerState = false;
unsigned int firstPin = -1;
unsigned int answerTimeout = 7000;

unsigned int player1Pin = 2;
unsigned int player2Pin = 3;
unsigned int player3Pin = 4;
unsigned int player4Pin = 5;
unsigned int player5Pin = 6;
unsigned int player6Pin = 7;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(player1Pin, OUTPUT);
  pinMode(player2Pin, OUTPUT);
  pinMode(player3Pin, OUTPUT);
  pinMode(player4Pin, OUTPUT);
  pinMode(player5Pin, OUTPUT);
  pinMode(player6Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(String(digitalRead(A0)));
  if(digitalRead(A0) == 0) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}

void turnOnPlayerButtons() {

}
