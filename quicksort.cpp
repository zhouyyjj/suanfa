#include <stdio.h>

#define SIZE 6

//��������
void quick_sort(int num[], int low, int high )
{
    int i,j,temp;
    int tmp;

    i = low;
    j = high;
    tmp = num[low];   //����Ϊ�м�ֽ��ߣ���߱���С���ұ߱�����,ͨ����һ��Ԫ���ǻ�׼��

    if(i > j)  //����±�i�����±�j��������������
    {
        return;
    }

    while(i != j)
    {
        while(num[j] >= tmp && j > i)   
        {
            j--;
        }

        while(num[i] <= tmp && j > i)
        {
            i++;
        }

        if(j > i)
        {
            temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
    }

    num[low] = num[i];
    num[i] = tmp;

    quick_sort(num,low,i-1);
    quick_sort(num,i+1,high);
}

int main(int argc , char **argv)
{
    //����һ������
    int num[SIZE] ={0};
    int i;

    //��������
    for(i =0; i < SIZE; i++)
    {
        scanf("%d",&num[i]);
    }

    quick_sort(num, 0, SIZE-1);

    for(i = 0; i < SIZE; i++)
    {
        printf(" %d ", num[i]);
    }

    return 0;
}
