//归并排序 
#include <stdio.h>
#include <stdlib.h>
 
// 归并排序：将一个数组中两个相邻有序空间合并成一个
 
// 参数说明
// a -- 包含两个有序区间的数组
// start -- 第一个有序区间的起始地址
// mid -- 第一个有序区间的结束地址。也是第二个有序区间的起始地址
// end -- 第二个有序区间的结束地址
 
void merge(int a[], int start, int mid, int end) {
 int* tmp = (int*)malloc((end - start + 1) * sizeof(int));
 // tmp是汇总2个有序区间的临时区域。
 int i = start; // 第一个有序区的索引
 int j = mid + 1; // 第二个有序区的索引
 int k = 0; // 临时区域的索引
 while (i <= mid && j <= end) {
  if (a[i] <= a[j]) {
   tmp[k++] = a[i++];
  }
  else {
   tmp[k++] = a[j++];
  }
 }
 while (i <= mid) {
  tmp[k++] = a[i++];
 }
 while (j <= end) {
  tmp[k++] = a[j++]; // 将两个有序区间合并
 }
 // 排序后的元素，全部都整合到数组a中
 for (i = 0; i < k; i++) {
  a[start + i] = tmp[i];
 }
 free(tmp);
 tmp = NULL;
}
 
// 归并排序--从上往下
// 参数说明：
// a -- 待排序数组
// start -- 数组的起始地址
// end -- 数组的结束地址
//
void merge_sort(int a[], int start, int end) {
 if (a == NULL || start >= end) {
  return;
 }
 int mid = (end + start) / 2;
 merge_sort(a, start, mid); // 递归排序a[start..mid]
 merge_sort(a, mid + 1, end); // 递归排序a[mid..end]
 // a[start..mid]和a[mid..end]是两个有序空间
 // 将它们排序成一个有序空间a[start..end]
 merge(a, start, mid, end);
}
 
int main() {
 int arr[] = { 9,5,1,6,2,3,0,4,8,7 };
 merge_sort(arr, 0, 9);
 for (int i = 0; i < 10; i++) {
  printf("%d ", arr[i]);
 }
 printf("\n");
 
 return 0;
}
