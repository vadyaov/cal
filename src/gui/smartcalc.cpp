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

  lineEditMain_ = new QLineEdit();
  lineEditX_ = new QLineEdit();
  xValue_ = new QLabel(tr("x:"));

  graphButton_ = new QRadioButton("Graph", this);

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
  mainLayout->addWidget(lineEditMain_, 0, 0, 1, 6);
  mainLayout->addWidget(lineEditX_, 5, 2);
  lineEditX_->setMaximumWidth(80);
  mainLayout->addWidget(graphButton_, 5, 0);
  mainLayout->addWidget(xValue_, 5, 1);
  xValue_->setAlignment(Qt::AlignRight);
  QFont f("Arial", 14, QFont::Bold);
    xValue_->setFont(f);

  setLayout(mainLayout);
  setWindowTitle(tr("Smartcalc_v1.0"));

  connect(button0_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(button1_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(button2_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(button3_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(button4_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(button5_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(button6_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(button7_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(button8_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(button9_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonBspc_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonAc_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonPoint_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonLbracket_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonRbracket_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonDiv_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonMult_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonMinus_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonPlus_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonMod_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonPow_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonEqual_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonSin_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonCos_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonTan_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonAsin_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonAcos_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonAtan_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonLn_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonLog_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(buttonSqrt_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
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
  delete buttonBspc_;
  delete buttonAc_;
  delete buttonPoint_;
  delete buttonLbracket_;
  delete buttonRbracket_;
  delete buttonDiv_;
  delete buttonMult_;
  delete buttonMinus_;
  delete buttonPlus_;
  delete buttonMod_;
  delete buttonPow_;
  delete buttonEqual_;
  delete buttonSin_;
  delete buttonCos_;
  delete buttonTan_;
  delete buttonAsin_;
  delete buttonAcos_;
  delete buttonAtan_;
  delete buttonLn_;
  delete buttonLog_;
  delete buttonSqrt_;
  delete lineEditMain_;
  delete lineEditX_;
  delete graphButton_;
  delete xValue_;
}

void Smartcalc::onButtonClicked() {
  QObject *callingButton = QObject::sender();
  if (callingButton == button0_)
    lineEditMain_->setText(lineEditMain_->text() + "0");
  else if (callingButton == button1_)
    lineEditMain_->setText(lineEditMain_->text() + "1");
  else if (callingButton == button2_)
    lineEditMain_->setText(lineEditMain_->text() + "2");
  else if (callingButton == button3_)
    lineEditMain_->setText(lineEditMain_->text() + "3");
  else if (callingButton == button4_)
    lineEditMain_->setText(lineEditMain_->text() + "4");
  else if (callingButton == button5_)
    lineEditMain_->setText(lineEditMain_->text() + "5");
  else if (callingButton == button6_)
    lineEditMain_->setText(lineEditMain_->text() + "6");
  else if (callingButton == button7_)
    lineEditMain_->setText(lineEditMain_->text() + "7");
  else if (callingButton == button8_)
    lineEditMain_->setText(lineEditMain_->text() + "8");
  else if (callingButton == button9_)
    lineEditMain_->setText(lineEditMain_->text() + "9");
  //else if (callingButton == buttonBspc_)

  //else if (callingButton == buttonAc_)

  else if (callingButton == buttonPoint_)
    lineEditMain_->setText(lineEditMain_->text() + ".");
  else if (callingButton == buttonLbracket_)
    lineEditMain_->setText(lineEditMain_->text() + "(");
  else if (callingButton == buttonRbracket_)
    lineEditMain_->setText(lineEditMain_->text() + ")");
  else if (callingButton == buttonDiv_)
    lineEditMain_->setText(lineEditMain_->text() + "/");
  else if (callingButton == buttonMult_)
    lineEditMain_->setText(lineEditMain_->text() + "*");
  else if (callingButton == buttonMinus_)
    lineEditMain_->setText(lineEditMain_->text() + "-");
  else if (callingButton == buttonPlus_)
    lineEditMain_->setText(lineEditMain_->text() + "+");
  else if (callingButton == buttonMod_)
    lineEditMain_->setText(lineEditMain_->text() + "mod");
  else if (callingButton == buttonPow_)
    lineEditMain_->setText(lineEditMain_->text() + "^");
  //else if (callingButton == buttonEqual_)

  else if (callingButton == buttonSin_)
    lineEditMain_->setText(lineEditMain_->text() + "sin(");
  else if (callingButton == buttonCos_)
    lineEditMain_->setText(lineEditMain_->text() + "cos(");
  else if (callingButton == buttonTan_)
    lineEditMain_->setText(lineEditMain_->text() + "tan(");
  else if (callingButton == buttonAsin_)
    lineEditMain_->setText(lineEditMain_->text() + "asin(");
  else if (callingButton == buttonAcos_)
    lineEditMain_->setText(lineEditMain_->text() + "acos(");
  else if (callingButton == buttonAtan_)
    lineEditMain_->setText(lineEditMain_->text() + "atan(");
  else if (callingButton == buttonLn_)
    lineEditMain_->setText(lineEditMain_->text() + "ln(");
  else if (callingButton == buttonLog_)
    lineEditMain_->setText(lineEditMain_->text() + "log(");
  else if (callingButton == buttonSqrt_)
    lineEditMain_->setText(lineEditMain_->text() + "sqrt(");
}
