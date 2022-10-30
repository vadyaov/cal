#include "smartcalc.h"

#include <QtWidgets>

// Constructor for main widget
Smartcalc::Smartcalc(QWidget *parent) : QWidget(parent) {
  createWidgets();
  createCreditWidgets();
  initGraph(customPlot);
  addWidgetsToLayout(mainLayout);
  addCreditWidgetsToLayout(creditLayout);
  frame1->setLayout(mainLayout);
  frame2->setLayout(creditLayout);
  connectWidgets();
  customWidgets();
  monthLine_->setPlaceholderText(QString("months"));
  yearLine_->setPlaceholderText(QString("years"));
  percentLine_->setPlaceholderText(QString("%"));
  sumLine_->setPlaceholderText(QString("$"));
  calcWidget->addTab(frame1, "calc");
  calcWidget->addTab(frame2, "credit");
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
  delete buttonBspc_;
  delete buttonAc_;
  delete buttonX_;
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
  delete customPlot;
  delete leftBorder_;
  delete rightBorder_;
  delete step_;
  delete leftBorderLine_;
  delete rightBorderLine_;
  delete stepLine_;
  delete Mudro_;
  delete wiseTree_;
  delete mainLayout;
  delete creditLayout;
  delete annulling_;
  delete differ_;
  delete creditSum_;
  delete creditTime_;
  delete interestRate_;
  delete paymentType_;
  delete sumLine_;
  delete yearLine_;
  delete monthLine_;
  delete percentLine_;
  delete frame1;
  delete frame2;
  delete calcWidget;
}

void Smartcalc::createWidgets() {
  frame1 = new QFrame(this);
  frame2 = new QFrame(this);
  mainLayout = new QGridLayout(frame1);
  creditLayout = new QGridLayout(frame2);
  calcWidget = new QTabWidget(this);
  createButtons();
  createOther();
}

void Smartcalc::createButtons() {
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
  buttonBspc_ = new QPushButton();
  buttonAc_ = new QPushButton(tr("AC"));
  buttonX_ = new QPushButton(tr("x"));
  buttonPoint_ = new QPushButton(tr("."));
  buttonLbracket_ = new QPushButton(tr("("));
  buttonRbracket_ = new QPushButton(tr(")"));
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
  graphButton_ = new QRadioButton("Graph", this);
  Mudro_ = new QPushButton(tr("Wise Tree"));
}

void Smartcalc::createOther() {
  lineEditMain_ = new QLineEdit();
  lineEditX_ = new QLineEdit();
  leftBorderLine_ = new QLineEdit();
  rightBorderLine_ = new QLineEdit();
  stepLine_ = new QLineEdit();
  xValue_ = new QLabel(tr("x:"));
  leftBorder_ = new QLabel(tr("from x:"));
  rightBorder_ = new QLabel(tr("to x:"));
  step_ = new QLabel(tr("Step"));
  customPlot = new QCustomPlot();
  wiseTree_ = new QLabel();
}

void Smartcalc::addWidgetsToLayout(QGridLayout *layout) {
  layout->addWidget(button0_, 5, 3);
  layout->addWidget(button1_, 4, 3);
  layout->addWidget(button2_, 4, 4);
  layout->addWidget(button3_, 4, 5);
  layout->addWidget(button4_, 3, 3);
  layout->addWidget(button5_, 3, 4);
  layout->addWidget(button6_, 3, 5);
  layout->addWidget(button7_, 2, 3);
  layout->addWidget(button8_, 2, 4);
  layout->addWidget(button9_, 2, 5);
  layout->addWidget(buttonBspc_, 0, 6);
  layout->addWidget(buttonAc_, 1, 6);
  layout->addWidget(buttonX_, 1, 1);
  layout->addWidget(buttonPoint_, 5, 4);
  layout->addWidget(buttonLbracket_, 1, 3);
  layout->addWidget(buttonRbracket_, 1, 4);
  layout->addWidget(buttonDiv_, 2, 6);
  layout->addWidget(buttonMult_, 3, 6);
  layout->addWidget(buttonMinus_, 4, 6);
  layout->addWidget(buttonPlus_, 5, 6);
  layout->addWidget(buttonMod_, 1, 5);
  layout->addWidget(buttonPow_, 1, 2);
  layout->addWidget(buttonEqual_, 5, 5);
  layout->addWidget(buttonSin_, 2, 1);
  layout->addWidget(buttonCos_, 3, 1);
  layout->addWidget(buttonTan_, 4, 1);
  layout->addWidget(buttonAsin_, 2, 0);
  layout->addWidget(buttonAcos_, 3, 0);
  layout->addWidget(buttonAtan_, 4, 0);
  layout->addWidget(buttonLn_, 2, 2);
  layout->addWidget(buttonLog_, 3, 2);
  layout->addWidget(buttonSqrt_, 4, 2);
  layout->addWidget(lineEditMain_, 0, 0, 1, 6);
  layout->addWidget(lineEditX_, 5, 2);
  layout->addWidget(graphButton_, 5, 0);
  layout->addWidget(Mudro_, 1, 0);
  layout->addWidget(xValue_, 5, 1);
  layout->addWidget(customPlot, 6, 0, 50, 6);
  layout->addWidget(leftBorder_, 6, 6);
  layout->addWidget(rightBorder_, 8, 6);
  layout->addWidget(step_, 10, 6);
  layout->addWidget(leftBorderLine_, 7, 6);
  layout->addWidget(rightBorderLine_, 9, 6);
  layout->addWidget(stepLine_, 11, 6);
}

void Smartcalc::connectWidgets() {
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
  connect(buttonX_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
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
  connect(Mudro_, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

  connect(calculate_, SIGNAL(clicked()), this, SLOT(onDepCalcClicked()));
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
  else if (callingButton == buttonBspc_)
    lineEditMain_->backspace();
  else if (callingButton == buttonAc_)
    lineEditMain_->clear();
  else if (callingButton == buttonX_)
    lineEditMain_->setText(lineEditMain_->text() + "x");
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
  else if (callingButton == buttonEqual_)
    doEqualButton();
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
  else if (callingButton == Mudro_)
    mudroFunction();
}

void Smartcalc::doEqualButton() {
  initInfo(&xinfo);
  QString mainLine = lineEditMain_->text();
  if (mainLine.isEmpty()) {
    lineEditMain_->setText("empy line");
  } else {
    char mainInput[512] = {'\0'};
    strncpy(mainInput, qPrintable(mainLine), 255);
    if (graphButton_->isChecked()) {
      printGraph(customPlot, mainInput);
    } else {
      QString xLine = lineEditX_->text();
      if (!xLine.isEmpty()) xinfo.x = lineEditX_->text().toDouble();
      result = calc(mainInput, &xinfo);
      lineEditMain_->clear();
      if (!xinfo.err)
        lineEditMain_->setText(QString::number(result, 'f', 7));
      else
        lineEditMain_->setText("error");
    }
  }
}

void Smartcalc::initInfo(info *data) {
  data->x = 0.0;
  data->err = 0;
}

void Smartcalc::initGraph(QCustomPlot *plot) {
  plot->addGraph();
  plot->graph(0)->setPen(QPen(Qt::blue));
  plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

  plot->xAxis2->setVisible(true);
  plot->xAxis2->setTickLabels(false);
  plot->yAxis2->setVisible(true);
  plot->yAxis2->setTickLabels(false);

  int pxx = plot->yAxis->coordToPixel(0);
  int pxy = plot->xAxis->coordToPixel(0);
  plot->xAxis->setOffset(-plot->axisRect()->height() - plot->axisRect()->top() +
                         pxx);
  plot->yAxis->setOffset(plot->axisRect()->left() - pxy);

  connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), plot->xAxis2,
          SLOT(setRange(QCPRange)));
  connect(plot->yAxis, SIGNAL(rangeChanged(QCPRange)), plot->yAxis2,
          SLOT(setRange(QCPRange)));

  plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                        QCP::iSelectPlottables);
}

void Smartcalc::printGraph(QCustomPlot *plot, const char *str) {
  double start = leftBorderLine_->text().toDouble(),
         end = rightBorderLine_->text().toDouble(),
         step = stepLine_->text().toDouble();
  int dots = (end - start) / step + 1;
  QVector<double> x(dots), y(dots);
  xinfo.x = start;
  for (int i = 0; i < dots; ++i) {
    x[i] = xinfo.x;
    y[i] = calc(str, &xinfo);
    if (y[i] > 1000000.0)
      y[i] = std::numeric_limits<double>::infinity();
    else if (y[i] < -1000000.0)
      y[i] = -std::numeric_limits<double>::infinity();
    //printf("x = %.16lf\ty = %.16lf\n", x[i], y[i]);
    xinfo.x += step;
    if (fabs(xinfo.x) < 1e-7) xinfo.x = 0.0;
    if (xinfo.err) {
      lineEditMain_->setText("error");
      return;
    }
  }
  plot->graph(0)->setData(x, y);
  plot->xAxis->rescale();
  plot->replot();
}

void Smartcalc::customWidgets() {
  frame1->setGeometry(0, 0, 750, 750);
  frame2->setGeometry(0, 0, 300, 300);
  xValue_->setAlignment(Qt::AlignRight);
  QFont f("Arial", 14, QFont::Bold);
  xValue_->setFont(f);
  lineEditX_->setText("0.0");
  lineEditX_->setMaximumWidth(80);
  lineEditX_->setAlignment(Qt::AlignCenter);
  leftBorderLine_->setMaximumWidth(80);
  stepLine_->setMaximumWidth(80);
  rightBorderLine_->setMaximumWidth(80);
  leftBorderLine_->setText("-50.0");
  rightBorderLine_->setText("50.0");
  stepLine_->setText("0.1");
  leftBorderLine_->setAlignment(Qt::AlignCenter);
  rightBorderLine_->setAlignment(Qt::AlignCenter);
  stepLine_->setAlignment(Qt::AlignCenter);
  lineEditMain_->setAlignment(Qt::AlignRight);
  lineEditMain_->setProperty("mandatoryField", true);
  lineEditMain_->setStyleSheet("color: black;"
                         "background-color: white;"
                         "selection-background-color: grey;");
  lineEditX_->setStyleSheet("color: black;"
                         "background-color: lightgrey;");
  QFont fontX = {"Arial", 12, QFont::Bold};
  buttonX_->setFont(fontX);
  leftBorderLine_->setStyleSheet("color: blue;"
                         "background-color: lightgrey;");
  rightBorderLine_->setStyleSheet("color: blue;"
                         "background-color: lightgrey;");
  buttonEqual_->setStyleSheet("color: black; background-color: lightBlue;");
  button0_->setStyleSheet("color: black; background-color: grey;");
  button1_->setStyleSheet("color: black; background-color: grey;");
  button2_->setStyleSheet("color: black; background-color: grey;");
  button3_->setStyleSheet("color: black; background-color: grey;");
  button4_->setStyleSheet("color: black; background-color: grey;");
  button5_->setStyleSheet("color: black; background-color: grey;");
  button6_->setStyleSheet("color: black; background-color: grey;");
  button7_->setStyleSheet("color: black; background-color: grey;");
  button8_->setStyleSheet("color: black; background-color: grey;");
  button9_->setStyleSheet("color: black; background-color: grey;");
  buttonPoint_->setStyleSheet("color: black; background-color: grey;");
  buttonBspc_->setIcon(style()->standardIcon(QStyle::SP_ArrowBack));
  wiseTree_->setStyleSheet("background-color: blue;");
}

void Smartcalc::mudroFunction() {
  QString imagePath = "index.png";
  QPixmap img(imagePath);
  wiseTree_->setMaximumWidth(80);
  wiseTree_->setPixmap(img);
  mainLayout->addWidget(wiseTree_, 12, 6, 18, 6);
}

void Smartcalc::createCreditWidgets() {
  creditSum_ = new QLabel(tr("Loan Amount"));
  creditTime_ = new QLabel(tr("Loan Term"));
  interestRate_ = new QLabel(tr("Interest Rate"));
  paymentType_ = new QLabel(tr("Compound"));

  sumLine_ = new QLineEdit();
  yearLine_ = new QLineEdit();
  monthLine_ = new QLineEdit();
  percentLine_ = new QLineEdit();

  annulling_ = new QRadioButton(tr("Annually"));
  differ_ = new QRadioButton(tr("Monthly"));

  outputInf_ = new QTextEdit();
  //outputInf_->setFixedHeight(200);

  calculate_ = new QPushButton(tr("Calculate"));
}

void Smartcalc::addCreditWidgetsToLayout(QGridLayout *layout) {
  layout->addWidget(creditSum_, 0, 0);
  layout->addWidget(creditTime_, 1, 0);
  layout->addWidget(interestRate_, 3, 0);
  layout->addWidget(paymentType_, 4, 0);

  layout->addWidget(sumLine_, 0, 1); 
  layout->addWidget(yearLine_, 1, 1); 
  layout->addWidget(monthLine_, 2, 1); 
  layout->addWidget(percentLine_, 3, 1); 

  layout->addWidget(annulling_, 4, 1); 
  layout->addWidget(differ_, 5, 1); 

  layout->addWidget(outputInf_, 7, 0, 7, 2, Qt::AlignTop);
  layout->addWidget(calculate_, 9, 0);
}

void Smartcalc::onDepCalcClicked() {
  QObject *callingCreditButton = QObject::sender();
  creditInfo inf;
  if (callingCreditButton == calculate_) {
    QString sum = sumLine_->text(), year = yearLine_->text(),
                  month = monthLine_->text(), rate = percentLine_->text();
    outputInf_->clear();
    if (sum.isEmpty()) {
      outputInf_->setText("Enter the loant amount!");
    }
    else if (year.isEmpty() && month.isEmpty()) {
      outputInf_->setText("Enter the loan period!");
    }
    else if (rate.isEmpty()) {
      outputInf_->setText("Enter the interest rate!");
    }
    else {
      initCreditInfo(&inf);
      inf.amount = sumLine_->text().toDouble();
      inf.time = yearLine_->text().toDouble() * 12.0 +
                 monthLine_->text().toDouble();
      inf.rate = percentLine_->text().toDouble();
      if (annulling_->isChecked())
        inf.type = 'a';
      else if (differ_->isChecked())
        inf.type = 'd';
      char *out = creditCalc(&inf);
      QString str = out;
      outputInf_->setText(str);
      free(out);
    }
  }
}
