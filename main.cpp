#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
void setup() {
  lcd.begin(16,2);
  pinMode(A0, INPUT);//temp
  pinMode(A1, INPUT);//pot
  pinMode(4, OUTPUT);//led r
  pinMode(2, OUTPUT);//led y
  pinMode(A2, INPUT);//LDR
  pinMode(3,OUTPUT);//led g
}

void loop() {
  int t=analogRead(A0);
  t=t/16;
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURE:");
  lcd.print(t);
  delay(1000);
  if (t>32)
  {
    digitalWrite(4,1);
  }else{
    digitalWrite(4,0);
  }

  int l=analogRead(A1);
  lcd.setCursor(0,1);
  lcd.print("POTENIOMETER:");
  lcd.print(l);
  delay(1000);
  
  if(l<100)
  {
    digitalWrite(2,1);

  }else{
    digitalWrite(2,0);

  }
  {
    lcd.clear();
    int ldr=analogRead(A2);
    lcd.setCursor(0,0);
    lcd.print("HUMAN PRESENCE");
    lcd.setCursor(0,1);
    lcd.print("FOUND:" );
    lcd.print(ldr);
    delay(1000);
    if(ldr>300)
    {
      digitalWrite(3,1);
    }else{
      digitalWrite(3,0);
    }

  }
  


  



}
