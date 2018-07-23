#ifndef _cScreen_hpp_
#define _cScreen_hpp_

#include <string>

class cScreen {
public:
  cScreen(int x, int y, int w, int h, int focused_color, int normal_color);
  ~cScreen();
  cScreen *draw(bool force = false);
  cScreen *update(int x, int y, int w, int h);
  bool focus();
  cScreen *focus(bool val);
  cScreen *title(std::string new_value);
  std::string title();
  WINDOW *window();
private:
	bool focused;
  bool needs_update;
  int x,y,w,h;
  int focused_color;
  int normal_color;
protected:
  virtual std::string Title;
  virtual WINDOW *win;
};

#endif
