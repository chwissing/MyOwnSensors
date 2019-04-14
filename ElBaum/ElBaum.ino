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

#include <sensors/SensorBattery.h>
SensorBattery battery;

#include <sensors/SensorSignal.h>
SensorSignal signalrep;

#include <sensors/SensorDigitalOutput.h>
SensorDigitalOutput digiout(4); // Pin 4 steers LEDs


/***********************************
 * Main Sketch
 */

// before
void before() {
  /***********************************
   * Configure your sensors
   */
   battery.setReportIntervalMinutes(90);
   signalrep.setReportIntervalMinutes(90);
   //nodeManager.setSleepMinutes(1); // Set sleep to 60min, but actually should react on messages
   battery.setMaxVoltage(3.27);  // Experience!
   //digiout.setStatus(ON);
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
