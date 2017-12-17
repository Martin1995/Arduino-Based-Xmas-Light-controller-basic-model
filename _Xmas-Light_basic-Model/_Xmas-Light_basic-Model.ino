#define PWM_LED 11
#define LED_puls 13
int brightness = 0;
int fadeAmount = 5;
int Round = 0; // needed for Round Counter
int Round2 = 0; // needed for Round Counter of Programm 2
void setup() {
  // put your setup code here, to run once:
pinMode (PWM_LED, OUTPUT); //LED OUTPUT for PWM blinker
//pinMode (LED_puls, OUTPUT); //Arduino on board LED for Heartbeat of the controller (normally commented out), only uncomment for debugging!
}

void loop() {
  // put your main code here, to run repeatedly:
if(Round == 1020) {
  while (Round2 <=100) {
    digitalWrite(LED_puls, ! digitalRead(LED_puls)); //Arduino heartbeat routine (inverting the status of LED_puls)
    digitalWrite(PWM_LED, ! digitalRead(PWM_LED));
    Round2 = Round2 + 1;
    delay(200);
  }
  Round = 0;
  Round2 = 0;
}
digitalWrite(LED_puls, ! digitalRead(LED_puls)); //Arduino heartbeat routine (inverting the status of LED_puls)
analogWrite(PWM_LED, brightness);
brightness = brightness + fadeAmount;
if (brightness <= 0 || brightness >=255) {
  fadeAmount = -fadeAmount;
}
Round = Round + 1;
delay(100);
}
