const int motA_pin1=5;              
const int motA_pin2=4;
const int motA_EN=3; 



const int motD_pin1=2;             
const int motD_pin2=10;
const int motD_EN=9; 




char speed=250; //speed of dc motor pwm
int command=0;


void setup() {
  Serial.begin(9600);

pinMode (motA_pin1,OUTPUT);      
pinMode (motA_pin2,OUTPUT);
pinMode (motA_EN,OUTPUT);



pinMode (motD_pin1,OUTPUT);
pinMode (motD_pin2,OUTPUT);
pinMode (motD_EN,OUTPUT);


 
}

// function 
void FWD() {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
 analogWrite(motA_EN,speed); 
 


 digitalWrite(motD_pin1,LOW);
digitalWrite(motD_pin2,HIGH);
 analogWrite(motD_EN,speed); 
//--
 
Serial.print("fwd   ");
Serial.println(speed);
}

void LEFT() {
analogWrite(motA_EN,speed);
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW);

 

 digitalWrite(motD_pin1,LOW);
digitalWrite(motD_pin2,HIGH);
 analogWrite(motD_EN,speed); 
//--

Serial.println("left"); 
}
void RIGHT() {
analogWrite(motA_EN,speed);
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);


 digitalWrite(motD_pin1,HIGH);
digitalWrite(motD_pin2,LOW);
 analogWrite(motD_EN,speed); 

//--

Serial.println("RIGHT"); 
}
void REV() {
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW);
analogWrite(motA_EN,speed);



 digitalWrite(motD_pin1,HIGH);
digitalWrite(motD_pin2,LOW);
 analogWrite(motD_EN,speed); 
//--

Serial.println("rev");
}


void STOP(){
analogWrite(motA_EN,0);
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);

 digitalWrite(motD_pin1,LOW);
digitalWrite(motD_pin2,LOW);
 analogWrite(motD_EN,0); 
//--

Serial.println("stop"); 
}

void loop() {
  if (Serial.available()>0){
command=Serial.read();
if ( command==70)  
FWD();
else if ( command==76)
LEFT();
else if ( command==82)
RIGHT();
else if ( command==66)
REV();

else 
STOP();
  }

}   
