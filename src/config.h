/** ---------------------------------------
 *      System configuration
 * ---------------------------------------*/
// Temperatura type Sensor
#define MAX6675_TEMP_SENSOR
//#define THERMISTOR_TEMP_SENSOR

//Display interface
#define SSD1306_OLED
/**
 * Pin mapping:
 * D8 - Temperature UP
 * D9 - Turn on or off the heating element
 * D10 - Temperature DOWN
 * A1 - Thermiston pin (if used)
 * - MAX6675:
 * - - SCLK - 4
 * - - CS - 3
 * - - MISO - 2
 */
/** ----------------------
 * Pins configuration
 * ----------------------- */
// #define COOLER_FAN 3 //WORK IN PROGRESS: FAST COOLING
#define HEATER_SIGNAL_PIN 13

//Sensor type configuration
#if defined THERMISTOR_TEMP_SENSOR
//Using Thermiston as temperature sensor
#define ThERMISTOR_PIN A1
#elif defined MAX6675_TEMP_SENSOR
//Using Thermocouple and MAX6675 as temperature sensor 
#define MAX6675_SCLK 4
#define MAX6675_CS 3
#define MAX6675_MISO 2
#else
//You must have at least one temperature sensor
#error No temperature sensor defined! You must have at least one temperature sensor.
#endif

#define BUTTON_TEMP_UP_PINMASK PINB0      // D8
#define BUTTON_TURN_ON_OFF_PINMASK PINB1  // D9
#define BUTTON_TEMP_DOWN_PINMASK PINB2    // 10

#include <Arduino.h>

#if defined SSD1306_OLED
//Adafruit SSD1306 library dependences.
//If you are using VScode with PlatformIO be sure that you have 
// this libraries in platformio.ini library depencies
// eg.:
//lib_deps = 
//	adafruit/Adafruit GFX Library @ ^1.10.12
//	adafruit/Adafruit SSD1306 @ ^2.5.0
//	adafruit/MAX6675 library@^1.1.0
#include <Adafruit_GFX.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_SSD1306.h>
#endif
#include <Wire.h>
#ifdef MAX6675_TEMP_SENSOR
#include <max6675.h>  // Biblioteca de controle
#endif