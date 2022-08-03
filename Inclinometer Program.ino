#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050.h>
MPU6050 mpu;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Timers
unsigned long timer = 0;
float timeStep = 0.01;

// Pitch, Roll and Yaw values
float pitch = 0;
float roll = 0;
float yaw = 0;

float x=0;
float y=0;
float z=0;

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

Serial.println(F("Initialize MPU6050"));

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println(F("Could not find a valid MPU6050 sensor, check wiring!"));
    delay(500);
  }
 // Calibrate gyroscope. The calibration must be at rest.
  // If you don't want calibrate, comment this line.
  mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);

   
}

void loop() {
//  // Read normalized values 
//  Vector normAccel = mpu.readNormalizeAccel();
//  
//  // Calculate Pitch & Roll
//  int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
//  int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;
 timer = millis();

  // Read normalized values
  Vector norm = mpu.readNormalizeGyro();

  // Calculate Pitch, Roll and Yaw
  pitch = pitch + norm.YAxis * timeStep;
  roll = roll + norm.XAxis * timeStep;
  yaw = yaw + norm.ZAxis * timeStep;

  // Output raw
  Serial.print(" Pitch = ");
  Serial.print(pitch);
  Serial.print(" Roll = ");
  Serial.print(roll);  
  Serial.print(" Yaw = ");
  Serial.println(yaw);

  // Wait to full timeStep period
  delay((timeStep*1000) - (millis() - timer));

  display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,2);
    display.print(F("R="));
    display.print(roll);
    display.print(char(50));
    display.display();

    display.setCursor(0, 12);
    display.print(F("P="));
    display.print(pitch);
    display.print(char(50));
    display.display();

    display.setCursor(68,2);
    display.print(F("Y="));
    display.print(yaw);
    display.print(char(50));
    display.display();

     //Claculating Motion
  Vector normAccel=mpu.readNormalizeAccel();
  float  x=normAccel.XAxis;
  float y=normAccel.YAxis;
  float z=normAccel.ZAxis;

   // Output raw
  Serial.print(F(" X = "));
  Serial.print(x);
  Serial.print(F(" Y = "));
  Serial.print(y);  
  Serial.print(F(" Z = "));
  Serial.println(z);

   display.setCursor(0,21);
   display.print(F("x= "));
   display.print(x);
   display.display();

   display.setCursor(55,21);
   display.print(F(" y= "));
   display.print(y);  
   display.display();

//   display.setCursor(90,21);
//   display.print(F(" z= "));
//   display.println(z);
//   display.display();

    float temp = mpu.readTemperature();

    Serial.print(" T=");
    Serial.print(temp);
    Serial.println(" *C");
    display.setCursor(55,12);
    display.print("Temp=");
    display.print(temp);
    display.println("C");
    display.display();
    delay(500);
    

//   //display.drawFastHLine(0,21,128,WHITE);
//   display.setCursor(66, 15);
//   display.drawRect(0,21,128,5,WHITE);
//   display.display();
//   delay(500);
//  
//   display.fillCircle( map(yaw, -100, 100, 0, 122),22, 2,WHITE);
//   delay(1000);
//    
    if (pitch==0 & roll==0 & yaw==0)
    {
     display.setTextSize(.1);
    display.setTextColor(WHITE);
    display.setCursor(45,2);
    display.print(F("flat")); 
    display.display();
   // delay(1000);
    }

}
