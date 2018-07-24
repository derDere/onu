#include <ncurses.h>
#include "cScreen.hpp"
#include <string>

cScreen::cScreen(int x, int y, int w, int h, int focused_color, int normal_color) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->focused_color = focused_color;
  this->normal_color = normal_color;
  this->win = newwin(y,x,h,w);
  keypad(this->win,true);
  this->Title = "";
  this->needs_update = true;
}

cScreen::~cScreen() {
  delwin(this->win);
}

void cScreen::title(std::string new_value) {
  if (new_value != this->Title) this->needs_update = true;
  this->Title = new_value;
}

std::string cScreen::title() {
  return this->Title;
}

void cScreen::focus(bool val) {
	this->focused = val;
}

bool cScreen::focus() {
	return this->focused;
}

WINDOW *cScreen::window() {
  return this->win;
}

void cScreen::draw(bool force) {
  if (this->needs_update || force) {
  	box(this->win,0,0);
  	if(this->focused) {
  			wattron(this->win,COLOR_PAIR(this->focused_color));
  			for (int i = 0; i < this->w; ++i)
  			{
  				char c = ' ';
  				if (((i-1) < this->Title.size())&&i>0) c = this->Title[i-1];
  				mvwaddch(this->win,0,i,c);
  			}
  			wattroff(this->win,COLOR_PAIR(this->focused_color));
  	}
  	else {
    	mvwaddstr(this->win,0,1,this->Title.c_str());
  	}
    wrefresh(this->win);
  }
}

void cScreen::update(int x, int y, int w, int h) {
  if ((this->x!=x)||(this->y!=y)||(this->w!=w)||(this->h!=h)) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    mvwin(this->win,y,x);
    wresize(this->win,h,w);
    this->needs_update = true;
  }
}
