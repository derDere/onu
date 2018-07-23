#ifndef _cFolderScreen_hpp_
#define _cFolderScreen_hpp_

#include <string>
#include "cScreen.hpp"

class cFolderScreen: public cScreen {
public:
  cFolderScreen(int focused_color, int normal_color);
  ~cFolderScreen();
private:
  int Folders;
};

#endif
