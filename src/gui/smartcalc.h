#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QPainterPath>
#include <QWidget>
#include <QDate>
#include <QDateEdit>

#include "qcustomplot.h"

extern "C" {
#include "../calclogic/calc.h"
#include "../calclogic/credit.h"
#include "../calclogic/deposit.h"
}
/*
class QGridLayout;
class QPushButton;
class QLineEdit;
class QRadioButton;
class QLabel;
class QFont;
class QString;
class QCustomPlot;
class QStyle;
class QPixmap;
class QTabWidget;
class QDate;
class QDateEdit;
*/
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

  /* MainCalc Widgets */

  QPushButton *button0_, *button1_, *button2_, *button3_, *button4_, *button5_,
      *button6_, *button7_, *button8_, *button9_, *buttonBspc_, *buttonAc_,
      *buttonX_, *buttonPoint_, *buttonLbracket_, *buttonRbracket_, *buttonDiv_,
      *buttonMult_, *buttonMinus_, *buttonPlus_, *buttonMod_, *buttonPow_,
      *buttonEqual_, *buttonSin_, *buttonCos_, *buttonTan_, *buttonAsin_,
      *buttonAcos_, *buttonAtan_, *buttonLn_, *buttonLog_, *buttonSqrt_,
      *Mudro_;

  QLineEdit *lineEditMain_, *lineEditX_, *leftBorderLine_, *rightBorderLine_,
      *stepLine_, *yMinLine_, *yMaxLine_;

  QLabel *xValue_, *leftBorder_, *rightBorder_, *step_, *yMin, *yMax, *wiseTree_;

  QCustomPlot *customPlot;

  QRadioButton *graphButton_;

  double result;
  info xinfo;

  /* CreditCalc Widgets */

  QRadioButton *annulling_, *differ_;

  QLabel *creditSum_, *creditTime_, *interestRate_, *paymentType_;

  QLineEdit *sumLine_, *yearLine_, *monthLine_, *percentLine_;

  QTextEdit *outputInf_;

  QPushButton *calculate_;

  /* DepositCalc Widgets */

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
  void onButtonClicked();
  void onCreditCalcClicked();
  void onDepositCalcClicked();
  void createWidgets();
  void deleteBasicCalc();
  void createButtons();
  void createOther();
  void setFrames();
  void addTabs();
  void addWidgetsToLayout(QGridLayout *layout);
  void connectWidgets();
  void doEqualButton();
  void initInfo(info *data);
  void initGraph(QCustomPlot *plot);
  void printGraph(QCustomPlot *plot, const char *str);
  void customWidgets();
  void mudroFunction();

  void createCreditWidgets();
  void addCreditWidgetsToLayout(QGridLayout *layout);

  void createDepositWidgets();
  void addDepositWidgetsToLayout(QGridLayout *layout);
};

#endif  // SMARTCALC_H
