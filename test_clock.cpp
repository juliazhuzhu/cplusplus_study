
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h> // clock_gettime 函數所需之標頭檔
 #include <unistd.h>

int main() {
  // 儲存時間用的變數
  struct timespec start;

  // 計算開始時間
  clock_gettime(CLOCK_MONOTONIC, &start); 
  printf("time tv.sev %ld\n", start.tv_sec);
  sleep(1);
  clock_gettime(CLOCK_MONOTONIC, &start); 
  printf("time tv.sev %ld\n", start.tv_sec);


}
