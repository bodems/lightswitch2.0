#define MAXSTRING 20
char inString[MAXSTRING+1]; // Space for the string plus Nullbyte
char newString[MAXSTRING+1];
byte index = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  while (Serial.available() > 0 && index < MAXSTRING) {
    inString[index] = Serial.read();
    inString[index+1] = '\0';
    index++;
    delay(4);
  }
  
  if ( index != 0 ) {
    strcpy( newString, inString );
    if ( !strcmp(newString, "start") ) {
      Serial.write("Start empfangen\n");
      digitalWrite(13, HIGH);   // set the LED on
      index = 0;
    }
    
    else if ( !strcmp(newString, "stopp") ) {
      Serial.write("Stopp empfangen\n");
      digitalWrite(13, LOW);   // set the LED off
      index = 0;
    }
    
    else if ( !strcmp(newString, "light_on\n") )
    {
      digitalWrite(13, HIGH);
      index = 0;
    }
    
     else if ( !strcmp(newString, "light_off\n") )
     {
       digitalWrite(13, LOW);
       index = 0;
     }
     
    else
    {
     index = 0;
     Serial.write("Falsche Eingabe!\n");
     Serial.write(newString);
    }
  }
}
