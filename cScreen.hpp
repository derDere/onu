#ifndef _cScreen_hpp_
#define _cScreen_hpp_

#include <string>

class cScreen {
public:
  cScreen(int x, int y, int w, int h, int focused_color, int normal_color);
  void draw();
  void update(int x, int y, int w, int h);
  bool focus();
  void focus(bool val);
  std::string name;
private:
	bool focused;
  int x,y,w,h;
  int focused_color;
  int normal_color;
  WINDOW *win;
};

#endif
