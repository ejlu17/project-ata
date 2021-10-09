
//Team Names: Rhys Colman, Riley Hubscher, Erica Lu, Sydney Pyles
//Class Section: Section 22 Team 5
//Team Name: ATA (Autonomous Testing Agent)
//__________________________________________________________________

#include <LiquidCrystal.h>
#include <Servo.h>

//LCD Display; The display in connected to pins 8-13
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
//Switch; The switch is connected to pin2
int switchPin = 2;
//Buzzer; The buzzer is connected to pin 4
const int buzzerPin = 4;
//Servo; The servo motor is defined here
Servo myservo;
int servoPosition;
//Temperature; setting variables to 0
float voltage = 0;
float degreesF = 0;
float degreesC = 0;
//__________________________________________________________________

void setup() {

  pinMode(switchPin, INPUT_PULLUP);

  //LCD Display
  lcd.begin(16, 2); //The LCD Display has 16 characters per line, and 2 lines
  lcd.clear(); //Clears the LCD Display of any previous writing

  //Buzzer; The buzzer is an output and does not take input
  pinMode(buzzerPin, OUTPUT);

  //Servo; The servo is connected to pin 5
  myservo.attach(5);
}
//__________________________________________________________________

void loop() {

  myservo.write(0);
  turnOn();

  if (digitalRead(switchPin) == LOW) {


    takeTemperature(); //Calls the takeTemperature function
    temperature(); //Calls the temerpature function

    if (degreesF >= 100.4) {
      //Checks if the temeprature is higher than 100.4 degrees F
      cannotBeTested(); //Calls the cannotBeTested function if the temeprature is higher than 100.4 degrees F
     buzzer(); //Calls the buzzer function

    }


    else {
    
      canBeTested(); //Calls the canBeTested function
      buzzer(); //Calls the buzzer function
      openDoor(); //Calls the openDoor function
      beginTest(); //Calls the beginTest function
      buzzer(); //Calls the buzzer function
      swabbingRight(); //Calls the swabbingRight function
      countDown(); //Calls the countDown function
      buzzer(); //Calls the buzzer function
      swabbingLeft(); //Calls the swabbingLeft function
      countDown(); //Calls the countingDown function
      buzzer(); //Calls the buzzer function
      dirtySwab(); //Calls the dirtySwab function
      thankYou(); //Calls the thankYou function
    }
  }




  else {
    //If the switch is off than the LCD screen will not do anything
    lcd.clear();
  }





}
//__________________________________________________________________

void turnOn() {
  //Defines the turnOn function
  lcd.clear(); //Clears the LCD screen of previous writing
  lcd.setCursor(0, 0); //Sets the cursor to the first character on the first line
  lcd.print("Flip switch left"); //Prints the instructions for turning the robot on
  lcd.setCursor(0, 1); //Sets the cursor to the first character on the second line
  lcd.print("then right"); //Prints out the instructions for turning the robot on
  delay(2000); //Pauses for 2 seconds for people to read
}
//__________________________________________________________________

void takeTemperature() {
  //Defines the takeTemeprature function
  lcd.clear(); //Clears the LCD
  lcd.setCursor(0, 0); //Sets the cursor to (0,0)
  lcd.print("Place finger on"); //Prints the instructions for taking temperatures
  lcd.setCursor(0, 1); //Sets the cursor (0,1)
  lcd.print("temp. sensor"); //Prints the last line of taking temp.
  delay(1500); //Pauses for 1.5 seconds
}
//__________________________________________________________________

void temperature() {
  //Defines temperature Function

  voltage = analogRead(A0) * 0.004882813; //Converts analog readings into voltages
  degreesC = (voltage - 0.5) * 100.0; //Converts voltage to degress Celsius
  degreesF = degreesC * (9.0 / 5.0) + 32.0; //Converts degrees Celsius to degrees Fahrenheit

  lcd.clear(); //Clears the LCD
  lcd.setCursor(0, 0); //Sets the curcor to (0,0)
  lcd.print("Degrees F: "); //Prints the Degrees F
  lcd.print(degreesF); //Prints your actual temeprature
  delay(3000); //Pauses for 3 seconds
}
//__________________________________________________________________

void cannotBeTested() {
  //Defines cannotBeTested Function
  lcd.clear(); //Clears the LCD
  lcd.setCursor(0, 0); //Sets the cursor to (0,0)
  lcd.print("Your temp. is too hot"); //Prints out their temp is too hot
  lcd.setCursor(0, 1); //Sets the cursor to (0,1)
  lcd.print("Please leave"); //Prints the last line of temp is too hot
  //__________________________________________________________________

  void canBeTested() {
    // Defines canBeTested function
    lcd.clear(); //Clears the LCD
    lcd.setCursor(0, 0); //Sets the cursor to (0,0)
    lcd.print("Please take the"); //Prints instruction for person to take the swab
    lcd.setCursor(0, 1); //Sets cursor to (0,1)
    lcd.print("cotton swab"); //Prints the last line of person to take swab
  }
  //__________________________________________________________________

  void buzzer() {
    //Defines the buzzer function
    tone(buzzerPin, 272); //Calls what tone the buzzer should play
    delay(1000); //Lets it play for 1 second
    noTone(buzzerPin); //Shuts the buzzer off
  }
  //__________________________________________________________________

  void openDoor() {
    //Defines openDoor function
    myservo.write(90); //Tells the servo how many degrees to change to
    delay(5000); //Waits 5 seconds for person to take swab
    myservo.write(-90); //Tells the servo how many degrees to change to
  }
  //__________________________________________________________________

  void beginTest() {
    //Defines beginTest function
    lcd.clear(); //Clears the LCD
    lcd.setCursor(0, 0); //Sets cursor to (0,0)
    lcd.print("We will begin"); //Prints out the instructions
    lcd.setCursor(0, 1); //Sets cursor to (0,1)
    lcd.print("the test now"); //Prints the second line of instructions
    delay(3500); //Pauses for 3.5 seconds

    lcd.clear(); //Clears the LCD
    lcd.setCursor(0, 0); //Sets cursor to (0,0)
    lcd.print("Lower your mask"); //Prints for user to lower the mask
    delay(1000); //Pauses for 1 second
  }
  //__________________________________________________________________

  void swabbingRight() {
    //Defines swabbingRight function
    lcd.clear(); //Clears LCD
    lcd.setCursor(0, 0); //Sets crusor to (0,0)
    lcd.print("Swab your right"); //Prints user should start swabbing
    lcd.setCursor(0, 1); //Sets crusor to (0,1)
    lcd.print("nostril"); //Prints the last line of instructions
    delay(2000); //Pauses for 2 seconds
  }
  //__________________________________________________________________

  void swabbingLeft() {
    //Defines swabbingLeft function
    lcd.clear(); //Clears LCD
    lcd.setCursor(0, 0); //Sets cursor to (0,0)
    lcd.print("Swab your left"); //Prints user should start swabbing
    lcd.setCursor(0, 1); //Sets cursor to (0,1)
    lcd.print("nostril"); //Prints the last line of instructions
    delay(2000); //Pauses for 2 seconds
  }
  //__________________________________________________________________

  void dirtySwab() {
    //Defines dirtySwab function
    lcd.clear(); //Clears the LCD
    lcd.setCursor(0, 0); //Sets cursor to (0,0)
    lcd.print("Drop swab in"); //Prints instructions for dirty swab
    lcd.setCursor(0, 1); //Sets sursor to (0,1)
    lcd.print("back chamber"); //Prints last line of isntructions
    delay(4000); //Pauses for 4 seconds
  }
  //__________________________________________________________________
  void thankYou() {
    //Defines the thankYou function

  
  lcd.clear(); //Clears the LCD
  lcd.setCursor(0, 0); //Sets cursor to (0,0)
  lcd.print("Thank you! Have"); //Prints thank you
  lcd.setCursor(0, 1); //Sets cursor to (0,1)
  lcd.print("a good day!"); //Prints last line of thank you
  delay(10000); //Pauses for 10 seconds
}
//__________________________________________________________________

void countDown() {
  //Defines the countDown function
  lcd.clear(); //Clears the LCD
  lcd.setCursor(8, 0); //Sets the cursor to (8,0)
  lcd.print("14"); //Prints 14
  delay(1000); //Pauses for 1 second --> repeats until 15 seconds have passed
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("13");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("12");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("11");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("10");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("9");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("8");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("7");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("6");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("5");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("4");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("3");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("2");
  delay(1000);
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("1");
}
//__________________________________________________________________
