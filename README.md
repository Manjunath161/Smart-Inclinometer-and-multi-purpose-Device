# Smart-Inclinometer-and-multi-purpose-Device

#INTRODUCTION:

An inclinometer or clinometer is an instrument used for measuring angles of slope, elevation, or depression of an object with respect to gravity's direction.

Clinometers measure both inclines and declines using three different units of measure: degrees, percentage points, and topo.

The Inclinometer makes use of the microcontroller ARDUINO board and MPU-6050 Chip. The 12C-transport is utilized by the sensor that can be interfaced with the Arduino. The MPU-6050 isn't so exorbitant as it in cooperates accelerometer and a gyro.

#Hardware Components 

Arduino Nano:

The Arduino Nano is small Arduino board based on ATmega328P or ATmega628 Microcontroller .

The Arduino Nano is organized using the Arduino IDE which can run on various Platforms.

Drawback: The DC power jack is absent in Nano. Thus, we cannot use a battery to apply any external power supply.
![image](https://user-images.githubusercontent.com/95703728/182553649-01419d78-6228-4ed4-bc3b-053637e08878.png)

#MPU6050:

![image](https://user-images.githubusercontent.com/95703728/182553849-85f7dbf2-363a-4d62-9a2b-54282b5a7c5b.png)

The MPU6050 module is a Micro Electro-Mechanical Systems (MEMS) which consists of a 3-axis Accelerometer and 3-axis Gyroscope inside it. This helps us to measure acceleration, velocity, orientation, displacement and many other motion related parameter of a system or object.

Measuring Rotation:

The MPU6050 can measure angular rotation using its on-chip gyroscope with four programmable full  scale ranges of ±250°/s, ±500°/s, ±1000°/s and ±2000°/s.

![image](https://user-images.githubusercontent.com/95703728/182554075-a1cf6052-2786-4280-840d-60c846f8fcb5.png)

The MPU6050 has another three 16-bit analog-to-digital converters that simultaneously samples 3 axes of rotation (around X, Y and Z axis). The sampling rate can be adjusted from 3.9 to 8000 samples per second.

Measuring Acceleration:

The MPU6050 can measure acceleration using its on-chip accelerometer with four programmable full scale ranges of ±2g, ±4g, ±8g and ±16g.

![image](https://user-images.githubusercontent.com/95703728/182554225-5714fa59-a97d-40e0-9723-c11a64b21ff0.png)

The MPU6050 has three 16-bit analog-to-digital converters that simultaneously sample the 3 axis of movement (along X, Y and Z axis).

#SSD1306 OLED Display:

It’s a Monocolor 0.96 inch Organic Light Emitting display(OLED) with 128x32 pixels as shown in the following figure.

![image](https://user-images.githubusercontent.com/95703728/182554538-1aa0287f-c6c9-4414-9d59-3fa398f12619.png)

#Coding:


Firstly, we will include the required libraries in the code and define the required functions.


Secondly, we will create setup function to initialize the MPU6050 sensor and SSD1306 OLED screen.


Thirdly, we will create loop function that will fetch the readings of gyro and accelerometer in  x, y, z directions and it will convert into Roll, Pitch, Yaw and Motion in 3D and same will be displayed on screen.


After verifying the code we upload it into Arduino Nano board.

#Connections :

After uploading the code , we make the following connections

![image](https://user-images.githubusercontent.com/95703728/182554951-7aa7359e-bd5f-40c1-9a2f-7fb5ddb3999b.png)











