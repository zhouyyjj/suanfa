//�۰���� 
#include"stdio.h"
int main()
{
 void sort(int a[10],int m);//������ 
 void search(int a[10],int n);//���Һ��� 
 int a[10],n,i;
 printf("������10��������\n");
 for(i=0;i<10;i++)
    scanf("%d",&a[i]);
 printf("����������Ҫ���ҵ����֣�\n");
 scanf("%d",&n);
 sort(a,10);
 search(a,n);
 return 0;
}
void sort(int a[10],int m)//ѡ������ 
{
 int i,j,k,temp;
 for(i=0;i<m-1;i++)
 {
  k=i;
  for(j=i+1;j<m;j++)
  {
   if(a[j]<a[k])
     k=j;
  }
  temp=a[i];a[i]=a[k];a[k]=temp;
 }
 printf("�����\n");
 for(i=0;i<m;i++)
    printf("%d ",a[i]);
 printf("\n");
}
void search(int a[10],int n)
{
 int low=0,high=9,mid,flag;//low,high�ֱ�Ϊ�������˵���Ҷ˵㣬midΪ�����м䣬flag����߼�ֵ 
 while(low<=high)
 {
  mid=(low+high)/2;//�۰� 
  if(n==a[mid])
  {
    flag=1;//��������м�ֵ���ڴ�����ֵ������ҳɹ���flagֵΪ 1,Ϊ�� 
    break;//�ҵ�������ֹѭ�� 
     }
  else
     if(n<a[mid])//������ֵС���м�ֵ������ǰһ�������ڼ������� 
       high=mid-1;//�����Ҷ˵� 
     else if(n>a[mid])//������ֵ�����м�ֵ�����ں�һ�������ڼ������� 
       low=mid+1;//������˵� 
 }
 if(flag==1)//����ҵ� 
   printf("found! ���Ϊ��%d\n",mid+1);//midΪ������ֵ�������е��±꣬��mid+1����������ϰ���е��±� 
 else
   printf("NO found !\n");
}
