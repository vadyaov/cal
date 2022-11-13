#ifndef _SRC_GUI_SMARTCALC_H
#define _SRC_GUI_SMARTCALC_H

#include "qcustomplot.h"

extern "C" {
#include "../calclogic/calc.h"
#include "../calclogic/credit.h"
#include "../calclogic/deposit.h"
}

#define YMIN -1000000.0
#define YMAX 1000000.0

class Smartcalc : public QWidget {
  Q_OBJECT

 public:
  Smartcalc(QWidget *parent = 0);
  ~Smartcalc();

 private:
  QTabWidget *calcWidget;
  QFrame *frame1, *frame2, *frame3;
  QGridLayout *mainLayout, *creditLayout, *depositLayout;

  /* -------------------------MainCalc Widgets---------------------------*/

  QPushButton *button0_, *button1_, *button2_, *button3_, *button4_, *button5_,
      *button6_, *button7_, *button8_, *button9_, *buttonBspc_, *buttonAc_,
      *buttonX_, *buttonPoint_, *buttonLbracket_, *buttonRbracket_, *buttonDiv_,
      *buttonMult_, *buttonMinus_, *buttonPlus_, *buttonMod_, *buttonPow_,
      *buttonEqual_, *buttonSin_, *buttonCos_, *buttonTan_, *buttonAsin_,
      *buttonAcos_, *buttonAtan_, *buttonLn_, *buttonLog_, *buttonSqrt_,
      *Mudro_;
  QLineEdit *lineEditMain_, *lineEditX_, *leftBorderLine_, *rightBorderLine_,
      *stepLine_, *yMinLine_, *yMaxLine_;
  QLabel *xValue_, *leftBorder_, *rightBorder_, *step_, *yMin, *yMax,
      *wiseTree_;
  QCustomPlot *customPlot;
  QRadioButton *graphButton_;

  /* -----------------------CreditCalc Widgets---------------------------*/

  QRadioButton *annulling_, *differ_;
  QLabel *creditSum_, *creditTime_, *interestRate_, *paymentType_, *stonks_;
  QLineEdit *sumLine_, *yearLine_, *monthLine_, *percentLine_;
  QTextEdit *outputInf_;
  QPushButton *calculate_, *stonksButton_;
  QHBoxLayout *memLayout_;

  /* -----------------------DepositCalc Widgets--------------------------*/

  QLabel *depositSum_, *depositTime_, *depInterestRate_, *depTaxRate_,
      *payFrequency_, *addToDep_, *addSum_, *removeFromDep_, *removeSum_;
  QLineEdit *depSumLine_, *depPercentLine_, *depTaxRateLine_, *addSumLine_,
      *removeSumLine_;
  QTextEdit *outDepInf_;
  QRadioButton *capitalization_;
  QComboBox *payFreq_, *addDep_, *removeDep_;
  QPushButton *calcDep_;
  QDateEdit *startDay_, *endDay_;
  QHBoxLayout *dateLayout_;

 private slots:
  /* -------------------------MainCalc Slots---------------------------*/

  void onButtonClicked();
  void createWidgets();
  void createButtons();
  void createOther();
  void setFrames();
  void addTabs();
  void addWidgetsToLayout(QGridLayout *layout);
  void doEqualButton();
  void initGraph(QCustomPlot *plot);
  void printGraph(QCustomPlot *plot, const char *str, info *xinfo);
  void setMainCalcAlignments();
  void setMainCalcWidths();
  void setMainCalcSkins();
  void setMainCalcTexts();
  void mainCalcCustom();
  void mudroFunction();
  void connectWidgets();
  void customWidgets();
  void deleteBasicCalc();

  /* -----------------------CreditCalc Slots---------------------------*/

  void creditCalcCustom();
  void createCreditWidgets();
  void addCreditWidgetsToLayout(QGridLayout *layout);
  void onCreditCalcClicked();
  void stonksButtonClicked();
  void deleteCreditCalc();

  /* -----------------------DepositCalc Slots--------------------------*/

  void createDepositWidgets();
  void addDepositWidgetsToLayout(QGridLayout *layout);
  void setBoxItems();
  void depositCalcCustom();
  void onDepositCalcClicked();
  void deleteDepositCalc();
};

#endif /*  _SRC_GUI_SMARTCALC_H */
