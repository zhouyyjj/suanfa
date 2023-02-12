#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
 
// 参数说明：
// a -- 待排序的数组
// n -- 数组的长度
 
void shell_sort1(int a[], int n) {
 int i, j, gap;
 // gap为步长，每次减为原来的一半。
 for (gap = n / 2; gap > 0; gap /= 2) {
  // 共gap个数组，对每一组都执行直接插入排序
  for (i = 0; i < gap; i++) {
   for (j = i + gap; j < n; j += gap) {
    // 如果a[j]<a[j-gap]，则寻找a[j]位置，并将后面的位置都后移。
    if (a[j] < a[j - gap]) {
     int tmp = a[j];
     int k = j - gap;
     while (k >= 0 && a[k] > tmp) {
      a[k + gap] = a[k];
      k -= gap;
     }
     a[k + gap] = tmp;
    }
   }
  }
 }
}
 
int main() {
 int arr[] = { 9,5,1,6,2,3,0,4,8,7 };
 shell_sort1(arr, 10);
 for (int i = 0; i < 10; i++) {
  printf("%d ", arr[i]);
 }
 printf("\n");
 
 return 0;
}
