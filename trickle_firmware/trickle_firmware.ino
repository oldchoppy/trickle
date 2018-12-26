/*Copyright (C) 2018 David Stanger

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/.  
#define moisture_setpoint_pin A0 
#define moisture_sensor_input_pin A5 
#define moisture_sensor_power_pin 2 
#define led_pin 3 
#define pump_pin 4 
#define water_level_pin 9 

#define time_delay 500 //time to delay in milliseconds
#define time_pump 2000 //amount of time to pump water

int moisture_setpoint; //moisture setpoint from the potentiometer
int moisture_sensor; //reading from the moisture sensor
boolean water_level; //reading from the water level sensor in true or false format

void setup() {
  // put your setup code here, to run once:
  //DEFINE PIN MODES FOR EACH PIN USED
pinMode(moisture_setpoint_pin,INPUT);
pinMode(moisture_sensor_input_pin,INPUT);
pinMode(moisture_sensor_power_pin,OUTPUT);
pinMode(led_pin,OUTPUT);
pinMode(pump_pin,OUTPUT);
pinMode(water_level_pin,INPUT_PULLUP);
  //SET ALL OUTPUT PINS TO LOW
digitalWrite(moisture_sensor_power_pin,LOW);
digitalWrite(led_pin,LOW);
digitalWrite(pump_pin,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
delay(time_delay);

//READ MOISTURE SETPOINT, SAVE THE SETTING
moisture_setpoint=analogRead(moisture_setpoint_pin);
//READ MOISTURE SENSOR INPUT
moisture_sensor=analogRead(moisture_sensor_input_pin);
//READ WATER LEVEL SENSOR
water_level=digitalRead(water_level_pin);
//COMPARE THE READINGS AND BEGIN TO PUMP IF REQUIREMENTS ARE MET
if(moisture_setpoint>moisture_sensor&&water_level){ //IF THE MEASUREMENT IS DRYER THAN THE SETPOINT AND THERE IS WATER IN THE TANK
  digitalWrite(pump_pin,HIGH);//BEGIN TO PUMP
  delay(time_pump);//WAIT FOR time_pump
  digitalWrite(pump_pin,LOW);//TURN OFF PUMP
}
//TURN ON THE LED IF THE WATER IS EMPTY
if(water_level!=true){
  digitalWrite(led_pin,HIGH);
}
}
