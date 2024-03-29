/* [5] 23 豊島圭吾 */

#include <math.h>
#include <stdio.h>

int prime(int n);

int main(void) {
  int i, r = 0, t = 0;

  // 素数の列挙
  int primes[100], prime_cache[100];
  for (i = 0; i < 100; i++)
    prime_cache[i] = 0;
  for (i = 0; i < 100; i++) {
    if (prime(i) == 1) {
      primes[r] = i;
      prime_cache[i] = r;
      r++;
    }
  }
  for (; r < 100; r++) {
    primes[r] = 0;
  }

  i = 6;
  int lhs, rhs;
  while (i <= 100) {
    printf("%d", i);

    r = 0;
    while ((lhs = primes[r]) <= i && lhs <= rhs) {
      if (prime_cache[i - lhs] == 0) {
        r++;
        continue;
      }

      printf(" = %d + %d", lhs, i - lhs);
      r++;
    }

    printf("\n");

    i += 2;
  }

  return 0;
}

int prime(int n) {
  int i, b;
  if (n == 1)
    return 0;

  i = 2;
  b = sqrt((double)n);
  while (((n % i) != 0) && (i <= b))
    i++;

  if (i > b) {
    return 1;
  } else {
    return 0;
  };
}

/* 実行結果
6 = 3 + 3
8 = 3 + 5
10 = 3 + 7 = 5 + 5
12 = 5 + 7
14 = 3 + 11 = 7 + 7
16 = 3 + 13 = 5 + 11
18 = 5 + 13 = 7 + 11
20 = 3 + 17 = 7 + 13
22 = 3 + 19 = 5 + 17 = 11 + 11
24 = 5 + 19 = 7 + 17 = 11 + 13
26 = 3 + 23 = 7 + 19 = 13 + 13
28 = 5 + 23 = 11 + 17
30 = 7 + 23 = 11 + 19 = 13 + 17
32 = 3 + 29 = 13 + 19
34 = 3 + 31 = 5 + 29 = 11 + 23 = 17 + 17
36 = 5 + 31 = 7 + 29 = 13 + 23 = 17 + 19
38 = 7 + 31 = 19 + 19
40 = 3 + 37 = 11 + 29 = 17 + 23
42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23
44 = 3 + 41 = 7 + 37 = 13 + 31
46 = 3 + 43 = 5 + 41 = 17 + 29 = 23 + 23
48 = 5 + 43 = 7 + 41 = 11 + 37 = 17 + 31 = 19 + 29
50 = 3 + 47 = 7 + 43 = 13 + 37 = 19 + 31
52 = 5 + 47 = 11 + 41 = 23 + 29
54 = 7 + 47 = 11 + 43 = 13 + 41 = 17 + 37 = 23 + 31
56 = 3 + 53 = 13 + 43 = 19 + 37
58 = 5 + 53 = 11 + 47 = 17 + 41 = 29 + 29
60 = 7 + 53 = 13 + 47 = 17 + 43 = 19 + 41 = 23 + 37 = 29 + 31
62 = 3 + 59 = 19 + 43 = 31 + 31
64 = 3 + 61 = 5 + 59 = 11 + 53 = 17 + 47 = 23 + 41
66 = 5 + 61 = 7 + 59 = 13 + 53 = 19 + 47 = 23 + 43 = 29 + 37
68 = 7 + 61 = 31 + 37
70 = 3 + 67 = 11 + 59 = 17 + 53 = 23 + 47 = 29 + 41
72 = 5 + 67 = 11 + 61 = 13 + 59 = 19 + 53 = 29 + 43 = 31 + 41
74 = 3 + 71 = 7 + 67 = 13 + 61 = 31 + 43 = 37 + 37
76 = 3 + 73 = 5 + 71 = 17 + 59 = 23 + 53 = 29 + 47
78 = 5 + 73 = 7 + 71 = 11 + 67 = 17 + 61 = 19 + 59 = 31 + 47 = 37 + 41
80 = 7 + 73 = 13 + 67 = 19 + 61 = 37 + 43
82 = 3 + 79 = 11 + 71 = 23 + 59 = 29 + 53 = 41 + 41
84 = 5 + 79 = 11 + 73 = 13 + 71 = 17 + 67 = 23 + 61 = 31 + 53 = 37 + 47 = 41 +
43 86 = 3 + 83 = 7 + 79 = 13 + 73 = 19 + 67 = 43 + 43 88 = 5 + 83 = 17 + 71 = 29
+ 59 = 41 + 47 90 = 7 + 83 = 11 + 79 = 17 + 73 = 19 + 71 = 23 + 67 = 29 + 61 =
31 + 59 = 37 + 53 = 43 + 47 92 = 3 + 89 = 13 + 79 = 19 + 73 = 31 + 61 94 = 5 +
89 = 11 + 83 = 23 + 71 = 41 + 53 = 47 + 47 96 = 7 + 89 = 13 + 83 = 17 + 79 = 23
+ 73 = 29 + 67 = 37 + 59 = 43 + 53 98 = 19 + 79 = 31 + 67 = 37 + 61 100 = 3 + 97
= 11 + 89 = 17 + 83 = 29 + 71 = 41 + 59 = 47 + 53
*/
