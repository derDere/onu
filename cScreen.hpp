#ifndef _cScreen_hpp_
#define _cScreen_hpp_

class cScreen {
public:
  cScreen(int x, int y, int w, int h);
  void draw();
  void update(int x, int y, int w, int h);
private:
  int x,y,w,h;
};

#endif
