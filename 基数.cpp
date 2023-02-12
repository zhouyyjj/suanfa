#include <stdio.h>
#include <string.h>
#define  size 10    // ���鳤��
#define  D 5        // ���λ��

//ȡ����M�ĵ�iλ��
int GetDigit(int M, int i) 
{
 while(i > 1)
 {
  M /= 10;
  i--;
 }
 return M % 10;
}

// ��������
void RadixSort(int *num, int len)
{
    int i, j, k, l, digit;
    int allot[10][size];   // ��������
    
    // ��ʼ����������ȫΪ0
    memset(allot, 0, sizeof(allot));
    
    // ����
    for (i = 1; i <= D; i++)
    {
        // ��ÿ�����ݵĵ�iλ�����䵽allot������
        for (j = 0; j < len; j++)
        {
            // ��ȡ��ǰ���� num[j] �� ��iλ��
            digit = GetDigit(num[j], i);  
            k = 0;
            // ���Ҳ����λ��
            while (allot[digit][k])
            {
                k++;
            }
            // ��num[j]��ӵ���������allot�ĵ�digit�е�ĩβ
            allot[digit][k] = num[j];
        }
        // ����������������ռ���ԭ������
        l = 0;
        for (j = 0; j < 10; j++)
        {
            k = 0;
            // ��ȡ����allot��ÿһ�е����� �� ԭ������
            while (allot[j][k])
            {
                num[l++] = allot[j][k++];
            }
        }
        memset(allot, 0, sizeof(allot));
    }
}

int main()
{
    int i, num[size] = {52, 200, 4, 1034, 17, 319, 834, 3311, 603, 8};
    RadixSort(num, size);

    for (i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
