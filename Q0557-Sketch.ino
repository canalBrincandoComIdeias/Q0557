#include <TM1637.h>

#define pinSensor A0

// Instantiation and pins configurations
// Pin 3 - > DIO
// Pin 2 - > CLK
TM1637 tm(2, 3);

int contador = 0;
bool estado    = false;
bool estadoAnt = false;

void setup()
{
    pinMode(pinSensor, INPUT);
    tm.init();
    tm.dispNumber(contador);
    delay(200);
}

void loop()
{
    estado = !digitalRead(pinSensor);
    if (estado && !estadoAnt) {
       contador++;
       tm.dispNumber(contador);
       delay(50);
    }

    estadoAnt = estado;
}
