
const int trigPin1 = 5;
const int echoPin1= 6;
float duration1, distance1;

void setup() {

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  //pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  //digitalWrite(6, LOW); //0
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  //if (distance < 20){
    //Serial.print("Hello World!");
    /*digitalWrite(6, HIGH); //153
    //delayMicroseconds(500);
    //delayMicroseconds(4000);
  }*/
  Serial.print("Distance1: ");
  Serial.println(distance1);
  delay(100);
  
}
