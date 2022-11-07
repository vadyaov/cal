#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct depInfo {
  double depSum, depTerm, intRate, taxRate, repSum, remSum;
  char frequency, replanishment, withdrawals;
  bool cap;
} deposit;

// every
//            day  week mont quart y/2 year
const char payFreq[] = {'d', 'w', '1', 'q', '6', 'y', '\0'};
// every
//              month 2m  quart 4m   6m   year
const char addRemFreq[] = {'1', '2', 'q', '4', '6', 'y', '\0'};

char *depcalc(deposit *depo);
void initDeposit(deposit *depo);
size_t days(const char *startDate, const char *endDate);
int toNumber(const char *p, int n);
size_t yulian(int day, int month, int year);
char chooseFrequency(const char *str);

void calcDepo(deposit *depo, double *percents, double *tax, double *money);
double daysFrequency(char c);
void printDepo(deposit dep);
