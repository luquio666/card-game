#include <TVout.h>
#include <fontALL.h>
#include "cards.h"
#include "Vector2.h"

TVout TV;
const int w = 120;
const int h = 96;

const int xoff = 30;

Vector2 pos[] = {
    Vector2(2, 2),   Vector2(22, 2),  Vector2(42, 2),
    Vector2(2, 36),  Vector2(22, 36), Vector2(42, 36),
    Vector2(2, 70),  Vector2(22, 70), Vector2(42, 70)
};

void setup() {
  TV.begin(NTSC,120,96);
  TV.select_font(font4x6);

  baselayout();
  
  game();
  
  draw_card_numbers();
}

void loop() {
    //move_card(pos[8], pos[4], card1, "+9");
    //delay(1000);
}

void game() {
  draw_card(cardback, pos[0], "");
  draw_card(cardempty, pos[1], "");
  draw_card(cardback, pos[2], "");

  draw_card(card7, pos[3], "+10");
  draw_card(card5, pos[4], "+3");
  draw_card(cardempty, pos[5], "");

  draw_card(card4, pos[6], "+9");
  draw_card(card7, pos[7], "+9");
  draw_card(cardempty, pos[8], "");
  
}

void draw_card_numbers()
{
  TV.print(39, 27, "1");
  TV.print(59, 27, "2");
  TV.print(79, 27, "3");

  TV.print(39, 64, "4");
  TV.print(59, 64, "5");
  TV.print(79, 64, "6");
}

void baselayout() {
  //TV.clear_screen(); 

  // screen limit
  TV.draw_rect(0, 0, w - 1, h - 1, 1);

  // player ui
  TV.draw_line(28, 0, 28,h-1, 1);
  TV.draw_line(0, 10, 28,10, 1);
  // player stats
  TV.print(3, 3, "Player");  
  TV.print(3, 14, "LV. 13");
  TV.print(3, 22, "HP. 45");
  TV.print(3, 30, "ATK 10");
  TV.print(3, 38, "DEF 00");
  TV.print(3, 46, "LUK 01");

  // cpu ui
  TV.draw_line(w-28-1, 0, w-28-1,h-1, 1);
  TV.draw_line(w-28-1, 10, w, 10, 1);
  // cpu stats
  TV.print(w-20, 3, "CPU");
  TV.print(w-26, 14, "LV. 08");
  TV.print(w-26, 22, "HP. 21");
  TV.print(w-26, 30, "ATK 15");
  TV.print(w-26, 38, "DEF 03");
  TV.print(w-26, 46, "LUK 09");
}

void draw_card(unsigned char *card, Vector2 pos, const char *s) {
    TV.bitmap(xoff + pos.x, pos.y, card);
    TV.print(xoff + pos.x + 2, pos.y + 17, s);
}

void move_card(Vector2 pos1, Vector2 pos2, unsigned char *card, const char *s) {
    const int steps = 2;
    for (int i = 0; i <= steps; i++) {
        float t = float(i) / steps;
        Vector2 current = pos1.interpolate(pos2, t);
        baselayout();
        draw_card(card, current, s);
        delay(50);
    }
    draw_card(card, pos2, s);
}