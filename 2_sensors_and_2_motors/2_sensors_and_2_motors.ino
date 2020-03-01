const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 7;
const int echoPin2 = 8;
float duration1, distance1, duration2, distance2;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(2, OUTPUT);  
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(3, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  digitalWrite(2, LOW);       
  
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  
  Serial.print("Distance1: ");
  Serial.println(distance1);
    digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;
  

    if (distance1 < 20 && distance2 < 20){
 
      digitalWrite(2, HIGH); 
         digitalWrite(3, HIGH); 
      delay(500);
      digitalWrite(2, LOW);
       digitalWrite(3, LOW);
      
    }
    else if (distance2 < 20){
      
    digitalWrite(3, HIGH);
    delay(500);
   
    digitalWrite(3, LOW);  
    }
    else if (distance1 < 20){
    digitalWrite(2, HIGH);
    
    delay(500);
   
    digitalWrite(2, LOW);  

    }
    


  Serial.print("Distance2 ");
  Serial.println(distance2);

}
