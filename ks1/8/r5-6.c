/* 23 豊島圭吾
 * レポート8 プログラム1
 */

#include <stdio.h>

int main(void) {
  char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  int d[5][12], total[5];

  int i, r;
  for (i = 0; i < 5; i++) {
    total[i] = 0;
    for (r = 0; r < 12; r++) {
      scanf("%d", &d[i][r]);
      total[i] += d[i][r];
    }
  }

  printf("      ");
  for (i = 0; i < 12; i++)
    printf("%s ", month[i]);
  printf("Total\n");

  for (i = 0; i < 5; i++) {
    printf("%4d  ", 1993 + i);
    for (r = 0; r < 12; r++)
      printf("%3d ", d[i][r]);
    printf("%5d\n", total[i]);
  }

  return 0;
}

/* 実行結果 23 豊島圭吾
36 51 71 96 100 158 135 102 201 103 60 30
42 46 65 100 107 170 128 100 190 110 68 29
48 52 68 109 114 166 131 92 196 106 70 35
37 47 70 89 93 160 125 86 189 99 65 40
40 54 71 101 100 169 132 96 197 108 64 28
      Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec Total
1993   36  51  71  96 100 158 135 102 201 103  60  30  1143
1994   42  46  65 100 107 170 128 100 190 110  68  29  1155
1995   48  52  68 109 114 166 131  92 196 106  70  35  1187
1996   37  47  70  89  93 160 125  86 189  99  65  40  1100
1997   40  54  71 101 100 169 132  96 197 108  64  28  1160
 */
