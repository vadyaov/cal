#include <QApplication>

#include "smartcalc.h"

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  Smartcalc calc;
#if defined(__APPLE__) && defined(__MACH__)
  calc.setMinimumWidth(650);
  calc.setMinimumHeight(870);
  calc.setMaximumWidth(650);
  calc.setMaximumHeight(870);
#else
  calc.setMinimumWidth(620);
  calc.setMinimumHeight(660);
  calc.setMaximumWidth(620);
  calc.setMaximumHeight(660);
#endif
  calc.show();
  return a.exec();
}
