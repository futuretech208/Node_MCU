/*Simple program for testing the relays using NodeMCU*/

void setup() 
{
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  digitalWrite(D8, HIGH);

}

void loop() {
  digitalWrite(D1, LOW);
  delay(500);
  digitalWrite(D1, HIGH);
  delay(500);
  digitalWrite(D2, LOW);
  delay(500);
  digitalWrite(D2, HIGH);
  delay(500);
  digitalWrite(D3, LOW);
  delay(500);
  digitalWrite(D3, HIGH);
  delay(500);
  digitalWrite(D4, LOW);
  delay(500);
  digitalWrite(D4, HIGH);
  delay(500);
  digitalWrite(D5, LOW);
  delay(500);
  digitalWrite(D5, HIGH);
  delay(500);
  digitalWrite(D6, LOW);
  delay(500);
  digitalWrite(D6, HIGH);
  delay(500);
  digitalWrite(D7, LOW);
  delay(500);
  digitalWrite(D7, HIGH);
  delay(500);
  digitalWrite(D8, LOW);
  delay(500);
  digitalWrite(D8, HIGH);
  delay(500);
}
