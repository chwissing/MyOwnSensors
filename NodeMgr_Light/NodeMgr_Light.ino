/*
NodeManager is intended to take care on your behalf of all those common tasks a MySensors node has to accomplish, speeding up the development cycle of your projects.
NodeManager includes the following main components:
- Sleep manager: allows managing automatically the complexity behind battery-powered sensors spending most of their time sleeping
- Power manager: allows powering on your sensors only while the node is awake
- Battery manager: provides common functionalities to read and report the battery level
- Remote configuration: allows configuring remotely the node without the need to have physical access to it
- Built-in personalities: for the most common sensors, provide embedded code so to allow their configuration with a single line 
Documentation available on: https://github.com/mysensors/NodeManager
*/

 
// load user settings
#include "config.h"
// include supporting libraries
#ifdef MY_GATEWAY_ESP8266
  #include <ESP8266WiFi.h>
#endif
// load MySensors library
#include <MySensors.h>
// load NodeManager library
#include "NodeManager.h"

// create a NodeManager instance
NodeManager nodeManager;

// before
void before() {
  // setup the serial port baud rate
  Serial.begin(MY_BAUD_RATE);  

  nodeManager.setBatteryReportMinutes(90);
  nodeManager.setBatteryMax(3.27); /* Experience - Minimum go with default of 2.7 */
  
  nodeManager.setSignalReportMinutes(10);
  nodeManager.setPowerPins(3, 4, 1000); //GND,Vcc,WaitTime_ms
  /*
   * Register below your sensors
  */
  nodeManager.setSleepMinutes(10);
  nodeManager.setReportIntervalMinutes(10);
  int i_light = nodeManager.registerSensor(SENSOR_BH1750); //Pins are implicit 
  SensorBH1750* lightSensor = (SensorBH1750*)nodeManager.getSensor(i_light);
  lightSensor->setMode(0x20); //BH1750_ONE_TIME_HIGH_RES_MODE 
  //lightSensor->setSamples(3);
  //lightSensor->setSamplesInterval(500);

  // DHT21 connected to digital pin 3
  nodeManager.registerSensor(SENSOR_DHT22,5); //Will actually register two sensors, temp & hum
  int i_sensor;
  int i_temp;
  int i_hum;
  for(i_sensor=0;i_sensor<255;i_sensor++){
    Sensor* this_sensor = nodeManager.getSensor(i_sensor);
    if (this_sensor->getPresentation() == S_TEMP) i_temp=i_sensor;
    if (this_sensor->getPresentation() == S_HUM) i_hum=i_sensor;
  }
  Sensor* tempSensor = nodeManager.getSensor(i_temp);
  Sensor* humSensor = nodeManager.getSensor(i_hum);
  tempSensor->setFloatPrecision(1);
  humSensor->setFloatPrecision(1);
  /*
   * Register above your sensors
  */
  nodeManager.setSignalCommand(SR_UPLINK_QUALITY);
  nodeManager.before();
}

// presentation
void presentation() {
  // call NodeManager presentation routine
  nodeManager.presentation();
}

// setup
void setup() {
  // call NodeManager setup routine
  nodeManager.setup();
}

// loop
void loop() {
  // call NodeManager loop routine
  nodeManager.loop();
}

// receive
void receive(const MyMessage &message) {
  // call NodeManager receive routine
  nodeManager.receive(message);
}

// receiveTime
void receiveTime(unsigned long ts) {
  // call NodeManager receiveTime routine
  nodeManager.receiveTime(ts);
}
