#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;
////////////////////
#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); 

/////////////////
void setup() 
{
  Serial.begin(115200);
  ///////////////////
  u8g2.begin(); 
  //////////////////
  Serial.println(F("Initialize MPU6050"));

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println(F("Could not find a valid MPU6050 sensor, check wiring!"));
    delay(500);
  }
 
}

void loop()
{
  // Read normalized values 
  Vector normAccel = mpu.readNormalizeAccel();
  
  // Calculate Pitch & Roll
  int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
  int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;
  
  
  u8g2.clearBuffer();
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_pxplusibmvga9_tf);
    u8g2.setCursor(0, 12);
    u8g2.print(F("x="));
    u8g2.print(roll);
    u8g2.print(char(176));
    
    u8g2.setCursor(0, 26);
    u8g2.print(F("y="));
    u8g2.print(pitch);
    u8g2.print(char(176));

    u8g2.drawVLine(64, 4, 25);

    u8g2.setCursor(66, 12);
        
    u8g2.drawRFrame(2,47,122,12,6);
    u8g2.drawFilledEllipse( map(pitch, -100, 100, 0, 122), 52, 7, 5, U8G2_DRAW_ALL);
    
    if (pitch==0){
       
       u8g2.setFont(u8g2_font_pxplusibmvga9_tf);
       u8g2.setCursor(59,63);
       u8g2.print("flat");
       
   }
  } 
  while ( u8g2.nextPage() );
 }
 //Sketch uses 16322 bytes (53%) of program storage space. Maximum is 30720 bytes.
//Global variables use 1830 bytes (89%) of dynamic memory, leaving 218 bytes for local variables. Maximum is 2048 bytes.
//Low memory available, stability problems may occur.
