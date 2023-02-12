//�鲢���� 
#include <stdio.h>
#include <stdlib.h>
 
// �鲢���򣺽�һ��������������������ռ�ϲ���һ��
 
// ����˵��
// a -- ���������������������
// start -- ��һ�������������ʼ��ַ
// mid -- ��һ����������Ľ�����ַ��Ҳ�ǵڶ��������������ʼ��ַ
// end -- �ڶ�����������Ľ�����ַ
 
void merge(int a[], int start, int mid, int end) {
 int* tmp = (int*)malloc((end - start + 1) * sizeof(int));
 // tmp�ǻ���2�������������ʱ����
 int i = start; // ��һ��������������
 int j = mid + 1; // �ڶ���������������
 int k = 0; // ��ʱ���������
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
  tmp[k++] = a[j++]; // ��������������ϲ�
 }
 // ������Ԫ�أ�ȫ�������ϵ�����a��
 for (i = 0; i < k; i++) {
  a[start + i] = tmp[i];
 }
 free(tmp);
 tmp = NULL;
}
 
// �鲢����--��������
// ����˵����
// a -- ����������
// start -- �������ʼ��ַ
// end -- ����Ľ�����ַ
//
void merge_sort(int a[], int start, int end) {
 if (a == NULL || start >= end) {
  return;
 }
 int mid = (end + start) / 2;
 merge_sort(a, start, mid); // �ݹ�����a[start..mid]
 merge_sort(a, mid + 1, end); // �ݹ�����a[mid..end]
 // a[start..mid]��a[mid..end]����������ռ�
 // �����������һ������ռ�a[start..end]
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
