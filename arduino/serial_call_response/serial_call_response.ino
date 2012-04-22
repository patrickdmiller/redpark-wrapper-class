/*  patrick miller
    example of sending commands to arduino and processing them
*/

unsigned char inChar;
unsigned char commandChar;
char command[50];
int commandLength = 0;

void setup(){
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("ready");
}

void loop(){
  if(Serial.available() > 0){
    readChar();
  }
}



void readChar(){
  commandChar = Serial.read();
  

  if( commandChar != '\n' && commandChar!='\r'){
    if(commandLength < 49){
      command[commandLength++]=commandChar;
    }
  }
  else{

    if(commandLength>0){
      command[commandLength]='\0';
      Serial.print("arduino received >");
      Serial.println(command);
     
      commandLength = 0;
      memset(command,0b00000000, sizeof(command)); 
    

    }
  }

}




