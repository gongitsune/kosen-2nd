/* 23 豊島圭吾
 * 第13回課題 プログラム5
 */

#include <string.h>

#include <stdio.h>
int main(void) {
  char path[100];
  printf("入力ファイル名 = ");
  scanf("%s", path);

  FILE *in_fp;
  if ((in_fp = fopen(path, "r")) == NULL) {
    printf("入力ファイルがありません\n");
    return 1;
  }

  int i, r;
  int cnts[20];
  for (i = 0; i < 20; i++) {
    cnts[i] = 0;
  }

  char s[100];
  while (fscanf(in_fp, "%s", s) != EOF) {
    cnts[(int)strlen(s) - 1]++;
  }

  fclose(in_fp);

  printf("文字数 : 単語数(*=10, +=5, .=1)\n");
  for (i = 0; i < 20; i++) {
    int cnt = cnts[i];
    printf("%2d : ", i + 1);

    while (cnt > 0) {
      if (cnt >= 10) {
        printf("*");
        cnt -= 10;
      } else if (cnt >= 5) {
        printf("+");
        cnt -= 5;
      } else {
        printf(".");
        cnt--;
      }
    }

    printf("\n");
  }

  return 0;
}

/* 実行結果
入力ファイル名 = snow-white.txt
文字数 : 単語数(*=10, +=5, .=1)
 1 : ******
 2 : ******************************************+..
 3 : *********************************************************************************************.
 4 : ********************************************************.
 5 : ******************************************+..
 6 : **************************+...
 7 : *****************..
 8 : *******....
 9 : ****
10 : ****..
11 : *+....
12 : +..
13 : +....
14 : *.
15 : 
16 : .
17 : 
18 : 
19 : 
20 : 
*/
