#ifndef config_h
#define config_h

/**********************************
 * Sketch configuration
 */

#define SKETCH_NAME "NodeMgr_LightTempHum"
#define SKETCH_VERSION "1.30"
// Upgrade to NodeManger 1.8 in 1.30
/**********************************
 * MySensors node configuration
 */

// General settings
#define MY_BAUD_RATE 115200
#define MY_DEBUG
//#define MY_REGISTRATION_FEATURE 0
//#define MY_NODE_ID 100
//#define MY_SMART_SLEEP_WAIT_DURATION_MS 500

// NRF24 radio settings
#define MY_RADIO_RF24
//#define MY_RF24_ENABLE_ENCRYPTION
//#define MY_RF24_CHANNEL 76
//#define MY_RF24_PA_LEVEL RF24_PA_HIGH
//#define MY_DEBUG_VERBOSE_RF24
//#define MY_RF24_DATARATE RF24_250KBPS

// RFM69 radio settings
//#define MY_RADIO_RFM69
//#define MY_RFM69_FREQUENCY RF69_868MHZ
//#define MY_RFM69_FREQUENCY RFM69_868MHZ
//#define MY_IS_RFM69HW
//#define MY_RFM69_NEW_DRIVER
//#define MY_RFM69_ENABLE_ENCRYPTION
//#define MY_RFM69_NETWORKID 100
//#define MY_DEBUG_VERBOSE_RFM69
//#define MY_RF69_IRQ_PIN D1
//#define MY_RF69_IRQ_NUM MY_RF69_IRQ_PIN
//#define MY_RF69_SPI_CS D2
//#define MY_RFM69_ATC_MODE_DISABLED

// RS485 serial transport settings
//#define MY_RS485
//#define MY_RS485_BAUD_RATE 9600
//#define MY_RS485_DE_PIN 2
//#define MY_RS485_MAX_MESSAGE_LENGTH 40
//#define MY_RS485_HWSERIAL Serial1

// Message signing settings
//#define MY_SIGNING_SOFT
//#define MY_SIGNING_SOFT_RANDOMSEED_PIN 7
//#define MY_SIGNING_REQUEST_SIGNATURES
//#define MY_SIGNING_ATSHA204

// OTA Firmware update settings
//#define MY_OTA_FIRMWARE_FEATURE
//#define OTA_WAIT_PERIOD 300
//#define FIRMWARE_MAX_REQUESTS 2
//#define MY_OTA_RETRY 2

/**********************************
 * MySensors gateway configuration
 */
// Common gateway settings
//#define MY_REPEATER_FEATURE

// Serial gateway settings
//#define MY_GATEWAY_SERIAL

// Ethernet gateway settings
//#define MY_GATEWAY_W5100

// ESP8266 gateway settings
//#define MY_GATEWAY_ESP8266
//#define MY_ESP8266_SSID ""
//#define MY_ESP8266_PASSWORD ""

// Gateway networking settings
//#define MY_IP_ADDRESS 192,168,178,87
//#define MY_IP_GATEWAY_ADDRESS 192,168,178,1
//#define MY_IP_SUBNET_ADDRESS 255,255,255,0
//#define MY_PORT 5003
//#define MY_GATEWAY_MAX_CLIENTS 2
//#define MY_USE_UDP

// Gateway MQTT settings
//#define MY_GATEWAY_MQTT_CLIENT
//#define MY_CONTROLLER_IP_ADDRESS 192, 168, 178, 68
//#define MY_PORT 1883
//#define MY_MQTT_USER "username"
//#define MY_MQTT_PASSWORD "password"
//#define MY_MQTT_CLIENT_ID "mysensors-1"
//#define MY_MQTT_PUBLISH_TOPIC_PREFIX "mygateway1-out"
//#define MY_MQTT_SUBSCRIBE_TOPIC_PREFIX "mygateway1-in"

// Gateway inclusion mode
//#define MY_INCLUSION_MODE_FEATURE
//#define MY_INCLUSION_BUTTON_FEATURE
//#define MY_INCLUSION_MODE_DURATION 60
//#define MY_DEFAULT_LED_BLINK_PERIOD 300

// Gateway Leds settings
//#define MY_DEFAULT_ERR_LED_PIN 4
//#define MY_DEFAULT_RX_LED_PIN  5
//#define MY_DEFAULT_TX_LED_PIN  6

/***********************************
 * NodeManager configuration
 */
//#define NODEMANAGER_DEBUG ON
#define NODEMANAGER_INTERRUPTS OFF  //Not required for this sensor, just measure and sleep.
#define NODEMANAGER_SLEEP ON
//#define NODEMANAGER_RECEIVE ON
//#define NODEMANAGER_DEBUG_VERBOSE OFF
#define NODEMANAGER_POWER_MANAGER ON
//#define NODEMANAGER_CONDITIONAL_REPORT OFF
//#define NODEMANAGER_EEPROM OFF
//#define NODEMANAGER_TIME OFF
//#define NODEMANAGER_RTC OFF
//#define NODEMANAGER_SD OFF
//#define NODEMANAGER_HOOKING OFF
//#define NODEMANAGER_OTA_CONFIGURATION OFF
//#define NODEMANAGER_SERIAL_INPUT OFF

#endif
