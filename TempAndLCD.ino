//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "dht.h"
#define dht_apin A0
dht DHT;
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init(); // Инициализация lcd
  lcd.backlight(); // Включаем подсветку

  Serial.begin(9600);
}


void loop()
{

  // Добавляем паузы в несколько секунд между измерениями
delay(2000);

  DHT.read11(dht_apin);
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h = DHT.humidity;
// Read temperature as Celsius
float t = DHT.temperature;
// Read temperature as Fahrenheit

// Выводим показания влажности и температуры
lcd.setCursor(0, 0); // Устанавливаем курсор в начало 1 строки
lcd.print("Hum = % "); // Выводим текст
lcd.setCursor(7, 0); // Устанавливаем курсор на 7 символ
lcd.print(h, 1); // Выводим на экран значение влажности
lcd.setCursor(0, 1); // Устанавливаем курсор в начало 2 строки
lcd.print("Temp = \1C "); // Выводим текст, \1 - значок градуса
lcd.setCursor(7, 1); // Устанавливаем курсор на 7 символ
lcd.print(t,1); // Выводим значение температуры
}
