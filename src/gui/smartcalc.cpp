#include <QtWidgets>
#include "smartcalc.h"

// Constructor for main widget
Smartcalc::Smartcalc(QWidget *parent) :
    QWidget(parent) {
  
  button0_ = new QPushButton(tr("0"));
  button1_ = new QPushButton(tr("1"));
  button2_ = new QPushButton(tr("2"));
  button3_ = new QPushButton(tr("3"));
  button4_ = new QPushButton(tr("4"));
  button5_ = new QPushButton(tr("5"));
  button6_ = new QPushButton(tr("6"));
  button7_ = new QPushButton(tr("7"));
  button8_ = new QPushButton(tr("8"));
  button9_ = new QPushButton(tr("9"));

  buttonBspc_ = new QPushButton(tr("<-"));
  buttonAc_ = new QPushButton(tr("AC"));

  buttonPoint_ = new QPushButton(tr("."));
  buttonLbracket_ = new QPushButton(tr("("));
  buttonRbracket_ = new QPushButton(tr(")"));

  lineEdit_ = new QLineEdit();

  buttonDiv_ = new QPushButton(tr("/"));
  buttonMult_ = new QPushButton(tr("*"));
  buttonMinus_ = new QPushButton(tr("-"));
  buttonPlus_ = new QPushButton(tr("+"));
  buttonMod_ = new QPushButton(tr("mod"));
  buttonPow_ = new QPushButton(tr("^"));
  buttonEqual_ = new QPushButton(tr("="));

  buttonSin_ = new QPushButton(tr("sin"));
  buttonCos_ = new QPushButton(tr("cos"));
  buttonTan_ = new QPushButton(tr("tan"));
  buttonAsin_ = new QPushButton(tr("asin"));
  buttonAcos_ = new QPushButton(tr("acos"));
  buttonAtan_ = new QPushButton(tr("atan"));
  buttonLn_ = new QPushButton(tr("ln"));
  buttonLog_ = new QPushButton(tr("log"));
  buttonSqrt_ = new QPushButton(tr("sqrt"));

  QGridLayout *mainLayout = new QGridLayout;
  mainLayout->addWidget(button0_, 5, 3);
  mainLayout->addWidget(button1_, 4, 3);
  mainLayout->addWidget(button2_, 4, 4);
  mainLayout->addWidget(button3_, 4, 5);
  mainLayout->addWidget(button4_, 3, 3);
  mainLayout->addWidget(button5_, 3, 4);
  mainLayout->addWidget(button6_, 3, 5);
  mainLayout->addWidget(button7_, 2, 3);
  mainLayout->addWidget(button8_, 2, 4);
  mainLayout->addWidget(button9_, 2, 5);

  mainLayout->addWidget(buttonBspc_, 0, 6);
  mainLayout->addWidget(buttonAc_, 1, 6);

  mainLayout->addWidget(buttonPoint_, 5, 4);
  mainLayout->addWidget(buttonLbracket_, 1, 3);
  mainLayout->addWidget(buttonRbracket_, 1, 4);

  mainLayout->addWidget(buttonDiv_, 2, 6);
  mainLayout->addWidget(buttonMult_, 3, 6);
  mainLayout->addWidget(buttonMinus_, 4, 6);
  mainLayout->addWidget(buttonPlus_, 5, 6);
  mainLayout->addWidget(buttonMod_, 1, 5);
  mainLayout->addWidget(buttonPow_, 1, 2);
  mainLayout->addWidget(buttonEqual_, 5, 5);

  mainLayout->addWidget(buttonSin_, 2, 1);
  mainLayout->addWidget(buttonCos_, 3, 1);
  mainLayout->addWidget(buttonTan_, 4, 1);
  mainLayout->addWidget(buttonAsin_, 2, 0);
  mainLayout->addWidget(buttonAcos_, 3, 0);
  mainLayout->addWidget(buttonAtan_, 4, 0);
  mainLayout->addWidget(buttonLn_, 2, 2);
  mainLayout->addWidget(buttonLog_, 3, 2);
  mainLayout->addWidget(buttonSqrt_, 4, 2);
  mainLayout->addWidget(lineEdit_, 0, 0, 1, 6);

  setLayout(mainLayout);
  setWindowTitle(tr("Smartcalc_v1.0"));

}

// Destructor
Smartcalc::~Smartcalc() {
  delete button0_;
  delete button1_;
  delete button2_;
  delete button3_;
  delete button4_;
  delete button5_;
  delete button6_;
  delete button7_;
  delete button8_;
  delete button9_;
  delete lineEdit_;
}
