//size of the robot
// 1 in diameter size
//wheel size = 1 in
//forward = bottom negtive, top postive 
// back = bottom pos, top negtive 
// left = bottom pos
//right = top pos 
// turn 1 times pi = 3.14/4 = 0.785
// number of pulses to wheel radio = 900
// 0.785 x 900 = 707
const int tm1 = 9;
const int tm2 = 10;
const int bm1 = 6;
const int bm2 = 11;
const int pd = 3;
const int it = 2;

volatile int pul = 0;
volatile int hipul = 0;
void fandtr()
{Serial.println("forward");
 while(pul <= 4500 && hipul<= 4500){
 analogWrite(tm1,255);
 analogWrite(tm2,0);
 analogWrite(bm1,255);
 analogWrite(bm2,0);
 }
stopit();
Serial.println("Right 90");
 while(hipul <= 707 ){
 analogWrite(tm1,255);
 analogWrite(tm2,0);
 analogWrite(bm1,0);
 analogWrite(bm2,0);
 }
stopit();

}
void FandTl(){
  Serial.println("forward 2");
 while(pul <= 9000 && hipul<= 9000){
 analogWrite(tm1,255);
 analogWrite(tm2,0);
 analogWrite(bm1,255);
 analogWrite(bm2,0);
 }
stopit();
Serial.println("left 90");
 while(pul <= 707 ){
 analogWrite(tm1,0);
 analogWrite(tm2,0);
 analogWrite(bm1,0);
 analogWrite(bm2,255);
 }
stopit();
} 
void F1andtl(){
  Serial.println("forward 1");
 while(pul <= 4500 && hipul<= 4500){
 analogWrite(tm1,255);
 analogWrite(tm2,0);
 analogWrite(bm1,255);
 analogWrite(bm2,0);
 }
stopit();
Serial.println("left 90");
 while(pul <= 707 ){
 analogWrite(tm1,0);
 analogWrite(tm2,0);
 analogWrite(bm1,0);
 analogWrite(bm2,255);
 }
stopit();
}
void fin(){
  Serial.println("forward 1");
 while(pul <= 4500 && hipul<= 4500){
 analogWrite(tm1,255);
 analogWrite(tm2,0);
 analogWrite(bm1,255);
 analogWrite(bm2,0);
 }
stopit();
Serial.println("left 90");
 while(pul <= 707 ){
 analogWrite(tm1,0);
 analogWrite(tm2,0);
 analogWrite(bm1,0);
 analogWrite(bm2,255);
 }
stopit();
 Serial.println("forward 1");
 while(pul <= 4500 && hipul<= 4500){
 analogWrite(tm1,255);
 analogWrite(tm2,0);
 analogWrite(bm1,255);
 analogWrite(bm2,0);
 }
stopit();
 Serial.println("We did it!");
 delay(300);
 }

void stopit()
{ analogWrite(tm1,0);
 analogWrite(tm2,0);
 analogWrite(bm1,0);
 analogWrite(bm2,0);
 pul = 0;
 hipul = 0;
}

void astime(){
pul++;
}
  
void asytime(){
hipul++;
}

void setup()
{
  attachInterrupt(digitalPinToInterrupt(pd),astime,RISING);
  attachInterrupt(digitalPinToInterrupt(it),asytime,RISING);
 pinMode(tm1,OUTPUT);
 pinMode(tm2,OUTPUT);
 pinMode(bm1,OUTPUT);
 pinMode(bm2,OUTPUT);
 pinMode(pd,INPUT_PULLUP);
 pinMode(it,INPUT_PULLUP);
 Serial.begin(9600);
}

void loop()
{ //fandtr();
  //fandtr();
 ///fandtr();
 FandTl();
 F1andtl();
 fin();
 stopit();
}