

#define uint8 unsigned char


#define MAX_ALARMS  5


// Valve definition 
#define VALVE1  4
#define VALVE2  5
#define VALVE3  6
#define VALVE4  7
#define VALVE5  8



#define OFF LOW
#define ON HIGH


typedef struct{
  uint8 ghour;
  uint8 gminute;  
  uint8 gdays;  
}grootAlarm;

 /* Prototypes */
void grootRegisterAlarm(uint8 u8Alarm,uint8 u8hour,uint8 minutes,uint8 u8days,void (*f)());
void grootEnableAlarm(uint8 u8Alarm);
void grootInit(void);
void grootService(void);
void set_RTC_alarm(uint8,uint8);
void grootSetDateTime(uint8 ,uint8 ,uint8 ,uint8 ,uint8);
void grootTestValves(int u16Delay);
uint8 grootLookNextAlarm(uint8,uint8);
uint8 grootActivateNextAlarm(void);
uint8 DayOfWeek(struct ts );



