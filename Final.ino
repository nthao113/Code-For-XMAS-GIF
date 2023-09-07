#include "main.h"


unsigned long milisecond;
unsigned long oldMillisecond;
bool start = false;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, tong);  
  FastLED.setBrightness(BRIGHTNESS);

  Serial.begin(9600);
  Serial.println("Ready!");
  pinMode(BUTTON, INPUT);
}

void loop() {
  clearLED();
  oldMillisecond = millis();
  Serial.println("Waitting!!!");
  if(digitalRead(4) == 1){
    while(digitalRead(4) == 1) {};
    start = true;
  }
  while(start == true) {
    Serial.println("Start!!!"); 
    milisecond = millis() - oldMillisecond;
    // Main control leds
    if(milisecond >= 4716 && milisecond < 6490) {
    Serial.println("0"); 
    }
    if(milisecond >= 6490 && milisecond < 6690) {
    Serial.println("1"); 
    FadeInOut_All(100, 255, 150, 12, 1);
    } 
    if(milisecond >= 7390 && milisecond < 7590) {
    Serial.println("1");
    FadeInOut_All(45, 247, 168, 12, 1);  
    }
    if(milisecond >= 8290 && milisecond < 8590) {
    Serial.println("2");
    FadeInOut_All(100, 255, 150, 12, 2);
    } 
    if(milisecond >= 9190 && milisecond < 9390) {
    Serial.println("2");
    FadeInOut_All(45, 247, 168, 12, 2);  
    } 
    if(milisecond >= 10090 && milisecond < 10290) {
    Serial.println("3");
    FadeInOut_All(100, 255, 150, 12, 3);    
    }  
    if(milisecond >= 10990 && milisecond < 11100) {
    Serial.println("3");
    FadeInOut_All(45, 247, 168, 12, 3);  
    }
    if(milisecond >= 11890 && milisecond < 12990) {
    Serial.println("4");
    }                                                                                                                                                                                                                                    
    if(milisecond >= 12790 && milisecond < 12890) {
    Serial.println("4");
    }
    if(milisecond >= 13690 && milisecond < 13700) {
    Serial.println("5");                                             
    } 
    if(milisecond >= 14590 && milisecond < 14600) {
    Serial.println("5");                                           
    } 
    if(milisecond >= 15490 && milisecond < 15690) {
    Serial.println("6");
    FadeInOut_All(100, 255, 150, 12, 6);                                              
    }  
    if(milisecond >= 16390 && milisecond < 16590) {
    Serial.println("6");
    FadeInOut_All(45, 247, 168, 12, 6);                                              
    }   
    if(milisecond >= 17290 && milisecond < 17490) {
    Serial.println("7");  
    FadeInOut_All(100, 255, 150, 12, 7);                                           
    } 
    if(milisecond >= 18190 && milisecond < 18390) {
    Serial.println("7");  
    FadeInOut_All(45, 247, 168, 12, 7);                                          
    }  
    if(milisecond >= 19090 && milisecond < 19290) {
    Serial.println("8"); 
    FadeInOut_All(100, 255, 150, 12, 8);                                         
    }  
    if(milisecond >= 19990 && milisecond < 20190) {
    Serial.println("8"); 
    FadeInOut_All(45, 247, 168, 12, 8);                                          
    } 
    if(milisecond >= 20890 && milisecond < 21090) {
    Serial.println("9"); 
    FadeInOut_All(100, 255, 150, 12, 9);                                         
    } 
    if(milisecond >= 21790 && milisecond < 21990) {
    Serial.println("9"); 
    FadeInOut_All(45, 247, 168, 12, 9);                                                
    }

    // 3 tích cuối                                            
    if(milisecond >= 22730 && milisecond < 22740) {
      customSetLED(0, 252, 16, 176, 51);
      FastLED.show();                                                    
    }
    if(milisecond >= 23174 && milisecond < 23200) {
      customSetLED(252,393, 255, 223, 114);
      FastLED.show();                                                      
    } 
    if(milisecond >= 23621 && milisecond < 23650) {
      customSetLED(393,491, 149, 10, 199);
      FastLED.show();                                                  
    }
    // Đoạn 2 
    if(milisecond >= 23900 && milisecond < 24000) {
      clearLED();                                            
    }
    if(milisecond >= 24529 && milisecond < 24729) {
      FadeInLeft(140, 8, 8,15);
      FadeInCenter(140, 8, 8,15);
      FadeInRight(140, 8, 8,15);                                             
    } 
    if(milisecond >= 25429 && milisecond < 25629) {
      FadeOutLeft(140, 8, 8,15);
      FadeOutCenter(140, 8, 8,15);
      FadeOutRight(140, 8, 8,15);                                          
    }
    if(milisecond >= 26329 && milisecond < 26529) {
      FadeInRight(140, 8, 8,15);
      FadeInCenter(140, 8, 8,15);                                            
      FadeInLeft(140, 8, 8,15);
    } 
    if(milisecond >= 27229 && milisecond < 27429) {
      FadeOutRight(140, 8, 8,15);                                             
      FadeOutCenter(140, 8, 8,15);
      FadeOutLeft(140, 8, 8,15);
    }
    if(milisecond >= 28129 && milisecond < 28329) {
      FadeIn_NHA(3, 166, 74,12);                                            
    } 
    if(milisecond >= 29429 && milisecond < 29629) {
      FadeOut_NHA(3, 166, 74,12);                                           
    }
    //
    if(milisecond >= 30029 && milisecond < 30729) {
      customSetLED(84,104, 138, 88, 27);
      FastLED.show();                                    
    } 
    if(milisecond >= 30929 && milisecond < 31629) {
      customSetLED(37, 60, 217, 13, 30);
      customSetLED(208,230, 14, 47, 115);
      FastLED.show();                                             
    } 
    if(milisecond >= 31829 && milisecond < 32529) {
      customSetLED(27, 37, 247, 148, 126);
      customSetLED(120,141, 247, 148, 126); 
      customSetLED(199,208, 247, 148, 126); 
      customSetLED(230,252, 247, 148, 126); 
      FastLED.show();                                             
    } 
    if(milisecond >= 32729 && milisecond < 33429) {
      customSetLED(104,120, 94, 165, 141); 
      customSetLED(141,157, 94, 165, 141);
      customSetLED(0,27, 94, 165, 141); 
      customSetLED(60,84, 94, 165, 141); 
      customSetLED(157,199, 94, 165, 141);       
      FastLED.show();                                             
    } 
    if(milisecond >= 33629 && milisecond < 34329) {
      customSetLED(252,393, 255, 223, 114);                                                    
      FastLED.show();                                            
    }
    if(milisecond >= 34529 && milisecond < 34679) {
      customSetLED(393,491,149, 10, 199);                                                    
      FastLED.show();                                                 
    }
    if(milisecond >= 34979 && milisecond < 35079) {
      //                                                                                         
    } 
    //     
    if(milisecond >= 35429 && milisecond < 35879) {
      SnowSparkle(10,10,10, 255, 255, 255, 5, 20);                                                                                     
    }  
    if(milisecond >= 35879 && milisecond < 35879) {
      SnowSparkle(10,10,10, 255, 255, 255, 5, 20);                                                                                               
    }  
    if(milisecond >= 35879 && milisecond < 36779) {
      SnowSparkle(10,10,10, 255, 255, 255, 5, 20);                                                                                             
    }  
    if(milisecond >= 36779 && milisecond < 37229) {
      SnowSparkle(10,10,10, 255, 255, 255, 5, 20);   
    }  
    if(milisecond >= 37229 && milisecond < 37679) {
      SnowSparkle(10,10,10, 255, 255, 255, 5, 20);                                               
    }  
    if(milisecond >= 37679 && milisecond < 38010) {
      SnowSparkle(10,10,10, 255, 255, 255, 5, 20);                                           
    }
    if(milisecond >= 38400 && milisecond < 38737) {
      setAll(0,0,0);                                              
    }
    //đoạn dồn dập    
    if(milisecond >= 38937 && milisecond < 40444) {
      xenke(tong, 0, 252, 114, 3, 177, 252, 50);                                        
    } 
    // tinh tinh
    if(milisecond >= 40444 && milisecond < 41100) {
      setAll(0,0,0);                                       
    }
    if(milisecond >= 41200 && milisecond < 41300) {
                                                                                              
    }  
    if(milisecond >= 41500 && milisecond < 41600) {
      customSetLED(0,491, 255, 211, 147);
      FastLED.show();                                          
    }
  //doan 3
    if(milisecond >= 41800 && milisecond < 42000) {
      setAll(0,0,0);                                                                        
    }     
    if(milisecond >= 42177 && milisecond < 43977) {
      luon(250,250, 250);                                                                        
    } 
    if(milisecond >= 43977 && milisecond < 45777) {
      luon(250,250, 250);
    }
    if(milisecond >= 45777 && milisecond < 47577) {
      luon(250,250, 250);                                                                                   
    }
    if(milisecond >= 47577 && milisecond < 49377) {
      luon(250,250, 250);
    }
//
    if(milisecond >= 49377 && milisecond < 52977) {
      RunningLights(149, 10, 199, 10);                                                                                      
    }
    if(milisecond >= 52977 && milisecond < 57000) {
      RunningLights(245, 150, 27, 10);                                                                                           
    }
    if(milisecond >= 58000 && milisecond < 58200) {
      setAll(0,0,0);                                                                                            
    }    
    if(milisecond >= 58749 && milisecond < 59649) {
      // cham than
      customSetLED(252,491, 100,0,0);
      FastLED.show();   
      delay(50); 
      setAll(0,0,0);                                                                                                
    }
    if(milisecond >= 60177 && milisecond < 63777) {
      RunningLights(24, 171, 102, 10);                                                                                            
    }
    if(milisecond >= 65000 && milisecond < 65690) {
     setAll(0,0,0);
     //gian cuoi                                                                                         
    }
    if(milisecond >= 68000 && milisecond < 68100) {
      FadeInOut(83, 182, 255, 2);                                                                             
    }    
        
// Nhạc 2
    if(milisecond >= 71835 && milisecond < 73480) {
    //gian cuoi                                                                                                                                                                
    }
    if(milisecond >= 73480 && milisecond < 73581) {
      FadeIn_All(100,255,150,5, 1);                                                                                                                                                                                                         
    }
    if(milisecond >= 75281 && milisecond < 75381) {
      FadeIn_All(138, 88, 27,5, 2);                                                                                                                                                                                                           
    }
    if(milisecond >= 77081 && milisecond < 77181) {
      FadeIn_All(217, 13, 30,5, 3);                                                                                                                                                                                                           
    }
    if(milisecond >= 78881 && milisecond < 78981) {
      FadeIn_All(14, 47, 115,5, 4);                                                                                                                                                                                                          
    }
    if(milisecond >= 80681 && milisecond < 80781) {
      FadeIn_All(247, 148, 126,5, 5);                                                                                                                                                                                                          
    }
    if(milisecond >= 82481 && milisecond < 82581) {
      FadeIn_All(94, 165, 141,5, 6);                                                                                                                                                                                                           
    }
    if(milisecond >= 84281 && milisecond < 84381) {
      FadeIn_All(94, 165, 141,5, 7);                                                                                                                                                                                                           
    }
    if(milisecond >= 86081 && milisecond < 86181) {
      FadeIn_All(3, 166, 74,5, 8);                                                                                                                                                                                                          
    }    
    // Next
    if(milisecond >= 88399 && milisecond < 92164) {
      uint16_t sinBeat = beatsin16(60, 0, tong - 1, 0, 0);
      leds[sinBeat] = CRGB(0,0,200);
      fadeToBlackBy(leds, tong, 10);
      FastLED.show();                                                                                                                                                                                                                                                    
    }
    if(milisecond >= 92164 && milisecond < 95929) {
      uint16_t sinBeat = beatsin16(60, 0, tong - 1, 0, 0);
      leds[sinBeat] = CRGB(149, 10, 199);
      fadeToBlackBy(leds, tong, 10);
      FastLED.show();                                                                                                                                                  
    }
    if(milisecond >= 95929 && milisecond < 99694) {
      uint16_t sinBeat = beatsin16(60, 0, tong - 1, 0, 0);
      leds[sinBeat] = CRGB(245, 150, 27);
      fadeToBlackBy(leds, tong, 10);
      FastLED.show();                                                                                                                                                                                                                                                     
    }
    if(milisecond >= 99694 && milisecond < 103595) {
      uint16_t sinBeat = beatsin16(60, 0, tong - 1, 0, 0);
      leds[sinBeat] = CRGB(24, 171, 102);
      fadeToBlackBy(leds, tong, 10);
      FastLED.show();                                                                                                                                                                                                                                                     
    }

    //xap don dap
    if(milisecond >= 103695 && milisecond < 105195) {
      FadeInOut(random(0, 255), random(0, 255), random(0, 255), 30);                                                                                                                                                                                                                                                      
    }
    if(milisecond >= 105195 && milisecond < 106995) {
      FadeInOut(random(0, 255), random(0, 255), random(0, 255), 30);                                                                                                                                                                                                                                                      
    }
    if(milisecond >= 106995 && milisecond < 108795) {
      FadeInOut(random(0, 255), random(0, 255), random(0, 255), 30);                                                                                                                                                                                                                                                      
    }
    if(milisecond >= 108795 && milisecond < 111500) {
      FadeInOut(random(0, 255), random(0, 255), random(0, 255), 30);                                                                                                                                                                                                                                                      
    }
    if(milisecond >= 111400 && milisecond < 115387) {
      rainbowDot();                                                                                                                                                                                                                                                    
    }
    if(milisecond >= 115787 && milisecond < 117395) {
      xenke(tong, 255, 74, 74, 255, 189, 189, 50);                                                                                                                                                                                                                                                       
    }
    // Drop
    if(milisecond >= 117395 && milisecond < 118030) {
      setAll(0,0,0);                                                                                                                                                                                                                                                                                                    
    }   
    if(milisecond >= 119930 && milisecond < 120130) {
      FadeInLeft(242, 0, 0,25);
      FadeInCenter(242, 0, 0,25);
      FadeInRight(242, 0, 0,25); 
      customSetLED(252,491, 242, 0, 0); 
      FastLED.show();                                                                                                                                                                                                                                                                                                      
    }
    if(milisecond >= 121815 && milisecond < 122015) {
      FadeOutLeft(242, 0, 0,25);
      FadeOutCenter(242, 0, 0,25);
      FadeOutRight(242, 0, 0,25); 
      customSetLED(252,491, 0, 0, 0); 
      FastLED.show();                                                                                                                                                                                                                                                                                                    
    }
    if(milisecond >= 123700 && milisecond < 123900) {
      FadeInRight(0, 176, 0,25);                                                                                                                                                                                                                                                                                                      
      FadeInCenter(0, 176, 0,25);
      FadeInLeft(0, 176, 0,25);
      customSetLED(252,491, 0, 176, 0); 
      FastLED.show();
    }
    if(milisecond >= 125585 && milisecond < 125785) {
      FadeOutRight(0, 176, 0,25);                                                                                                                                                                                                                                                                                                     
      FadeOutCenter(0, 176, 0,25);
      FadeOutLeft(0, 176, 0,25);
      customSetLED(252,491, 0, 0, 0); 
      FastLED.show();
    }
    if(milisecond >= 127470 && milisecond < 127670) {
      FadeInLeft(255, 255, 0,25);
      FadeInCenter(255, 255, 0,25);
      FadeInRight(255, 255, 0,25);  
      customSetLED(252,491, 255, 255, 0); 
      FastLED.show();                                                                                                                                                                                                                                                                                                   
    }
    if(milisecond >= 129355 && milisecond < 129555) {
      FadeOutLeft(255, 255, 0,25);                                                                                                                                                                                                                                                                                                     
      FadeOutCenter(255, 255, 0,25);
      FadeOutRight(255, 255, 0,25); 
      customSetLED(252,491, 0, 0, 0); 
      FastLED.show();                                                                                                                                                                                                                                                                                                     
    }
    if(milisecond >= 131240 && milisecond < 131440) {
      FadeInRight(0, 153, 221,25);                                                                                                                                                                                                                                                                                                      
      FadeInCenter(0, 153, 221,25);
      FadeInLeft(0, 153, 221,25);
      customSetLED(252,491,0, 153, 221); 
      FastLED.show();
    }
    if(milisecond >= 133125 && milisecond < 133325) {
      FadeOutRight(0, 153, 221,25);                                                                                                                                                                                                                                                                                                     
      FadeOutCenter(0, 153, 221,25);
      FadeOutLeft(0, 153, 221,25); 
      customSetLED(252,491, 0, 0, 0); 
      FastLED.show();                                                                                                                                                                                                                                                                                                     
    }

    // Drop 2
    if(milisecond >= 134810 && milisecond < 142218) {
      uint16_t beatA = beatsin16(30, 0, 255);
      uint16_t beatB = beatsin16(20, 0, 255);
      fill_palette(leds, tong, (beatA + beatB) / 2, 10, orangePink, 255, LINEARBLEND);

      FastLED.show();                                                                                                                                                                                                                                                                                                                                         
    }
    if(milisecond >= 142218 && milisecond < 150622) {
      uint16_t beatA = beatsin16(30, 0, 255);
      uint16_t beatB = beatsin16(20, 0, 255);
      fill_palette(leds, tong, (beatA + beatB) / 2, 10, redPink, 255, LINEARBLEND);

      FastLED.show();                                                                                                                                                                                                                                                              
    }
    if(milisecond >= 150622) {
      TwinkleRandom(tong, 20, false);                                                                                                                                                                                                                                                                                                             
    }        
  }   
}
