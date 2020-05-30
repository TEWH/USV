const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 11;
const int echoPin2= 12;
float duration1, distance1, duration2, distance2;

void setup() {
  Serial.begin(38400);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  
  if ((int)distance1%2 == 0){
    distance1 = distance1 + 1;
  }
  
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;
  if ((int)distance2%2 == 1){
    distance2 = distance2 + 1;
  }
  if(Serial.availableForWrite() && distance1 < 250 || distance2 < 250) {
    //Serial.write(L);
    Serial.write((int)distance1);
    //Serial.write(R);
    Serial.write((int)distance2);
  }
  else if(!Serial.availableForWrite()) {
    Serial.write(111);
    
  }
}
