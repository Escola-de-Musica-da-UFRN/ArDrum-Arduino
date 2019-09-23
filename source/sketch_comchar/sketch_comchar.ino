/*==== ON/OFF PADS ====*/
#define ISON_CX true
#define ISON_BU true
#define ISON_CH true
#define ISON_CR true
#define ISON_RI true
#define ISON_T1 true
#define ISON_T2 false
#define ISON_SU false

/*==== ARDUINO UNO / MEGA ====*/
//#define UNO
#define MEGA

/*==== THRESHOLD ====*/
#define TSHD_STD 150      // Standard Threshold

#define TSHD_CX 230
#define TSHD_BU 220
#define TSHD_CH 170
#define TSHD_CR 200
#define TSHD_RI TSHD_STD
#define TSHD_T1 200
#define TSHD_T2 TSHD_STD
#define TSHD_SU 5

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

/* variables to get adc values */
byte adc7 = 0, adc6 = 0, adc5 = 0, adc4 = 0, adc3 = 0, adc2 = 0, adc1 = 0, adc0 = 0;

/* variables to set how time to wait after a hit */
int aux7 = WAIT_STD, aux6 = WAIT_STD, aux5 = WAIT_STD, aux4 = WAIT_STD, aux3 = WAIT_STD,
    aux2 = WAIT_STD, aux1 = WAIT_STD, aux0 = WAIT_STD;

/* string to concatenate all hitted pad tags */
String str = "";


void setup() {
  Serial.begin(115200);   // starting serial
}


void loop() {
  // strint to concatenate the pad tags
  str = "";

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
  // Surdo
  if( ISON_SU && adc7 > TSHD_SU && aux7 == 0 ){
    str.concat('7');
    aux7 = WAIT_SU;
  }

  // tom2
  if( ISON_T2 && adc6 > TSHD_T2 && aux6 == 0 ){
    str.concat('6');
    aux6 = WAIT_T2;
  }
#endif

  // tom1
  if( ISON_T1 && adc5 > TSHD_T1 && aux5 == 0 ){
    str.concat('5');
    aux5 = WAIT_T1;
  }

  // ride
  if( ISON_RI && adc4 > TSHD_RI && aux4 == 0 ){
    str.concat('4');
    aux4 = WAIT_RI;
  }

  // crash
  if( ISON_CR && adc3 > TSHD_CR && aux3 == 0 ){
    str.concat('3');
    aux3 = WAIT_CR;
  }

  // chimbal
  if( ISON_CH && adc2 > TSHD_CH && aux2 == 0 ){
    str.concat('2');
    aux2 = WAIT_CH;
  }

  // bumbo
  if( ISON_BU && adc1 > TSHD_BU && aux1 == 0 ){
    str.concat('1');
    aux1 = WAIT_BU;
  }

  // caixa
  if( ISON_CX && adc0 > TSHD_CX && aux0 == 0 ){
    str.concat('0');
    aux0 = WAIT_CX;
  }

  // sending result
  if( str != "" )
    Serial.print(str);

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
