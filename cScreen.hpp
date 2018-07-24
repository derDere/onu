#ifndef _cScreen_hpp_
#define _cScreen_hpp_

#include <string>

class cScreen {
public:
  cScreen(int x, int y, int w, int h, int focused_color, int normal_color);
  ~cScreen();
  virtual void draw(bool force = false);
  void update(int x, int y, int w, int h);
  bool focus();
  void focus(bool val);
  void title(std::string new_value);
  std::string title();
  WINDOW *window();
private:
	bool focused;
  bool needs_update;
  int x,y,w,h;
  int focused_color;
  int normal_color;
protected:
  std::string Title;
  WINDOW *win;
};

#endif
