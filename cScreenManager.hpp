#ifndef _cScreenManager_hpp_
#define _cScreenManager_hpp_

class cScreenManager {
public:
  cScreenManager();
  bool sizeChanged();
  void updateScreens();
  void print();
  void hr();
private:
  int maxL;
  int maxC;
};

#endif
