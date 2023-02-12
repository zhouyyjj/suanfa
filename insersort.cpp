#include <stdio.h>
#define size 10

void InsertSort(int *num, int len)
{
    int i, j, temp;
    for (i = 1; i < len; i++)
    {
        // num[i]֮ǰ������������ģ�num[i - 1]Ϊ���򲿷ֵ����ֵ
        // ��ֻ��Ҫ�����򲿷ֵ����ֵ���бȽϣ������ж��Ƿ���Ҫ����
        if (num[i - 1] > num[i])
        {
            // ��ȡ��Ҫ���������
            temp = num[i];         
            // ���κ��ƣ����Ҳ���λ��
            for ( j = i - 1; j >= 0 && num[j] > temp; j--)
            {
                num[j + 1] = num[j];
            }
            // ��ɲ���
            num[j + 1] = temp;  
        } 
    }
}

int main()
{
    int i, num[size] = {34, 56, 978, 543, 321, 7386, 534, 8, 1, 6};
    InsertSort(num, size);

    for (i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
