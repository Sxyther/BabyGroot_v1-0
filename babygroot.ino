#include "groot.h"

/**********************/
/* Global Definitions */
/**********************/
#define SERIAL_BAUD 115200





/************************************************************************/
void alarma0(void)
{
    Serial.println("Funcion Alarma 0 ");
}

/************************************************************************/
void alarma1(void)
{
    Serial.println("Funcion Alarma 1 ");
}

/************************************************************************/
void alarma2(void)
{
    Serial.println("Funcion Alarma 2 ");
}
/************************************************************************/
void alarma3(void)
{
    Serial.println("Funcion Alarma 3 ");
}
/************************************************************************/
void alarma4(void)
{
    Serial.println("Funcion Alarma 4 ");
}
  

/************************************************************************/
void setup() 
{
    Serial.begin(SERIAL_BAUD);
    delay(200);
  
    Serial.println("=======================");
    Serial.println("BabyGroot por MakersGDL");
    Serial.println("=======================");
  
    /* Inicializacion BabyGroot */ 
    grootInit();
    
    /*----------------------------*/
    /* Set Date/Time on DS3231 RTC*/
    /*----------------------------*/
    //grootSetDateTime(minuto,hora,dia,mes,año)
    //grootSetDateTime(55,15,11,6,18 );


    /*------------------------------------------*/
    /* Registro de Alarmas y funciones a llamar */
    /*------------------------------------------*/
    //grootRegisterAlarm(hora,minuto,dias,callback)
    grootRegisterAlarm(0,17,20,B01111111,alarma0);
    grootRegisterAlarm(1,17,17,B01111101,alarma1);
    grootRegisterAlarm(2,17,11,B01111111,alarma2);
    grootRegisterAlarm(3,17,19,B01111101,alarma3);                                                                                                      
    grootRegisterAlarm(4,17,18,B01111111,alarma4);

    /*------------------------------------------*/
    /* Activacion de Alarmas */                              
    /*------------------------------------------*/
    grootEnableAlarm(2);
    grootEnableAlarm(4);
    grootEnableAlarm(1);
    grootEnableAlarm(3);
    grootEnableAlarm(0);

    Serial.println("--- End of Setup, moving to loop ---");
}


/************************************************************************/
void loop() 
{
    /* Servicio a sistema Baby Groot */
    grootService();
    grootTestValves(500);
}

