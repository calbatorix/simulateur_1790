#include <Thread.h>
#include <ThreadController.h>

ThreadController controll = ThreadController();
Thread mesureThread = Thread();
Thread envoieThread = Thread();

#define NUM_AXES    4         // 1 axes

typedef struct joyReport_t {
    int16_t axis[NUM_AXES];
} joyReport_t;

joyReport_t joyReport;

int valeur_Min[NUM_AXES];
int valeur_Max[NUM_AXES];
void setup(void);
void loop(void);

void setup() 
{
    Serial.begin(115200);
    delay(200);
    mesureThread.onRun(mesure);
    mesureThread.setInterval(50);
    envoieThread.onRun(envoieUSB);
    envoieThread.setInterval(50);
    controll.add(&mesureThread);
    controll.add(&envoieThread);    

    for (uint8_t ind=0; ind<NUM_AXES; ind++) 
    {
      valeur_Min[ind] = analogRead(ind) ;
    valeur_Max[ind] = analogRead(ind)+1 ;
    }
    
}

void mesure(){
      for (uint8_t ind=0; ind<NUM_AXES; ind++)
    {
      int valeur_Potar = analogRead(ind);
    
      if ( valeur_Potar < valeur_Min[ind])
      {  
        valeur_Min[ind] = valeur_Potar ;
      }   
      if ( valeur_Potar > valeur_Max[ind])
      {
        valeur_Max[ind] = valeur_Potar ;
      }
    
      joyReport.axis[ind] =map(analogRead(ind), valeur_Min[ind], valeur_Max[ind], -32768,32767 );

    }
}

void envoieUSB(){
  sendJoyReport(&joyReport);
}
void sendJoyReport(struct joyReport_t *report){
    Serial.write((uint8_t *)report, sizeof(joyReport_t));
}

void loop() {
controll.run();
}
