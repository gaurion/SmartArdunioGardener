#define m11 8
#define m12 9
#define m21 6
#define m22 7
#define trigPin 4
#define echoPin 3

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A0, INPUT);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);
  delay(5000);
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int moisture = digitalRead(A0);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  if (distance <= 20)
  {
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    digitalWrite(m21, LOW);
    digitalWrite(m22, LOW);
    Serial.print("Ultrasonic    ");
    Serial.print("Distance=");
    Serial.println(distance);
  }
  else
  {
    if (moisture == 0)
    {
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, LOW);
      Serial.println("Water");
    }
    else  if (moisture == 1)
    {
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      Serial.println("Dry");
    }
  }
}
