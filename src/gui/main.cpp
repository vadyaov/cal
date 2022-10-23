#include <QApplication>

#include "smartcalc.h"

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  Smartcalc calc;
  calc.resize(750, 500);
  calc.show();
  return a.exec();
}
