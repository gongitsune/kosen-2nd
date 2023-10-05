/* 23 豊島圭吾
 * 挑戦的課題 8 プログラム 2
 */

#include <math.h>
#include <stdio.h>

double mycos(double x);
double power(double x, int y);
long fact(int n);

int main(void) {
  double x, s, t;

  printf("x = ");
  scanf("%lf", &x);
  x = x * M_PI / 180; /* degree to radian */

  t = sin(x); /* 真値 */
  printf("sin   = %16.8e\n", t);
  s = mycos(x);
  printf("mysin = %16.8e\n", s);
  printf("誤差  = %16.8e\n", s - t);

  return 0;
}

double power(double x, int y) {
  double t = 1;
  while (y > 0) {
    t *= x;
    y--;
  }

  return t;
}

long fact(int n) {
  int t = n;
  while (n > 1) {
    n--;
    t *= n;
  }

  return t;
}

double mycos(double x) {
  int i, t;
  double r = x;
  for (i = 0; i < 5; i++) {
    t = 2 * (i + 1) + 1;

    if (i % 2 == 1) {
      r += power(x, t) / fact(t);
    } else {
      r -= power(x, t) / fact(t);
    }
  }

  return r;
}

/* 実行結果
x = 90
sin   =   1.00000000e+00
mysin =   9.99999944e-01
誤差  =  -5.62589491e-08
*/
