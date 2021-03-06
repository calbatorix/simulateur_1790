#define NUM_AXES    4         // 4 axes, X, Y, Z, etc

typedef struct joyReport_t {
    int16_t axis[NUM_AXES];
} joyReport_t;

joyReport_t joyReport;

int valeur_Min[NUM_AXES];
int valeur_Max[NUM_AXES];
void setup(void);
void loop(void);
void sendJoyReport(joyReport_t *report);

void setup() {
    Serial.begin(115200);

    for (uint8_t ind=0; ind<NUM_AXES; ind++) 
    {
      valeur_Min[ind] = analogRead(ind) ;
    valeur_Max[ind] = analogRead(ind)+1 ;
    }
    delay(200);
}

void mesure(){
    for (uint8_t ind=0; ind<NUM_AXES; ind++){
      int valeur_Potar = analogRead(ind);
      if ( valeur_Potar < valeur_Min[ind]) 
        valeur_Min[ind] = valeur_Potar ; 
      if ( valeur_Potar > valeur_Max[ind])
        valeur_Max[ind] = valeur_Potar ;
    
      joyReport.axis[ind] =map(analogRead(ind), valeur_Min[ind], valeur_Max[ind], -32768,32767 );

    }
}

void sendJoyReport(struct joyReport_t *report){
    Serial.write((uint8_t *)report, sizeof(joyReport_t));
}

void loop() 
{
   mesure();
   sendJoyReport(&joyReport);

    delay(100);
}
