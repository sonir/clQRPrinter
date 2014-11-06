#pragma once

//#include <stdio.h>
//#include <stdlib.h>

static char chunk36[] = "0123456789abcdefghijklmnopqrstuvwxyz";

// 戻り値
//   長さ
// 引数
//   num 変換したい数
//   out 変換した文字列を格納するバッファ

int ito36(int num, char *out) {
  int len = 0;
  char buf[16];

  while (num) {
    buf[len++] = chunk36[num % 36];
    num /= 36;
  }

  for (int i = 0; i < len; i++) {
      out[i] = buf[len - i - 1];
  }
  out[len] = 0;

  return len;
}

//int main() {
//  char buf[8];
//  int val = 123456;
//
//  printf("val = %d\n", val);
//  printf("len = %d\n", ito36(val, buf));
//  printf("out = %s\n", buf);
//
//  return 0;
//}
