#include <QApplication>

#include "smartcalc.h"

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  Smartcalc calc;
  calc.setMinimumWidth(620);
  calc.setMinimumHeight(660);
  calc.setMaximumWidth(620);
  calc.setMaximumHeight(660);
  calc.show();
  return a.exec();
}
