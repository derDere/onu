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
  this->name = "";
}

void cScreen::focus(bool val) {
	this->focused = val;
}

bool cScreen::focus() {
	return this->focused;
}

void cScreen::draw() {
	box(this->win,0,0);
	if(this->focused) {
			wattron(this->win,COLOR_PAIR(this->focused_color));
			for (int i = 0; i < this->w; ++i)
			{
				char c = ' ';
				if (((i-1) < this->name.size())&&i>0) c = this->name[i-1];
				mvwaddch(this->win,0,i,c);
			}
			wattroff(this->win,COLOR_PAIR(this->focused_color));
	}
	else {
  	mvwaddstr(this->win,0,1,this->name.c_str());
	}
  wrefresh(this->win);
}

void cScreen::update(int x, int y, int w, int h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  mvwin(this->win,y,x);
  wresize(this->win,h,w);
}
