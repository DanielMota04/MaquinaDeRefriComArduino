#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int buttonPin1 = 1;
const int buttonPin2 = 2;
const int rele1Pin = 6;
const int rele2Pin = 5; 
int button1State = 0;
int button2State = 0; 
LiquidCrystal_I2C lcd(0x27,16,2); 

byte customChar[8] = { 
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};



void setup()
{
 pinMode(rele1Pin, OUTPUT); 
 pinMode(rele2Pin, OUTPUT); 
 pinMode(buttonPin1, INPUT);
 pinMode(buttonPin2, INPUT);
 digitalWrite(rele1Pin, HIGH);
 digitalWrite(rele2Pin, HIGH);

 lcd.init();
 lcd.createChar(1, customChar); 
 lcd.backlight(); 
 lcd.setCursor(4,0);
 lcd.print("Ligando");
 lcd.setCursor(4,1); 
 lcd.print("Maquina");
 delay(3000); 
 lcd.clear(); 
 
}


void loop()
{
  button1State = digitalRead(buttonPin1); 
  button2State = digitalRead(buttonPin2); 

  lcd.setCursor(3,0); 
  lcd.print("Escolha um");
  lcd.setCursor(2,1); 
  lcd.print("Refrigerante"); 

  if(button1State == LOW) 
  {
    ligaDesligaComTimer(rele1Pin);
  }

  if(button2State == LOW) 
  {
    ligaDesligaComTimer(rele2Pin);
  }
}

void ligaDesligaComTimer(int relePin)
{
    lcd.clear(); 
    digitalWrite(relePin, LOW);
    lcd.print("Refri ligado"); 
    contador(); 
    lcd.clear();
    lcd.print("finalizando!");
    delay(1500); 
    digitalWrite(relePin, HIGH);
    lcd.clear(); 
}

void ligaDesliga(int relePin)
{
    digitalWrite(relePin, LOW);
    digitalWrite(relePin, HIGH);
}

void contador()
{
  for (int i = 0; i < 16; i++){
   lcd.setCursor(i, 1); 
   lcd.write(1); 
   delay(125); 
  }
}
