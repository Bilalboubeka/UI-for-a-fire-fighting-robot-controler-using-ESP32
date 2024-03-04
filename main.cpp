
//https://github.com/Bilalboubeka




#include <U8g2lib.h>
U8G2_SH1106_128X64_NONAME_F_HW_I2C oled(U8G2_R0);
int progres = 0 ;
int dis = 0 ;

void setup() {
  oled.begin();  
}

void loop() {


oled.clearBuffer();          // Clear the buffer
oled.setFont(u8g2_font_siji_t_6x10);

 
//battry for the robot
oled.drawGlyph(114, 9, 0xe243);
//battry for the controler  
oled.drawGlyph(100, 9, 0xe243);

//network
oled.drawGlyph(1, 9, 0xe0f0);

//water pump
oled.drawGlyph(10, 9, 0xe1e4);

//imargncy
oled.drawGlyph(18, 9, 0xe040);

oled.drawStr(1, 34, "f:11");

//top rigt box 
oled.drawRFrame(100,10,25,18,3);

if (progres<100){
  progres++;
}
else{
  progres =0;
}


if (dis<20){
  dis++;
}
else{
  dis =0;
}


line();
speed ();
fire ();
tirminal ();
usonic1 ();
usonic2 ();
diractions ();
pumpProjection ();

oled.sendBuffer();           // Send the buffer to the display
}


//Line Follower (IR sensors status)


void line (){

int rond = random(6);

oled.drawRFrame(1,11,25,15,3);

if(rond==0){
oled.drawBox(3,13,3,11);
}
if(rond==1){
oled.drawBox(7,13,4,11);
}
if(rond==2){
oled.drawBox(12,13,3,11);
}
if(rond==3){
oled.drawBox(16,13,3,11);
}
if(rond==4){
oled.drawBox(21,13,3,11);
}
}


void speed (){

oled.setDrawColor(2);
oled.drawStr(56, 58, "100");
oled.drawRFrame(28,48,71,12,4);
oled.drawBox(30,50,map(progres,0,100,0,67),8); // max = 67
oled.drawLine(32, 61, map(progres,0,100,32,80), 61);

}


void fire (){

//fire sensor
oled.drawRFrame(28,35,71,12,4);
oled.setFont(u8g2_font_open_iconic_all_1x_t);
oled.drawGlyph(map(progres,0,100,32,80), 45, 0x00a8);
}
void tirminal () {
// tirminal
oled.drawRFrame(28,1,71,33,6);
}


void usonic1 (){
// uper usonic
oled.setDrawColor(1);
oled.drawRFrame(14,36,12,28,3);
oled.drawBox(16,57,8,5);


}

void usonic2 () {
  // butom usonic

oled.setDrawColor(1);
oled.drawRFrame(1,36,12,28,3);
oled.drawBox(3,57,8,5);

}
void diractions (){
  oled.drawRFrame(100,44,25,18,3);
  oled.setFont(u8g2_font_siji_t_6x10);
 oled.drawGlyph(107, 57, 0xe191);
}
void pumpProjection (){
oled.setFont(u8g2_font_siji_t_6x10);
oled.drawRFrame(100,27,25,16,3);
 oled.drawGlyph(107, 39, 0xe191); 
}