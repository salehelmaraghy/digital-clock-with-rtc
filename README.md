# digital-clock-with-rtc

this simple project is to implement a digital clock using timers and display it on  7-segments and save the time to RTC and modify 

the time using buttons. 

#Devices:
Micro-controller:ATmega32.

.external peripherals:

Real time clock RTC "DS1307": to store the time.

7-segment: to display the time.

Buttons:for user interface.

.Internal peripherals:

I2C:to communicate with the RTC.

timer:to get the time every 30 seconds from the RTC and compare it with the.

#Pin configuration:

7-segment : PORT B0 B1 B2 B3 for the data and PORT C2 C3 C4 C5 for enabling the 7-segments.

RTC		  : Port C0 C1 for I2C clk and data.

Led       : Port D4 to blink each second.

Buttons	  :	Port D2 D3 for user interface.

#Steps:

first take the folder "RTC_INITAL_VALUE" add it to a separate project and add the initial time to it.

then create a new project and copy the folders "MCAL-HAL-Service_layer-Application_layer" to it.

#Application:

1- The micro-controller will get the time from RTC. "that you have added to the "RTC_INITAL_VALUE" project.

2- if you want to change the Minutes or hours,use the buttons and the time will be changed also in the RTC.

3- If the power is unplugged from the micro-controller it's no problem because the time is saved to the RTC.
