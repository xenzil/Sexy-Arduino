void setup() {
 // initialize both serial ports:
 Serial1.begin(115200);
 Serial.begin(115200);
}

char letter = ' ';
char ack1 = '1';
char ack2 = '2';
char ack3 = '3';
int firstShake = 0;
int secondShake = 0;

void loop() {

  while(firstShake == 0){
  //Serial.println("shaking1");
    if(Serial1.available()>0){
      letter = Serial1.read();
      Serial.println("TRIGGERED");
      Serial.println(letter);
    }
    if(ack1 == letter){
      firstShake = 1;
    }
  }
  
  letter = ' ';

  while(secondShake == 0){
    Serial1.write(ack2);
    if(Serial1.available()>0){
      letter = Serial1.read();
    }
    if(letter = ack3){
      secondShake = 1;
    }
  }
  
  Serial.println("Handshake Complete");
  while(1);
}

