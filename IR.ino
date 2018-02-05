//IR Receiver.
//Variable decleration

byte input;                           //the input from the dig pins  
int degree[5] = {0,45,90,135,180};
int zero =0;       //to store how many 1 we are reading
int sum =0;       //sum for the sum of degeees.

void setup() {
  // put your setup code here, to run once:
  DDRB = 0x0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  input = PINB;       //read the inputs to the digital pins (8-13)
  //check the number of zeros.
 for (int i=0 ;i <5; i++){
  if ( 0 &bitRead(input,i))
  zero++;
 }
 if (zero == 0)                         //there is no signals.
  Serial.println("200");
  
 else if (zero == 1){                  // Only one IR reciever detects the signal.
    for (int i =0 ; i<5; i++){
      if (bitRead(input,i)&0)
          Serial.println(degree[i]);}
    }
 else if (zero == 2){                 // There is two IR receiver detects the signal.
  for (int i= 0; i<5; i++){
    if (bitRead(input,i)&0)
        sum+= degree[i];
    }
    Serial.println(sum/2);
 }
 
 else                                 
  Serial.println("300");

delay (100);
}
