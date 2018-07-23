#ifndef _cScreenManager_hpp_
#define _cScreenManager_hpp_

#include "cScreen.hpp"

class cScreenManager {
public:
  cScreenManager(cScreen *FolderScreen, cScreen *FilesScreen, cScreen *DocumentScreen);
  bool sizeChanged();
  void updateScreens();
  void draw();
  void focus(cScreen *NewFocus);
private:
  int maxL;
  int maxC;
  cScreen *FolderScreen, *FilesScreen, *DocumentScreen;
};

#endif
