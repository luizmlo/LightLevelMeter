//----------------------------------
// Code by: Luiz Melo, 08/02/2017;
//----------------------------------

// Pin setup;
int sensorPin = A0;
int verdePin = 8;
int azulPin = 9;
int vermelhoPin = 10;
int buzzerPin = 11;

// Global Variables Setup;
int valorLuz;


void setup() {
  
  // Pin Mode Setup;
  pinMode(sensorPin, INPUT);
  pinMode(verdePin, OUTPUT);
  pinMode(azulPin, OUTPUT);
  pinMode(vermelhoPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Serial monitor setup;
  Serial.begin(9600);
}

void loop(){

  // valorLuz == Analog output from photocell;
  valorLuz = analogRead(sensorPin);
    
  Serial.println(valorLuz);

  if(valorLuz >= 3){
    digitalWrite(verdePin, HIGH);
    if(valorLuz >= 12){
      digitalWrite(azulPin, HIGH);
      if(valorLuz >= 100){
        digitalWrite(vermelhoPin, HIGH);
        if(valorLuz >= 300){
          tone(buzzerPin, 3000);

        }
      }        
    }
  }

  delay(5);

  // Shuts down everything for fast response;
  digitalWrite(verdePin, LOW);
  digitalWrite(azulPin, LOW);
  digitalWrite(vermelhoPin, LOW);
  noTone(buzzerPin);
  
  delay(5);
}



 