#include<stdlib.h>
#include<stdio.h>

struct _retire_info {
  int months ; //months this is applicable for
  double contribution; // dollars contributed or spent in month
  double rate_of_return; //rate of interest
};

typedef struct _retire_info retire_info;


void print_month_info(int months, double balance) { //prints a statement to keep track of information
  printf("Age %3d month %2d you have $%.2lf\n", months / 12, months % 12, balance);

  return;
}

double balance_calculation(double balance, retire_info retire_stats) { //balance includes rate of interest and contribution per month
  balance += balance * retire_stats.rate_of_return;
  balance += retire_stats.contribution;

  return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  /* startage = in months,
     double initial, initial savings in dollars
     retire_info working, //info about working
     retire_info retired //info about being retired
  */
  
  // Set balance at initial to start
  double balance = initial;
  int total_months = startAge - 1;

  for (int i = 0; i < working.months; i++) {
    total_months += 1;
    print_month_info(total_months, balance);
    balance = balance_calculation(balance, working);
  }

  for (int j = 0; j < retired.months; j++) {
    total_months += 1;
    print_month_info(total_months, balance);
    balance = balance_calculation(balance, retired);
  }

  return;
}

int main() {
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12.0;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12.0;

  retirement(327, 21345, working, retired);

  return 0;
}
