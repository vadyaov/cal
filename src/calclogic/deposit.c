#include "deposit.h"

char *depcalc(deposit *depo) {
  double per = 0.0, tax = 0.0, all = 0.0;
  if (depo->cap) {
  } else {
    per = (depo->depSum * depo->intRate * depo->depTerm) / 36500.0;
    all = depo->depSum;
    tax = per * depo->taxRate / 100.0;
  }
  printf("percents:%lf\nall:%lf\ntax:%lf\n", per, all, tax);
  return NULL;
}

void initDeposit(deposit *depo) {
  depo->depSum = 0.0;
  depo->depTerm = 0.0; 
  depo->intRate = 0.0;
  depo->taxRate = 0.0;
  depo->repSum = 0.0;
  depo->remSum = 0.0;
  depo->frequency = 0;
  depo->replanishment = 0;
  depo->withdrawals = 0;
  depo->cap = false;
}

int main() {
  deposit vklad;
  initDeposit(&vklad);
  vklad.depSum = 350000;
  vklad.depTerm = 9 * 30;
  vklad.intRate = 4.7;
  vklad.taxRate = 13.0;
  depcalc(&vklad);
  return 0;
}
