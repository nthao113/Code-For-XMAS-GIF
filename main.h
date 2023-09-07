#include <FastLED.h>
#include <avr/pgmspace.h>

#include "config.h"
#include "variable.h"

DEFINE_GRADIENT_PALETTE( browngreen_gp ) { 
    0,    6,  255,    0,     //green
   71,    0,  255,  153,     //bluegreen
  122,  200,  200,  200,     //gray
  181,  110,   61,    6,     //brown
  255,    6,  255,    0      //green
};
DEFINE_GRADIENT_PALETTE( redgreen_gp ) {  
    0,    200,  0,    0,     //green
   71,    41, 255, 98,     //bluegreen
  122,    200,  200,  200,     //gray
  181,    41, 255, 98,     //brown
  255,    200,  0,    0,      //green
};
CRGBPalette16 orangePink = browngreen_gp;
CRGBPalette16 redPink = redgreen_gp;

void setPixel(int Pixel, byte red, byte green, byte blue) {
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
}
void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < tong; i++ ) {
    setPixel(i, red, green, blue);
  }
  FastLED.show();
}
void FadeIn(byte red, byte green, byte blue, byte k){
  float r, g, b;
  for(int i = 0; i < 256; i=i+k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    setAll(r,g,b);
  }
}

void FadeOut(byte red, byte green, byte blue, byte k){
  float r, g, b;  
  for(int i = 255; i >= 0; i=i-k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    setAll(r,g,b);
  }
}

void FadeInOut(byte red, byte green, byte blue, byte k){
  float r, g, b;
     
  for(int i = 0; i < 256; i=i+k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    setAll(r,g,b);
  }
     
  for(int i = 255; i >= 0; i=i-k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    setAll(r,g,b);
  }
}
void customSetLED(int start, int end, byte red, byte green, byte blue) {
  for(int i = start; i < end; i++){
    setPixel(i, red, green, blue);
  }
}
void customSetALED_tang(int start, int end, byte red, byte green, byte blue) {
  for(int i = start; i < end; i++){
    setPixel(i, red, green, blue); 
    FastLED.show();      
  }
}
void customSetALED_giam(int start, int end, byte red, byte green, byte blue) {
  for(int i = start; i > end; i--){
    setPixel(i, red, green, blue);     
    FastLED.show();    
  }
}
void luon(byte red, byte green, byte blue){
  FastLED.clear();
  customSetALED_giam(26,0, red,green,blue);//san ngoai ben trai
  customSetALED_tang(120,141, red,green,blue);//san trong trai
  customSetALED_tang(230,252, red,green,blue);//san trong phai
  customSetALED_tang(167,199, red,green,blue);//san ngoai phai
  customSetALED_giam(345,331, red,green,blue);//nha 1
  customSetALED_giam(321,307, red,green,blue);//nha 2
  customSetALED_giam(392,381, red,green,blue); //nha 3
  customSetALED_tang(365,376, red,green,blue);//nha 4
  customSetALED_tang(273,287, red,green,blue);//nha 5
  customSetALED_tang(252,264, red,green,blue);// nha 6
  customSetALED_tang(452,466, red,green,blue);//mai 1  
  customSetALED_tang(444,452, red,green,blue);//mai 2
  customSetALED_giam(435,427, red,green,blue);//mai 3
  customSetALED_tang(410,423, red,green,blue);//mai 4
  customSetALED_giam(26,0, 0,0,0);//san ngoai ben trai
  customSetALED_tang(120,141, 0,0,0);//san trong trai
  customSetALED_tang(230,252, 0,0,0);//san trong phai
  customSetALED_tang(167,199, 0,0,0);//san ngoai phai
  customSetALED_giam(345,331, 0,0,0);//nha 1
  customSetALED_giam(321,307, 0,0,0);//nha 2
  customSetALED_giam(392,381, 0,0,0); //nha 3
  customSetALED_tang(365,376, 0,0,0);//nha 4
  customSetALED_tang(273,287, 0,0,0);//nha 5
  customSetALED_tang(252,264, 0,0,0);// nha 6
  customSetALED_tang(452,466, 0,0,0);//mai 1  
  customSetALED_tang(444,452, 0,0,0);//mai 2
  customSetALED_giam(435,427, 0,0,0);//mai 3
  customSetALED_tang(410,423, 0,0,0);//mai 4 
}
void FadeInOut_All(byte red, byte green, byte blue, byte k, byte mode){
  float r, g, b;
  for(int i = 0; i < 256; i=i+k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    switch (mode) {
      case 1:
        customSetLED(37, 60, r , g, b);
        customSetLED(208,230, r , g, b);
        customSetLED(84,104, r , g, b);
        break;
      case 2:
        customSetLED(27, 37, r , g, b);
        customSetLED(120,141, r , g, b); 
        customSetLED(199,208, r , g, b); 
        customSetLED(230,252, r , g, b); 
        break;
      case 3:
        customSetLED(0,27, r , g, b); 
        customSetLED(60,84, r , g, b); 
        customSetLED(157,199, r , g, b);         
        break;
      case 4:
        // Hiệu ứng 4
        break;
      case 5:
        // Hiệu ứng 5
        break;
      case 6:
        customSetLED(252,393, r , g, b);  
        break;
      case 7:
        customSetLED(393,491, r , g, b); 
        break;
      case 8:
        customSetLED(0,252, r , g, b);   
        break;
      default:
        customSetLED(252,491, r , g, b);                      
        break;  
    }
    FastLED.show();
  }
  for(int i = 255; i >= 0 ; i=i-k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    switch (mode) {
      case 1:
        customSetLED(37, 60, r , g, b);
        customSetLED(208,230, r , g, b);
        customSetLED(84,104, r , g, b);
        break;
      case 2:
        customSetLED(27, 37, r , g, b);
        customSetLED(120,141, r , g, b); 
        customSetLED(199,208, r , g, b); 
        customSetLED(230,252, r , g, b); 
        break;
      case 3:
        customSetLED(0,27, r , g, b); 
        customSetLED(60,84, r , g, b); 
        customSetLED(157,199, r , g, b);         
        break;
      case 4:
        // Hiệu ứng 4
        break;
      case 5:
        // Hiệu ứng 5
        break;
      case 6:
        customSetLED(252,393, r , g, b);  
        break;
      case 7:
        customSetLED(393,491, r , g, b); 
        break;
      case 8:
        customSetLED(0,252, r , g, b);   
        break;
      default:
        customSetLED(252,491, r , g, b);       
        break;  
    }
    FastLED.show();
  }
}
/*
void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) {
    setAll(red,green,blue);
    FastLED.show();
    delay(FlashDelay);
    setAll(0,0,0);
    FastLED.show();
    delay(FlashDelay);
  }
 
 delay(EndPause);
}
*/
void FadeIn_All(byte red, byte green, byte blue, byte k, byte mode){
  float r, g, b;
  for(int i = 0; i < 256; i=i+k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    switch (mode) {
      case 1:
        break;
      case 2:
        customSetLED(84,104, r , g, b);
        break;
      case 3:
        customSetLED(37, 60, r , g, b);
        break;
      case 4:
        customSetLED(208,230, r , g, b);
        break;
      case 5:
        customSetLED(27, 37, r , g, b);
        customSetLED(120,141, r , g, b); 
        customSetLED(199,208, r , g, b); 
        customSetLED(230,252, r , g, b); 
        break;
      case 6:
        customSetLED(0,27, r , g, b); 
        customSetLED(60,84, r , g, b); 
        customSetLED(157,199, r , g, b);              
        break;
      case 7: 
        customSetLED(104,120, r , g, b); 
        customSetLED(141,157, r , g, b);  
        break;
      case 8: 
         customSetLED(252,491, r , g, b);       
        break;
      default:                      
        break;  
    }
    FastLED.show();
  }
}

void Sparkle(byte red, byte green, byte blue, int SpeedDelay) {
  setPixel(random(0,20),red,green,blue);
  setPixel(random(51,100),red,green,blue);
  setPixel(random(101,150),red,green,blue);
  setPixel(random(151,200),red,green,blue);
  setPixel(random(201,250),red,green,blue);
  setPixel(random(251,300),red,green,blue);
  setPixel(random(301,350),red,green,blue);
  setPixel(random(351,400),red,green,blue);
  setPixel(random(0,251),red,green,blue);
  setPixel(random(252,393),red,green,blue);
  setPixel(random(393,491),red,green,blue);
  setPixel(random(393,491),red,green,blue);  
  FastLED.show();
  delay(SpeedDelay);
  FastLED.clear();
}
void FadeInLeft(byte red, byte green, byte blue, byte k){
  float r, g, b;
  for(int i = 0; i < 256; i=i+k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    customSetLED(0, 104, r , g, b);
    FastLED.show();
  }
}
void FadeInCenter(byte red, byte green, byte blue, byte k){
  float r, g, b;
  for(int i = 0; i < 256; i=i+k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    customSetLED(104, 157, r , g, b);
    customSetLED(230, 252, r , g, b);
    FastLED.show();
  }
}
void FadeInRight(byte red, byte green, byte blue, byte k){
  float r, g, b;
  for(int i = 0; i < 256; i=i+k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    customSetLED(157, 230, r , g, b);
    FastLED.show();
  }
}
void FadeOutLeft(byte red, byte green, byte blue, byte k){
  float r, g, b;  
  for(int i = 255; i >= 0; i=i-k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    customSetLED(0, 104, r , g, b);
    FastLED.show();
  }
}
void FadeOutCenter(byte red, byte green, byte blue, byte k){
  float r, g, b;  
  for(int i = 255; i >= 0; i=i-k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    customSetLED(104, 157, r , g, b);
    customSetLED(230, 252, r , g, b);
    FastLED.show();
  }
}
void FadeOutRight(byte red, byte green, byte blue, byte k){
  float r, g, b;  
  for(int i = 255; i >= 0; i=i-k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    customSetLED(157, 230, r , g, b);
    FastLED.show();
  }
}
void FadeIn_NHA(byte red, byte green, byte blue, byte k){
  float r, g, b;
  for(int i = 0; i < 256; i=i+k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    customSetLED(252,491, r , g, b);
    FastLED.show();
  }
}
void FadeOut_NHA(byte red, byte green, byte blue, byte k){
  float r, g, b;  
  for(int i = 255; i >= 0; i=i-k) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    customSetLED(252,491, r , g, b);
    FastLED.show();
  }
}
void xenke(int numLeds, byte red1, byte green1, byte blue1, byte red2, byte green2, byte blue2, int ms){
  for (int i = 0; i < numLeds; i++) {
    if (i % 2 == 0) {
      leds[i] = CRGB(red1, green1, blue1);
    }
  }
  FastLED.show();
  delay(ms);
  FastLED.clear();
  for (int i = 0; i < numLeds; i++) {
    if (i % 2 != 0) {
      leds[i] = CRGB(red2, green2, blue2);
    }
  }
  FastLED.show();
  delay(ms);
  FastLED.clear();
}
void clearLED() {
  setAll(0,0,0);
}
/*
void dai_mau_led()
{
  FastLED.clear(); 
  // dải màu led dịch chuyển
  int a[24]={255,255,255,255,255,191,128,64,0,0,0,0,0,0,0,0,0,64,128,191,255,255,255,255};
  int b[24]={0,64,128,191,255,255,255,255,255,255,255,255,255,191,128,64,0,0,0,0,0,0,0,0};
  int c[24]={0,0,0,0,0,0,0,0,0,64,128,191,255,255,255,255,255,255,255,255,255,191,128,64};        
  for(int i=0;i<tong;i++) 
  {               
    leds[i]=CRGB(a[i%24],b[i%24],c[i%24]);
    if (i>=7) leds1[i-7]=CRGB(0, 0, 0);
    FastLED.show(); 
    delay(1);   
  }   
}
*/
void SnowSparkle(byte red1, byte green1, byte blue1, byte red2, byte green2, byte blue2, int SparkleDelay, int SpeedDelay) {
  setAll(red1,green1,blue1);
 
  setPixel(random(0,50),red2,green2,blue2);
  setPixel(random(51,100),red2,green2,blue2);
  setPixel(random(101,150),red2,green2,blue2);
  setPixel(random(151,200),red2,green2,blue2);
  setPixel(random(201,250),red2,green2,blue2);
  setPixel(random(251,300),red2,green2,blue2);
  setPixel(random(301,350),red2,green2,blue2);
  setPixel(random(351,400),red2,green2,blue2);
  setPixel(random(0,251),red2,green2,blue2);
  setPixel(random(252,490),red2,green2,blue2);
  setPixel(random(252,490),red2,green2,blue2);
  FastLED.show();
  delay(SparkleDelay);
  setPixel(random(0,50),red2,green2,blue2);
  setPixel(random(51,100),red2,green2,blue2);
  setPixel(random(101,150),red2,green2,blue2);
  setPixel(random(151,200),red2,green2,blue2);
  setPixel(random(201,250),red2,green2,blue2);
  setPixel(random(251,300),red2,green2,blue2);
  setPixel(random(301,350),red2,green2,blue2);
  setPixel(random(351,400),red2,green2,blue2);
  setPixel(random(0,251),red2,green2,blue2);
  setPixel(random(252,490),red2,green2,blue2);
  setPixel(random(252,490),red2,green2,blue2);
  FastLED.show();
  delay(SpeedDelay);
}
void SnowSparkle1(byte red1, byte green1, byte blue1, byte red2, byte green2, byte blue2, int SparkleDelay) {
  setAll(red1,green1,blue1);
  setPixel(random(0,20),red2,green2,blue2);
  setPixel(random(21,40),red2,green2,blue2);
  setPixel(random(41,60),red2,green2,blue2);
  setPixel(random(61,80),red2,green2,blue2);
  setPixel(random(81,100),red2,green2,blue2);
  setPixel(random(101,120),red2,green2,blue2);
  setPixel(random(121,140),red2,green2,blue2);
  setPixel(random(141,160),red2,green2,blue2);
  setPixel(random(161,180),red2,green2,blue2);
  setPixel(random(181,200),red2,green2,blue2);
  setPixel(random(201,220),red2,green2,blue2);
  setPixel(random(221,240),red2,green2,blue2);
  setPixel(random(241,260),red2,green2,blue2);
  setPixel(random(261,280),red2,green2,blue2);
  setPixel(random(281,300),red2,green2,blue2);
  setPixel(random(301,320),red2,green2,blue2);
  setPixel(random(321,340),red2,green2,blue2);
  setPixel(random(341,360),red2,green2,blue2);
  setPixel(random(361,380),red2,green2,blue2);
  setPixel(random(381,400),red2,green2,blue2);
  setPixel(random(401,420),red2,green2,blue2);
  setPixel(random(421,440),red2,green2,blue2);
  setPixel(random(441,460),red2,green2,blue2);
  setPixel(random(461,480),red2,green2,blue2);
  setPixel(random(481,400),red2,green2,blue2);
  FastLED.show();
  delay(SparkleDelay);
}

void movingDot() {
  uint16_t sinBeat = beatsin16(30, 0, tong - 1, 0, 0);

  leds[sinBeat] = CRGB::Blue;
  
  fadeToBlackBy(leds,tong, 10);

  FastLED.show();
}

void sangdan(int led, byte ms){
  for(int i = 0; i < BRIGHTNESS; i++){
  FastLED.setBrightness(i > BRIGHTNESS ? BRIGHTNESS : i);
  for(int i = 0; i < 40; i++){
    setPixel(random(0, led), random(0, 255), random(0, 255), random(0, 255));
  }
  FastLED.show();
  delay(ms);
  }
}

void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position=0;
 
  for(int j=0; j<10; j++)
  {
      Position++; // = 0; //Position + Rate;
      for(int i=0; i<tong; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        setPixel(i,((sin(i+Position) * 127 + 128)/255)*red,
                   ((sin(i+Position) * 127 + 128)/255)*green,
                   ((sin(i+Position) * 127 + 128)/255)*blue);
      }
     
      FastLED.show();
      delay(WaveDelay);
  }
}
void rainbowDot() {
  uint16_t posBeat  = beatsin16(30, 0, tong - 1, 0, 0);
  uint16_t posBeat2 = beatsin16(60, 0, tong - 1, 0, 0);
  uint16_t posBeat3 = beatsin16(30, 0, tong - 1, 0, 32767);
  uint16_t posBeat4 = beatsin16(60, 0, tong - 1, 0, 32767);

  // Wave for LED color
  uint8_t colBeat  = beatsin8(45, 0, 255, 0, 0);

  leds[(posBeat + posBeat2) / 2]  = CHSV(colBeat, 255, 255);
  leds[(posBeat3 + posBeat4) / 2]  = CHSV(colBeat, 255, 255);

  fadeToBlackBy(leds, tong, 10);

  FastLED.show();
}
void rainBowDrop1() {
  uint16_t beatA = beatsin16(30, 0, 255);
  uint16_t beatB = beatsin16(20, 0, 255);
  fill_palette(leds, tong, (beatA + beatB) / 2, 100, orangePink, 200, LINEARBLEND);

  FastLED.show();
}

void rainBowDrop2() {
  uint16_t beatA = beatsin16(30, 0, 255);
  uint16_t beatB = beatsin16(20, 0, 255);
  fill_palette(leds, tong, (beatA + beatB) / 2, 100, redPink, 200, LINEARBLEND);

  FastLED.show();
}
void TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(0,0,0);
 
  for (int i=0; i<Count; i++) {
     setPixel(random(tong),random(0,255),random(0,255),random(0,255));
     FastLED.show();
     delay(SpeedDelay);
     if(OnlyOne) {
       setAll(0,0,0);
     }
   }
 
  delay(SpeedDelay);
}
