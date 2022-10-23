#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QWidget>
#include <QPainterPath>
#include "qcustomplot.h"

extern "C" {
  #include "../calclogic/calc.h"
}

class QGridLayout;
class QPushButton;
class QLineEdit;
class QRadioButton;
class QLabel;
class QFont;
class QString;
class QCustomPlot;

class Smartcalc : public QWidget {
  Q_OBJECT

  public:
    Smartcalc(QWidget *parent = 0); // Constructor
    ~Smartcalc(); // Destructor

  private:
    QPushButton *button0_, *button1_, *button2_, *button3_, *button4_,
                *button5_, *button6_, *button7_, *button8_, *button9_,
                *buttonBspc_, *buttonAc_, *buttonX_,
                *buttonPoint_, *buttonLbracket_, *buttonRbracket_,
                *buttonDiv_, *buttonMult_, *buttonMinus_, *buttonPlus_,
                *buttonMod_, *buttonPow_, *buttonEqual_, *buttonSin_,
                *buttonCos_, *buttonTan_, *buttonAsin_, *buttonAcos_,
                *buttonAtan_, *buttonLn_, *buttonLog_, *buttonSqrt_;

    QLineEdit *lineEditMain_, *lineEditX_, *leftBorderLine_, *rightBorderLine_,
              *stepLine_;
    QRadioButton *graphButton_;
    QLabel *xValue_, *leftBorder_, *rightBorder_, *step_;

    QCustomPlot *customPlot;

    double result;
    info xinfo;

  private slots:
    void onButtonClicked();
    void createWidgets();
    void addWidgetsToLayout(QGridLayout *layout);
    void connectWidgets();
    void initInfo(info *data);
    void initGraph(QCustomPlot *plot);
    void printGraph(QCustomPlot *plot, const char *str);
};

#endif // SMARTCALC_H
