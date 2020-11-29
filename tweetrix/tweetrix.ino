
#define PIN 13        // пин DI
#define NUM_LEDS 150   // число диодов
#include "Adafruit_NeoPixel.h"
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int rows = 15;    //rows number in led matrix
int columns = 10;  //columns number in led matrix
uint32_t color; 
uint32_t picture1[ 15 ][ 10 ] = { 
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0xffffff, 0x000000 },  
  { 0xff0000, 0x000000, 0xff0000, 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0xffffff, 0xff0000 },
  { 0xff0000, 0x000000, 0xff0000, 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0xffffff, 0xff0000 },
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0xff0000, 0xffffff, 0xff0000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xffffff, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000 },
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000 },
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 }  
  };   // array for picture


uint32_t picture[ 15 ][ 10 ] = { 
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000 },  
  { 0xff0000, 0x000000, 0xff0000, 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0x000000, 0xff0000 },
  { 0xff0000, 0x000000, 0xff0000, 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0xff0000, 0xff0000 },
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0xff0000, 0x000000, 0xff0000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0xff0000, 0xff0000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000 },
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000 },
  { 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000 },
  { 0x000000, 0x000000, 0x000000, 0x000000, 0xff0000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000 }  
  };   // array for picture






void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
 
  strip.begin();
  strip.setBrightness(20);    // яркость, от 0 до 255
  strip.clear();                          // очистить
  strip.show();                           // отправить на ленту


//start wifi TBD
//start WebClient TBD   or web client. have no idea at this point






//
//          strip.setPixelColor(1, 0x0000ff);          // paint white
//          strip.show();                                                  // send to strip
//          delay(100);          strip.setPixelColor(2, 0xff0000);          // paint white
//          strip.show();                                                  // send to strip
//          delay(100);          strip.setPixelColor(3, 0x00ff00);          // paint white
//          strip.show();                                                  // send to strip
//          delay(100);          strip.setPixelColor(0, 0xff0000);          // paint white
//          strip.show();                                                  // send to strip
//          delay(100);



//parse and print


int icursor = 0;                                                        //this cursor will incrementally slide thru the strip while main loops go thru matrix rows by colums


for (int icolumn = columns-1; icolumn>=0; icolumn--) {                       //x axis l starting from last column 

  if ((icolumn % 2) != 0) {                                                  //if column number is ODD - read columns from   BOTTOM TO TOP     
      for (int irow = rows-1; irow >=0; irow--) {                        //y axis  looping rows 
      
    
         
           
          strip.setPixelColor(icursor, 0xff00ff);     // paint white
           
          //strip.setPixelColor(icursor, picture[irow][icolumn]);          // paint white
          strip.show();                                                  // send to strip
          delay(10);
    
    
          //debug
          if ((icolumn % 2) == 0) Serial.print(" EVE ") ;
          if ((icolumn % 2) != 0)  Serial.print(" ODD "); 
          Serial.print("col: ");     Serial.print(icolumn);
          Serial.print("    row: "); Serial.print(irow);
          Serial.print("    color: "); Serial.print(picture[irow][icolumn], HEX);
          Serial.print("    curs: "); Serial.println(icursor);

           icursor++;
      }
  
    } else {                                       //if column number is EVEN - read columns from  TOP to BOTTOM    fill TOP BOTTOM
          for (int irow = 0; irow <rows; irow++){           
      
    
         
          strip.setPixelColor(icursor, 0x0000ff);     // paint white
           
          //strip.setPixelColor(icursor, picture[irow][icolumn]);     // paint white
          strip.show();                         // send to strip
          delay(10);
    
    
          //debug
          if ((icolumn % 2) == 0) Serial.print(" EVE ") ;
          if ((icolumn % 2) != 0)  Serial.print(" ODD "); 
          Serial.print("col: ");     Serial.print(icolumn);
          Serial.print("    row: "); Serial.print(irow);
          Serial.print("    color: "); Serial.print(picture[irow][icolumn], HEX);
           Serial.print("    curs: "); Serial.println(icursor);

           icursor++;
      }
    }

}



}

void loop() {


  //if changed

  // parse and print

  

  
/*examples  
  // заливаем трёмя цветами плавно
  for (int i = 0; i < NUM_LEDS / 3; i++ ) {   // от 0 до первой трети
    strip.setPixelColor(i, 0xff0000);     // залить красным
    strip.show();                         // отправить на ленту
    delay(100);
  }
  for (int i = NUM_LEDS / 3; i < NUM_LEDS * 2 / 3; i++ ) {   // от 1/3 до 2/3
    strip.setPixelColor(i, 0x00ff00);     // залить зелёным
    strip.show();                         // отправить на ленту
    delay(100);
  }
  for (int i = NUM_LEDS * 2 / 3; i < NUM_LEDS; i++ ) {   // от 2/3 до конца
    strip.setPixelColor(i, 0x0000ff);     // залить синим
    strip.show();                         // отправить на ленту
    delay(100);
  }
  delay(1000);
  // заливаем белым
  for (int i = 0; i < NUM_LEDS; i++ ) {   // всю ленту
    strip.setPixelColor(i, 0xffffff);     // залить белым
    strip.show();                         // отправить на ленту
    delay(10);
  }
  delay(1000);
  // заливаем чёрным
  for (int i = 0; i < NUM_LEDS; i++ ) {   // всю ленту
    strip.setPixelColor(i, 0x000000);     // залить чёрным
    strip.show();                         // отправить на ленту
    delay(10);
  }
  delay(1000);
  // включаем случайные диоды жёлтым
  for (int i = 0; i < 50; i++ ) {         // 50 раз
    strip.setPixelColor(random(0, NUM_LEDS), 0xffff00);     // залить жёлтым
    strip.show();                         // отправить на ленту
    delay(500);
  }
*/



}
