//������������� 
#include<stdio.h>
#include<stdlib.h>
#define N 10
int a[N]={3,2,5,8,4,7,6,9,1,10};
 
typedef struct tree
{
 int data;
 struct tree *lchild;
 struct tree *rchild;
}BitTree;
 
void Sort_Tree(BitTree *bt,int key)  //�ڶ����������в�����ҹؼ���key��
{
 BitTree *parent;
 BitTree *p=(BitTree *)malloc(sizeof(BitTree));
 p->data=key;               //���������ݣ�
 p->lchild=p->rchild=NULL;  //���������ÿգ�
 BitTree *head=bt;
 while(head)                //���ҹؼ������ڵ�λ�ã�
 {
  parent=head;
  if(key<head->data)     //����ؼ���С�ڽ������ݣ�
   head=head->lchild; //���������ϲ��ң�
  else                   //���ؼ��ִ��ڽ�������
   head=head->rchild; //���������ϲ��ң�
 }
 //�ж���ӵ�������������������
 if(key<parent->data)  //С�ڸ���㣻
  parent->lchild=p; //��ӵ���������
 else                  //���ڸ���㣻
  parent->rchild=p; //��ӵ���������
}
 
//����������������������
void InOrder(BitTree *bt)  
{
 if(bt)  //����Ϊ�գ���ִ�����²�����
 {
  InOrder(bt->lchild);   //���������������
  printf("%d ",bt->data);  //���������ݣ�
  InOrder(bt->rchild);  //���������������
 }
}
 
int main(void)
{
 int i;
 BitTree *bt;  //�����������������㣻
 printf("ԭ����:\n");
 for(i=0;i<N;i++)
  printf("%d ",a[i]);
 printf("\n\n");
 
 //��ʼ������㣻
 bt=(BitTree *)malloc(sizeof(BitTree));
 bt->data=a[0];
 bt->lchild=bt->rchild=NULL;
 //�������������ݽ�������
 for(i=1;i<N;i++)
  Sort_Tree(bt,a[i]);
 
 printf("��������������:\n");
 InOrder(bt);
 printf("\n");
 return 0;
}
