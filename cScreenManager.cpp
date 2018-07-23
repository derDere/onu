#include <ncurses.h>
#include "cScreenManager.hpp"
#include "cScreen.hpp"
#include <string>

cScreenManager::cScreenManager(cScreen *FolderScreen, cScreen *FilesScreen, cScreen *DocumentScreen) {
  this->FolderScreen = FolderScreen;
  this->FilesScreen = FilesScreen;
  this->DocumentScreen = DocumentScreen;
  this->maxC = -1;
  this->maxL = -1;
}

void cScreenManager::draw() {
  refresh();
  this->FolderScreen->draw();
  this->FilesScreen->draw();
  this->DocumentScreen->draw();
}

cScreen *cScreenManager::focus() {
  return this->CurrentFocus;
}

void cScreenManager::focus(cScreen *NewFocus) {
  this->FolderScreen->focus(this->FolderScreen==NewFocus);
  this->FilesScreen->focus(this->FilesScreen==NewFocus);
  this->DocumentScreen->focus(this->DocumentScreen==NewFocus);
  CurrentFocus = NewFocus;
}

bool cScreenManager::sizeChanged() {
  int l, c;
  getmaxyx(stdscr, l, c);
  if ((this->maxC != c) || (this->maxL != l)) {
    this->maxC = c;
    this->maxL = l;
    return true;
  }
  return false;
}

void cScreenManager::updateScreens() {
  int w3 = (int)(this->maxC*0.3);
  int w4 = (int)(this->maxC*0.4);
  this->FolderScreen->update(0,0,w3,this->maxL);
  this->FilesScreen->update(w3,0,w3,this->maxL);
  this->DocumentScreen->update(w3+w3,0,w4,this->maxL);
}
