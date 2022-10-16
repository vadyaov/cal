#include <QApplication>

#include "smartcalc.h"

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  Smartcalc calc;
  calc.show();
  return a.exec();
}
