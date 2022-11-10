#include <QApplication>

#include "smartcalc.h"

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  Smartcalc calc;
#if defined(__APPLE__) && defined(__MACH__)
  calc.setMinimumWidth(650);
  calc.setMinimumHeight(720);
  calc.setMaximumWidth(650);
  calc.setMaximumHeight(720);
#else
  calc.setMinimumWidth(620);
  calc.setMinimumHeight(740);
  calc.setMaximumWidth(620);
  calc.setMaximumHeight(740);
#endif
  calc.show();
  return a.exec();
}
