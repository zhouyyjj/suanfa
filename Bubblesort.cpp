//ð������ 
#include<stdio.h>
void Bubble_sort(int arr[], int size)
{
 int j,i,tem;
 for (i = 0; i < size-1;i ++)//size-1����Ϊ�������Լ��Ƚϣ����Աȵ�������һ��
 {
  int count = 0;
  for (j = 0; j < size-1 - i; j++) //size-1-i����Ϊÿһ�˾ͻ���һ�����Ƚ�
  {
   if (arr[j] > arr[j+1])//���������ŷ���ǰһ�����ͺ�һ�����Ƚϣ����ǰ���������һ������λ��
   {
    tem = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = tem;
    count = 1;
    
   }
  }
  if (count == 0)   //���ĳһ��û�н���λ�ã���˵���Ѿ��ź���ֱ���˳�ѭ��
    break; 
 }
 
}
int main()
{
 int arr[10];
 int i;
 
 printf("������10����\n");
 for (i = 0; i < 10; i++)  //�����û�����ֵ
 {
  scanf("%d", &arr[i]);
 }
 printf("����ǰ������>");
 for (i = 0; i < 10; i++)
 {
  printf("%d ", arr[i]);
 }
 
 printf("\n����������>");
 Bubble_sort(arr, 10);
 for (i = 0; i < 10; i++)
 {
  printf("%d ", arr[i]);
 }
 
 return 0;
}
