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

// import NodeManager library (a nodeManager object will be then made available)
#include <MySensors_NodeManager.h>

/***********************************
 * Add your sensors
 */

PowerManager power(3,4,500);  // (GND,Vcc,WaitTime_ms)

#include <sensors/SensorBattery.h>
SensorBattery battery;

#include <sensors/SensorSignal.h>
SensorSignal signalrep;

#include <sensors/SensorDHT22.h>
SensorDHT22 dht22(5); // Pin 5 is readout

#include <sensors/SensorBH1750.h>
SensorBH1750 bh1750; // Pins are impicit


/***********************************
 * Main Sketch
 */

// before
void before() {
  /***********************************
   * Configure your sensors
   */
   // report measures of every attached sensors every 10 minutes
   nodeManager.setReportIntervalMinutes(10);
   // set the node to sleep in 10 minutes cycles
   nodeManager.setSleepMinutes(10);
   // report battery and signal level every 90 minutes
   battery.setReportIntervalMinutes(90);
   signalrep.setReportIntervalMinutes(90);
   // power all the nodes through dedicated pins
   nodeManager.setPowerManager(power);

   battery.setMaxVoltage(3.27);  // Experience!
   bh1750.setMode(BH1750::ONE_TIME_HIGH_RES_MODE);  // HexPattern: 0x20 = BH1750_ONE_TIME_HIGH_RES_MODE
   // call NodeManager before routine
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

#if NODEMANAGER_RECEIVE == ON
// receive
void receive(const MyMessage &message) {
  // call NodeManager receive routine
  nodeManager.receive(message);
}
#endif

#if NODEMANAGER_TIME == ON
// receiveTime
void receiveTime(unsigned long ts) {
  // call NodeManager receiveTime routine
  nodeManager.receiveTime(ts);
}
#endif
