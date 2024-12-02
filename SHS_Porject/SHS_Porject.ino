#include <Servo.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>


//0x3F or 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);   //LCD Object

const int Button1 = 2;
const int Button2 = 3;
const int Button3 = 4;
const int buzzerPin = 5;

Servo myservo;  // create servo object to control a servo

int totalColumns = 16;
int totalRows = 2;

String staticMessage = "     HELLO";
String scrollingMessage = "Welcome to Medicine Dispenser";

void scrollMessage(int row, String message, int delayTime, int totalColumns) {
  for (int i=0; i < totalColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int position = 0; position < message.length(); position++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(position, position + totalColumns));
    delay(400);
  }
}

void setup()  {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);

  pinMode(buzzerPin, OUTPUT);

  myservo.attach(6);  // attaches the servo on pin 6 to the servo object

  lcd.backlight();
  // Print a welcome message to the LCD
  lcd.setCursor(0, 0);
  lcd.print(staticMessage);
  scrollMessage(1, scrollingMessage, 250, totalColumns);
}

void loop()  {
  myservo.write(0);   // Move to 0 degrees

  int But1 = digitalRead(Button1);
  int But2 = digitalRead(Button2);
  int But3 = digitalRead(Button3);
  

  if (But1 == LOW){ //button for 30 seconds

      lcd.setCursor(0, 0);
      lcd.print("Set Timer:");
      lcd.setCursor(0, 1);
      lcd.print("30 Seconds");

      digitalWrite(buzzerPin, HIGH);//1
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW); // Turn off the buzzer
      delay(300);
      digitalWrite(buzzerPin, HIGH);//2
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW);//2
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, HIGH);//2
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW);//2
      delay(1500); // Sound the buzzer for 1 second
      

      lcd.clear();

      delay(30000); // Wait for 30 seconds
      myservo.write(90);   // Move to 0 degrees

      digitalWrite(buzzerPin, HIGH);//1
      delay(3000); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW); // Turn off the buzzer
      delay(300);

      lcd.setCursor(0, 0);
      lcd.print("Timer Done");
      lcd.setCursor(0, 1);
      lcd.print("");
      delay(2500);

      lcd.clear();
  }

  else if (But2 == LOW){ // button for 5 Minutes

      lcd.setCursor(0, 0);
      lcd.print("Set Timer:");
      lcd.setCursor(0, 1);
      lcd.print("5 minutes");

      digitalWrite(buzzerPin, HIGH);//1
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW); // Turn off the buzzer
      delay(300);
      digitalWrite(buzzerPin, HIGH);//2
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW);//2
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, HIGH);//2
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW);//2
      delay(1500); // Sound the buzzer for 1 second

      lcd.clear();

      delay(300000); // Wait for 30 seconds
      myservo.write(90);   // Move to 0 degrees

      digitalWrite(buzzerPin, HIGH);//1
      delay(3000); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW); // Turn off the buzzer
      delay(300);

      lcd.setCursor(0, 0);
      lcd.print("Timer Done");
      lcd.setCursor(0, 1);
      lcd.print("");
      delay(2500);
      
      lcd.clear();    
  }

  else if (But3 == LOW){ // button for 1 hr

      lcd.setCursor(0, 0);
      lcd.print("Set Timer:");
      lcd.setCursor(0, 1);
      lcd.print("1 Hour");

      digitalWrite(buzzerPin, HIGH);//1
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW); // Turn off the buzzer
      delay(300);
      digitalWrite(buzzerPin, HIGH);//2
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW);//2
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, HIGH);//2
      delay(300); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW);//2
      delay(1500); // Sound the buzzer for 1 second

      delay(3600000); // Wait for 30 seconds
      myservo.write(90);   // Move to 0 degrees

      digitalWrite(buzzerPin, HIGH);//1
      delay(3000); // Sound the buzzer for 1 second
      digitalWrite(buzzerPin, LOW); // Turn off the buzzer
      delay(300);

      lcd.setCursor(0, 0);
      lcd.print("Timer Done");
      lcd.setCursor(0, 1);
      lcd.print("");
      delay(2500);

      lcd.clear();

  }

  else {
      digitalWrite(buzzerPin, LOW); // Turn off the buzzer

  }
}