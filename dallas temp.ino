#include <LCD5110_Graph.h>// para la pantalla
#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2

LCD5110 LCD(3,4,5,7,6);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature miSensor(&oneWire);
double temp;
double tempDigital;


extern uint8_t SmallFont[]; // Indicamos el tipo de fuente SmallFont
extern uint8_t TinyFont []; // Indicamos el tipo de fuente TinyFont
extern uint8_t MediumNumbers[];

//prototipo de funciones
double obtenerTemperatura();
void saludarSensor();
void mostrarTemp();

void setup() {
  LCD.InitLCD();
  saludarSensor();
}

void loop() {
  miSensor.requestTemperatures();
  temp = obtenerTemperatura();
  mostrarTemp();
}
double obtenerTemperatura(){
  
  double tempC = miSensor.getTempCByIndex(0);
  return tempC;
}
void saludarSensor(){
  LCD.clrScr(); //Limpiamos la pantalla 
  LCD.setFont(SmallFont); //Decimos el tipo de fuente "SmallFont"
  LCD.print("SENSORES Y ",CENTER,5); //Escribimos un texto que sera colocado en
  LCD.print("ACTUADORES",CENTER,15); 
  LCD.print("2019-B",CENTER,25);
  LCD.update();
  delay(2000);
  LCD.clrScr();
  LCD.update();
  LCD.setFont(SmallFont);
  LCD.print("JEFFRY",CENTER,5);
  LCD.print("Q. B.",CENTER,15);
  LCD.update();
  delay(2000);
  LCD.clrScr();
  LCD.update();
}
void mostrarTemp(){
  LCD.setFont(TinyFont); //Decimos el tipo de fuente "SmallFont"
  LCD.print("laboratorio 1",0,5); //Escribimos un texto que sera colocado en
  LCD.setFont(MediumNumbers);
  LCD.print(String(temp),0,20);
  LCD.setFont(SmallFont);
  LCD.print("C",76,28);
  LCD.print(".",72,24);
  LCD.update();
  delay(50);
}
