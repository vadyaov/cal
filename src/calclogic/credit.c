#include "credit.h"

char *creditCalc(creditInfo *input) {
  double monthPayment = 0.0, overPayment = 0.0, totalPayment = 0.0,
         firstMonth = 0.0, lastMonth = 0.0;
  int mlen = 0, tlen = 0, olen = 0;
  char *output = NULL;
  char month[512] = {'\0'}, total[256] = {'\0'}, overp[256] = {'\0'};
  if (input->type == 'a') {
    monthPayment = (input->amount * input->rate / 1200.0) /
                   (1 - pow(1 + input->rate / 1200.0, -input->time));
    totalPayment = monthPayment * input->time;
  } else {
    for (int i = 0; i < input->time; i++) {
      monthPayment = input->amount / input->time +
                     (input->amount - (input->amount / input->time) * i) *
                         (input->rate / 1200.0);
      totalPayment += monthPayment;
      if (0 == i)
        firstMonth = monthPayment;
      else if (i == input->time - 1)
        lastMonth = monthPayment;
    }
  }
  overPayment = totalPayment - input->amount;
  if (input->type == 'a')
    mlen = sprintf(month, "Month Payment: %.2lf\n", monthPayment);
  else
    mlen = sprintf(month, "Month Payment:\n\t from: %.2lf\n\t   to:    %.2lf\n",
                   firstMonth, lastMonth);
  tlen = sprintf(total, "Total Payment: %.2lf\n", totalPayment),
  olen = sprintf(overp, "Overpayment : %.2lf\n", overPayment);
  output = calloc(mlen + tlen + olen + 1, sizeof(char));
  if (output) {
    strcpy(output, month);
    strcat(output, total);
    strcat(output, overp);
  }
  return output;
}

void initCreditInfo(creditInfo *info) {
  info->amount = 0;
  info->time = 0;
  info->rate = 0;
  info->type = 0;
}
