#include <LiquidCrystal.h>
//LCD pinMode setup
const int rs = 12,  en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6,  d7);

//music tone setup for "SO" (G), "LA" (A), "TI" (B), "DO" (C)
int  abc[] = {3920, 4400, 4940, 5230};

//variables declaration
signed short  minutes, secondes;
char timeline[16];
char countf[16];
int buzzerpin =  7;
int rightButton = 8;
int leftButton = 9;
int selectButton = 10;
int  menu = 1;
int flag = 0;
int count = 0;
int mins;
int sec;
int total;

//-----------------------------------------  SETUP PROGRAM ---------------------------------------------------
void setup(){
  lcd.begin(16,2);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(leftButton,  INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(buzzerpin,  OUTPUT);

  lcd.setCursor(3,0);
  lcd.print("WELCOME TO");
  for(int  i = 0; i < 4; i++) //playing welcoming melody
  {
    mtone(buzzerpin, abc[i],  500); 
    delay(50);
    lcd.setCursor(4,1);
  lcd.print("POMODORO");
  }

  updateMenu();

}
//------------------------------------- PUSHBUTTON  INPUT DETECTION ---------------------------------------------
//flag 0 for "auto"  and "custom"  (general mode) menu interface
//flag 1 for "Yes" and "no"  (continue confirmation) menu interface
//flag 2 for custom option mode menu interface
//mtone()  function play a tone if sny switch was pressed
//Notice that there is a tone  different between "select button" and "left/right buttion"

void loop(){
  if(!digitalRead(leftButton)){
    mtone(buzzerpin, abc[0], 50); 
    menu++;
    if (flag == 0){
      mtone(buzzerpin, abc[0], 50); 
      updateMenu();
    }
    else if (flag == 1){
      mtone(buzzerpin, abc[0], 50); 
      updateMenu2();
    }
    else if (flag == 2){
      mtone(buzzerpin, abc[0], 50); 
      updateMenu3();
    }
    delay(100);
    while(!digitalRead(leftButton));
  }
  if(!digitalRead(rightButton)){
   
    menu--;
    if (flag == 0){
      mtone(buzzerpin, abc[0], 100);  // abc[i] tone sound for 0.5 second
      updateMenu();
    }
    else  if (flag == 1){
      mtone(buzzerpin, abc[0], 100); // abc[i] tone sound for  0.5 second
      updateMenu2();
    }
    else if (flag == 2){
      mtone(buzzerpin,  abc[0], 100); // abc[i] tone sound for 0.5 second
      updateMenu3();
    }
    delay(100);
    while(!digitalRead(rightButton)); 
  }
  if(!digitalRead(selectButton)){
    if (flag == 0){
    mtone(buzzerpin, abc[3], 50); // abc[i] tone sound for  0.5 second
    executeAction();
    }
    else if (flag == 1){
     mtone(buzzerpin,  abc[3], 50); // abc[i] tone sound for 0.5 second
    updateMenu2();
    confirm();
    }
    else if (flag == 2){
     mtone(buzzerpin, abc[3], 50); // abc[i]  tone sound for 0.5 second
    action2();
    }
    delay(100);
    while(!digitalRead(selectButton));
  }
  
}
//--------------------------------------------- General Mode Menu  Display -----------------------------------------------
void updateMenu(){
  switch(menu){
    case 0: //auxiliary condition
    menu = 1;
    break;
    
    case 1: //Select option 1 - AUTO interface
    lcd.clear();
    lcd.print("----  OPTION ----");
    lcd.setCursor(1,1);
    lcd.print("~AUTO");
    lcd.setCursor(9,1);
    lcd.print("CUSTOM");
    break;

    case 2: //Select option 2- CUSTOM  interface
    lcd.clear();
    lcd.print("---- OPTION ----");
    lcd.setCursor(2,1);
    lcd.print("AUTO");
    lcd.setCursor(8,1);
    lcd.print("~CUSTOM");
    break;

    case 3:
    menu = 2;
    break;
  }
}
//-------------------------------------------  Function Execution for auto and custom ----------------------------------
void  executeAction(){
    switch(menu){
      case 1:
      flag = 0;
      delay(100);
      action1();
      break;

      case 2:
      menu = 1;
      flag  = 2;
      updateMenu3();
      break;
    }
}

void action1(){
  lcd.clear();
  lcd.print("---- ALERT! ----");
  buzz();
  for (int  i=5;i>=0;i--){
    lcd.setCursor(1,1);
    lcd.print("GET READY IN ");
    lcd.setCursor(14,1);
    lcd.print(i);
    delay(1000);
  }

  timedisplay();
  delay(2000);
}

//-----------------------------------  custom mode menu display ----------------------------------==
void updateMenu3(){
  switch(menu){
    case 0: //auxiliary condition
    menu = 1;
    break;
    
    case 1: //Select option 1 - AUTO interface
    delay(100);
    lcd.clear();
    lcd.print("---- OPTION ----");
    lcd.setCursor(1,1);
    lcd.print("~1HR");
    lcd.setCursor(7,1);
    lcd.print("2HR");
    lcd.setCursor(12,1);
    lcd.print("3HR");
    break;

    case 2: //Select option 2- CUSTOM  interface
    delay(100);
    lcd.clear();
    lcd.print("---- OPTION  ----");
    lcd.setCursor(2,1);
    lcd.print("1HR");
    lcd.setCursor(6,1);
    lcd.print("~2HR");
    lcd.setCursor(12,1);
    lcd.print("3HR");
    break;

    case 3:
    delay(100);
    lcd.clear();
    lcd.print("----  OPTION ----");
    lcd.setCursor(2,1);
    lcd.print("1HR");
    lcd.setCursor(7,1);
    lcd.print("2HR");
    lcd.setCursor(11,1);
    lcd.print("~3HR");
    break;

    case 4: //Select option 1 - AUTO interface
    delay(100);
    lcd.clear();
    lcd.print("---- OPTION ----");
    lcd.setCursor(1,1);
    lcd.print("~4HR");
    lcd.setCursor(7,1);
    lcd.print("5HR");
    lcd.setCursor(12,1);
    lcd.print("6HR");
    break;

    case  5: //Select option 2- CUSTOM interface
    delay(100);
    lcd.clear();
    lcd.print("---- OPTION ----");
    lcd.setCursor(2,1);
    lcd.print("4HR");
    lcd.setCursor(6,1);
    lcd.print("~5HR");
    lcd.setCursor(12,1);
    lcd.print("6HR");
    break;

    case 6:
    delay(100);
    lcd.clear();
    lcd.print("---- OPTION ----");
    lcd.setCursor(2,1);
    lcd.print("4HR");
    lcd.setCursor(7,1);
    lcd.print("5HR");
    lcd.setCursor(11,1);
    lcd.print("~6HR");
    break;

    case  7: //Select option 1 - AUTO interface
    delay(100);
    lcd.clear();
    lcd.print("---- OPTION ----");
    lcd.setCursor(1,1);
    lcd.print("~7HR");
    lcd.setCursor(7,1);
    lcd.print("8HR");
    lcd.setCursor(12,1);
    lcd.print("BCK");
    break;

    case 8: //Select option 2- CUSTOM  interface
    delay(100);
    lcd.clear();
    lcd.print("---- OPTION  ----");
    lcd.setCursor(2,1);
    lcd.print("7HR");
    lcd.setCursor(6,1);
    lcd.print("~8HR");
    lcd.setCursor(12,1);
    lcd.print("BCK");
    break;

    case 9:
    delay(100);
    lcd.clear();
    lcd.print("----  OPTION ----");
    lcd.setCursor(2,1);
    lcd.print("7HR");
    lcd.setCursor(7,1);
    lcd.print("8HR");
    lcd.setCursor(11,1);
    lcd.print("~BCK");
    break;

    case 10:
    menu = 9;
    break;
  }
}

//--------------------------  Function execution for each custom mode option -----------------------------------------
void  action2(){                     
    switch(menu){
      case 0:
      menu  = 1;
      break;
      
      case 1:
      lcd.clear();
      flag  = 2;
      for (int i = 0; i < 2; i++){
      action1();
      }
      lcd.clear();
      lcd.print("SESSION");
      
      lcd.setCursor(0,1);
      lcd.print("ENDED");
      for (int i = 0; i <3; i++){
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        delay(100);
      }
      delay(2000);
      updateMenu3();
      flag = 2;
      count  = 0;
      break;

      case 2:
      lcd.clear();
      flag =  2;
      for (int i = 0; i < 4; i++){
      action1();
      }
      lcd.clear();
      lcd.print("SESSION");
      lcd.setCursor(0,1);
      lcd.print("ENDED");
      for (int i = 0; i <3; i++){
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        delay(100);
      }
      delay(1000);
      updateMenu3();
      flag = 2;
      count  = 0;
      break;

      case 3:
      lcd.clear();
      flag =  2;
      for (int i = 0; i < 6; i++){
      action1();
      }
      lcd.clear();
      lcd.print("SESSION");
      lcd.setCursor(0,1);
      lcd.print("ENDED");
      for (int i = 0; i <3; i++){
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        delay(100);
      }
      delay(1000);
      updateMenu3();
      flag = 2;
      count  = 0;
      break;

      case 4:
      lcd.clear();
      flag =  2;
      for (int i = 0; i < 8; i++){
      action1();
      }
      lcd.clear();
      lcd.print("SESSION");
      lcd.setCursor(0,1);
      lcd.print("ENDED");
      for (int i = 0; i <3; i++){
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        delay(100);
      }
      delay(1000);
      updateMenu3();
      flag = 2;
      count  = 0;
      break;

      case 5:
      lcd.clear();
      flag =  2;
      for (int i = 0; i < 10; i++){
      action1();
      }
      lcd.clear();
      lcd.print("SESSION");
      lcd.setCursor(0,1);
      lcd.print("ENDED");
      for (int i = 0; i <3; i++){
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        delay(100);
      }
      delay(1000);
      updateMenu3();
      flag = 2;
      count  = 0;
      break;

      case 6:
      lcd.clear();
      flag =  2;
      for (int i = 0; i < 7; i++){
      action1();
      }
      lcd.clear();
      lcd.print("SESSION");
      lcd.setCursor(0,1);
      lcd.print("ENDED");
      for (int i = 0; i <3; i++){
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        delay(100);
      }
      delay(1000);
      updateMenu3();
      flag = 2;
      count  = 0;
      break;

      case 7:
      lcd.clear();
      flag =  2;
      for (int i = 0; i < 8; i++){
      action1();
      }
      lcd.clear();
      lcd.print("SESSION");
      lcd.setCursor(0,1);
      lcd.print("ENDED");
      for (int i = 0; i <3; i++){
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        delay(100);
      }
      delay(1000);
      updateMenu3();
      flag = 2;
      count  = 0;
      break;

      case 8:
      lcd.clear();
      flag =  2;
      for (int i = 0; i < 9; i++){
      action1();
      }
      lcd.clear();
      lcd.print("SESSION");
      lcd.setCursor(0,1);
      lcd.print("ENDED");
      for (int i = 0; i <3; i++){
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        delay(100);
      }
      delay(1000);
      updateMenu3();
      flag = 2;
      count  = 0;
      break;

      case 9:
      menu = 1;
      flag = 0;
      updateMenu();
      
      break;

      case 10:
      menu  = 9;
      break;
  }
  
}

//---------------------- 30 minutes  pomodoro session program ---------------------------------------
void timedisplay(){
  minutes = 25;
  secondes = 0;
 
  lcd.clear();
  lcd.print("--- FOCUSING  ---");
  
  while (minutes != 0 or secondes != 0){
    if(secondes ==  0){
      lcd.setCursor(0,1);
      sprintf(timeline,"    %0.2d    %0.2d  ", minutes, secondes);
      lcd.print(timeline);
      delay(300);
      lcd.setCursor(7,1);
      lcd.print(":");
      lcd.setCursor(8,1);
      lcd.print(":");
      lcd.setCursor(7,1);
      lcd.print("");
      lcd.setCursor(8,1);
      lcd.print("");
      delay(700);
      secondes  = 59;
      minutes --;
    }
    else{
      lcd.setCursor(0,1);
      sprintf(timeline,"    %0.2d    %0.2d  ", minutes, secondes);
      lcd.print(timeline);
      delay(300);
      lcd.setCursor(7,1);
      lcd.print(":");
      lcd.setCursor(8,1);
      lcd.print(":");
      lcd.setCursor(7,1);
      lcd.print("");
      lcd.setCursor(8,1);
      lcd.print("");
      delay(700);
      secondes  --;
    }
  }
  lcd.setCursor(0,1);
  sprintf(timeline,"    %0.2d ::  %0.2d  ", minutes, secondes);
  lcd.print(timeline);
  delay(1000);
  lcd.clear();
  lcd.print("-- COMPLETED! --");
  buzz();
  lcd.setCursor(3,1);
  lcd.print("REST  TIME");
  delay(2000);

  minutes = 5;
  secondes = 0;
  
  lcd.clear();
  lcd.print("----- REST -----");
  while (minutes != 0 or secondes != 0){
    if(secondes == 0){
      lcd.setCursor(0,1);
      sprintf(timeline,"    %0.2d    %0.2d  ", minutes, secondes);
      lcd.print(timeline);
      delay(300);
      lcd.setCursor(7,1);
      lcd.print(":");
      lcd.setCursor(8,1);
      lcd.print(":");
      lcd.setCursor(7,1);
      lcd.print("");
      lcd.setCursor(8,1);
      lcd.print("");
      delay(700);
      secondes  = 59;
      minutes --;
    }
    else{
      lcd.setCursor(0,1);
      sprintf(timeline,"    %0.2d    %0.2d  ", minutes, secondes);
      lcd.print(timeline);
      delay(300);
      lcd.setCursor(7,1);
      lcd.print(":");
      lcd.setCursor(8,1);
      lcd.print(":");
      lcd.setCursor(7,1);
      lcd.print("");
      lcd.setCursor(8,1);
      lcd.print("");
      delay(700);
      secondes  --;
    }
  }
  lcd.setCursor(0,1);
  sprintf(timeline,"    %0.2d ::  %0.2d  ", minutes, secondes);
  lcd.print(timeline);
  delay(1000);
  
  count++;
  total = count * 30;
      if (total >= 60){
        mins =  total /60;
        sec = total%60;
      }
      else{
        mins  = 0;
        sec = total;
      }
   lcd.clear();
      lcd.print("--  CHECKPOINT --");
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        delay(100);
      lcd.setCursor(0,1);
      sprintf(countf, "COUNT:%0.2d   %0.2d:%0.2d", count, mins, sec);
      lcd.print(countf);
      delay(1000);
  if (flag == 0){
  updateMenu2();
  flag = 1;
  }
  }

//---------------------------- confirmation menu display -----------------------------------
void  updateMenu2(){

  switch(menu){
    case 0: //auxiliary condition
    menu  = 1;
    break;
    
    case 1: //Select option 1 - YES interface
    lcd.clear();
    lcd.print("-- CONTINUE ? --");
    lcd.setCursor(2,1);
    lcd.print("~YES");
    lcd.setCursor(11,1);
    lcd.print("NO");
    break;

    case 2: //Select option 2- NO interface
    lcd.clear();
    lcd.print("-- CONTINUE ? --");
    lcd.setCursor(3,1);
    lcd.print("YES");
    lcd.setCursor(10,1);
    lcd.print("~NO");
    break;

    case  3:
    menu = 2;
    break;
  }
}

//-------------------- confirmation  to continue execution ---------------------------------------
void confirm(){
     switch(menu){
      case 1:
      delay(100);
      flag = 0;
      action1();
      break;

      case 2:
      delay(100);
      flag  = 0;
      menu = 1;
      total = count * 30;
      if (total >= 60){
        mins = total /60;
        sec = total%60;
      }
      else{
        mins = 0;
        sec = total;
      }
      lcd.clear();
      lcd.print("----  SUMMARY ----");
      lcd.setCursor(0,1);
      sprintf(countf, "COUNT:%0.2d   %0.2d:%0.2d", count, mins, sec);
      lcd.print(countf);
      delay(2000);
      count = 0;

      
      updateMenu();
      break;
     }
}

//  ------------------------ buzzer execution -------------------------------
void  buzz(){
  for (int i = 0; i <3; i++){
        digitalWrite(buzzerpin, HIGH);
        delay(50);
        digitalWrite(buzzerpin, LOW);
        delay(50);
      }
}

//------------------------- welcoming message execution ---------------------
void  mtone(int dx, int hz, unsigned long tm)
{
  unsigned long t = millis();
  unsigned long ns = (long)500000 / hz;
  
  // Repeats for tm milliseconds.
  // Sounds for tm milliseconds
  while(millis() - t < tm)
  {
    digitalWrite(dx,  HIGH);
    delayMicroseconds(ns);
    digitalWrite(dx, LOW);
    delayMicroseconds(ns);
  }
}
