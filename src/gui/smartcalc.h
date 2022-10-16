#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QWidget>

class QPushButton;
class QLineEdit;

class Smartcalc : public QWidget {
  Q_OBJECT

  public:
    Smartcalc(QWidget *parent = 0); // Constructor
    ~Smartcalc(); // Destructor

  private:
    QPushButton *button0_, *button1_, *button2_, *button3_, *button4_,
                *button5_, *button6_, *button7_, *button8_, *button9_;

    QPushButton *buttonBspc_;
    QPushButton *buttonAc_;

    QPushButton *buttonPoint_;
    QPushButton *buttonLbracket_;
    QPushButton *buttonRbracket_;

    QPushButton *buttonDiv_;
    QPushButton *buttonMult_;
    QPushButton *buttonMinus_;
    QPushButton *buttonPlus_;
    QPushButton *buttonMod_;
    QPushButton *buttonPow_;
    QPushButton *buttonEqual_;

    QPushButton *buttonSin_;
    QPushButton *buttonCos_;
    QPushButton *buttonTan_;
    QPushButton *buttonAsin_;
    QPushButton *buttonAcos_;
    QPushButton *buttonAtan_;
    QPushButton *buttonLn_;
    QPushButton *buttonLog_;
    QPushButton *buttonSqrt_;

    
    QLineEdit *lineEdit_;
};

#endif // SMARTCALC_H
