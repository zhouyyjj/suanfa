//冒泡排序 
#include<stdio.h>
void Bubble_sort(int arr[], int size)
{
 int j,i,tem;
 for (i = 0; i < size-1;i ++)//size-1是因为不用与自己比较，所以比的数就少一个
 {
  int count = 0;
  for (j = 0; j < size-1 - i; j++) //size-1-i是因为每一趟就会少一个数比较
  {
   if (arr[j] > arr[j+1])//这是升序排法，前一个数和后一个数比较，如果前数大则与后一个数换位置
   {
    tem = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = tem;
    count = 1;
    
   }
  }
  if (count == 0)   //如果某一趟没有交换位置，则说明已经排好序，直接退出循环
    break; 
 }
 
}
int main()
{
 int arr[10];
 int i;
 
 printf("请输入10个数\n");
 for (i = 0; i < 10; i++)  //接收用户的数值
 {
  scanf("%d", &arr[i]);
 }
 printf("排序前的数组>");
 for (i = 0; i < 10; i++)
 {
  printf("%d ", arr[i]);
 }
 
 printf("\n排序后的数组>");
 Bubble_sort(arr, 10);
 for (i = 0; i < 10; i++)
 {
  printf("%d ", arr[i]);
 }
 
 return 0;
}
