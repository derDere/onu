#include <ncurses.h>
#include "cScreen.hpp"
#include <string>

cScreen::cScreen(int x, int y, int w, int h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}

void cScreen::draw() {
  addstr("Screen\n");
}

void cScreen::update(int x, int y, int w, int h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}
