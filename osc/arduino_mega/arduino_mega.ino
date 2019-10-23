/*==== ON/OFF PADS ====*/
#define ISON_CX true
#define ISON_BU true
#define ISON_CH true
#define ISON_CR true
#define ISON_RI true
#define ISON_T1 true
#define ISON_T2 true
#define ISON_SU true

/*==== ARDUINO UNO / MEGA ====*/
//#define UNO
#define MEGA

/*==== DEBUG MESSAGES VIA SERIAL ====*/
#define DEBUG

/*==== THRESHOLD ====*/
#define TSHD_STD 150      // Standard Threshold

#define TSHD_CX 100
#define TSHD_BU 220
#define TSHD_CH 220
#define TSHD_CR 220
#define TSHD_RI 200
#define TSHD_T1 230
#define TSHD_T2 200
#define TSHD_SU 200

/*==== WAIT ====*/
#define WAIT_STD 60       // Standard Wait Time

#define WAIT_CX WAIT_STD
#define WAIT_BU WAIT_STD
#define WAIT_CH WAIT_STD
#define WAIT_CR WAIT_STD
#define WAIT_RI WAIT_STD
#define WAIT_T1 WAIT_STD
#define WAIT_T2 WAIT_STD
#define WAIT_SU WAIT_STD

/*==== MAIN DELAY ====*/
#define MAIN_DELAY 1

/*==== DIGITALWRITE DELAY ====*/
#define DIGI_DELAY 100

/* variables to get adc values */
byte adc7 = 0, adc6 = 0, adc5 = 0, adc4 = 0, adc3 = 0, adc2 = 0, adc1 = 0, adc0 = 0;

/* variables to set how time to wait after a hit */
int aux7 = WAIT_STD, aux6 = WAIT_STD, aux5 = WAIT_STD, aux4 = WAIT_STD, aux3 = WAIT_STD,
    aux2 = WAIT_STD, aux1 = WAIT_STD, aux0 = WAIT_STD;

/*==== DEFINING PIN ====*/
#define PIN_CX 2 // snare
#define PIN_BU 3 // kick
#define PIN_CH 4 // hi-hat
#define PIN_CR 5 // crash
#define PIN_RI 6 // ride
#define PIN_T1 7 // tom1
#define PIN_T2 8 // tom2
#define PIN_SU 9 // floor

void setup() {
  #ifdef DEBUG
  Serial.begin(115200);   // starting serial to debug
  #endif
  
  pinMode(PIN_CX, OUTPUT); // snare
  pinMode(PIN_BU, OUTPUT); // kick
  pinMode(PIN_CH, OUTPUT); // hi-hat
  pinMode(PIN_CR, OUTPUT); // crash
  pinMode(PIN_RI, OUTPUT); // ride
  pinMode(PIN_T1, OUTPUT); // tom1
  pinMode(PIN_T2, OUTPUT); // tom2
  pinMode(PIN_SU, OUTPUT); // floor
}


void loop() {
  // getting values
#ifdef MEGA
  adc7 = analogRead(A7);
  adc6 = analogRead(A6);
#endif
  adc5 = analogRead(A5);
  adc4 = analogRead(A4);
  adc3 = analogRead(A3);
  adc2 = analogRead(A2);
  adc1 = analogRead(A1);
  adc0 = analogRead(A0);

  // checking pads
#ifdef MEGA
  // floor
  if( ISON_SU && adc7 > TSHD_SU && aux7 == 0 ){
    digitalWrite(PIN_SU, HIGH);
    delayMicroseconds(DIGI_DELAY);
    digitalWrite(PIN_SU, LOW);
    aux7 = WAIT_SU;
    
    #ifdef DEBUG
    Serial.println("floor");
    #endif
  }

  // tom2
  if( ISON_T2 && adc6 > TSHD_T2 && aux6 == 0 ){
    digitalWrite(PIN_T2, HIGH);
    delayMicroseconds(DIGI_DELAY);
    digitalWrite(PIN_T2, LOW);
    aux6 = WAIT_T2;
    
    #ifdef DEBUG
    Serial.println("tom2");
    #endif
  }
#endif

  // tom1
  if( ISON_T1 && adc5 > TSHD_T1 && aux5 == 0 ){
    digitalWrite(PIN_T1, HIGH);
    delayMicroseconds(DIGI_DELAY);
    digitalWrite(PIN_T1, LOW);
    aux5 = WAIT_T1;

    #ifdef DEBUG
    Serial.println("tom1");
    #endif
  }

  // ride
  if( ISON_RI && adc4 > TSHD_RI && aux4 == 0 ){
    digitalWrite(PIN_RI, HIGH);
    delayMicroseconds(DIGI_DELAY);
    digitalWrite(PIN_RI, LOW);
    aux4 = WAIT_RI;

    #ifdef DEBUG
    Serial.println("ride");
    #endif
  }

  // crash
  if( ISON_CR && adc3 > TSHD_CR && aux3 == 0 ){
    digitalWrite(PIN_CR, HIGH);
    delayMicroseconds(DIGI_DELAY);
    digitalWrite(PIN_CR, LOW);
    aux3 = WAIT_CR;

    #ifdef DEBUG
    Serial.println("crash");
    #endif
  }

  // hi-hat
  if( ISON_CH && adc2 > TSHD_CH && aux2 == 0 ){
    digitalWrite(PIN_CH, HIGH);
    delayMicroseconds(DIGI_DELAY);
    digitalWrite(PIN_CH, LOW);
    aux2 = WAIT_CH;

    #ifdef DEBUG
    Serial.println("hi-hat");
    #endif
  }

  // kick
  if( ISON_BU && adc1 > TSHD_BU && aux1 == 0 ){
    digitalWrite(PIN_BU, HIGH);
    delayMicroseconds(DIGI_DELAY);
    digitalWrite(PIN_BU, LOW);
    aux1 = WAIT_BU;

    #ifdef DEBUG
    Serial.println("kick");
    #endif
  }

  // snare
  if( ISON_CX && adc0 > TSHD_CX && aux0 == 0 ){
    digitalWrite(PIN_CX, HIGH);
    delayMicroseconds(DIGI_DELAY);
    digitalWrite(PIN_CX, LOW);
    aux0 = WAIT_CX;

    #ifdef DEBUG
    Serial.println("snare");
    #endif
  }

  // removing one from wait time
#ifdef MEGA
  if(aux7>0) aux7--;
  if(aux6>0) aux6--;
#endif
  if(aux5>0) aux5--;
  if(aux4>0) aux4--;
  if(aux3>0) aux3--;
  if(aux2>0) aux2--;
  if(aux1>0) aux1--;
  if(aux0>0) aux0--;
  
  // delay
  delay(MAIN_DELAY);
}
