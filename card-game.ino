#include <TVout.h>
#include <fontALL.h>
#include "cardback.h"
#include "cardempty.h"
#include "cardskel.h"
#include "cardrip.h"
#include "cardsword.h"

TVout TV;
const int w = 120;
const int h = 96;

const int xoff = 30;

void setup() {
  TV.begin(NTSC,120,96);
  TV.select_font(font4x6);

  baselayout();
}

void loop() {
}

void baselayout() {
  // draw game area
  TV.draw_rect(0, 0, w - 1, h - 1, 1);

  // enemy
  TV.bitmap(xoff + 2,2,cardback);
  TV.bitmap(xoff + 22,2,cardback);
  TV.bitmap(xoff + 42,2,cardback);

  // board 
  TV.bitmap(xoff + 2,36,cardempty);
  TV.bitmap(xoff + 22,36,cardempty);
  TV.bitmap(xoff + 42,36,cardempty);
  
  // player  
  TV.bitmap(xoff + 2,70,cardskel);
  TV.print(xoff + 4, 88, "+16");

  TV.bitmap(xoff + 22,70,cardrip);
  TV.print(xoff + 24, 87, "+16");

  TV.bitmap(xoff + 42,70,cardsword);
  TV.print(xoff + 44, 87, "+16");
}