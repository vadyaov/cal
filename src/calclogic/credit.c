#include "credit.h"

char *creditCalc(creditInfo *input) {
  double monthPayment = 0, overPayment = 0,
         totalPayment = 0;
  printCreditStruct(input);
  if (input->type == 'a') {
    monthPayment = (input->amount * input->rate / 1200.0) / (1 - pow(1 + input->rate / 1200.0, -input->time));
    totalPayment = monthPayment * input->time;
  } else {
    int N = 0;
    for (int i = 0; i < input->time; i++) {
      monthPayment = input->amount / input->time + (input->amount - (input->amount / input->time) * N) * (input->rate / 1200.0);
      totalPayment += monthPayment;
      N++;
      printf("[%lf]\n", monthPayment);
    }
  }
  overPayment = totalPayment - input->amount;
  printf("monthP:%lf\ntotalP:%lf\noverP:%lf\n", monthPayment, totalPayment, overPayment); 
  return NULL;
}

void initCreditInfo(creditInfo *info) {
  info->amount = 0;
  info->time = 0;
  info->rate = 0;
  info->type = 0;
}

void printCreditStruct(creditInfo *inf) {
  printf("amount = %lf\ntime = %lf\nrate = %lf\n, type = %c\n",
          inf->amount, inf->time, inf->rate, inf->type);
}
/*
int main() {
  creditInfo mycredit;
  initCreditInfo(&mycredit);
  mycredit.amount = 1000000;
  mycredit.time = 48;
  mycredit.rate = 6.6;
  mycredit.type = 'd';
  creditCalc(&mycredit);
  return 0;
}
*/
