//�۰� 
#include <stdio.h>
#define size 10

void BInsertSort(int *num, int len)
{
    int i, j, low, high, mid, key;
    for (i = 1; i < len; i++)
    {
        // �жϵ�ǰ�����Ƿ���Ҫ���в���
        if (num[i - 1] > num[i])
        {
            // ��ȡ��Ҫ���������
            key = num[i];
            // ��ʼ���ҷ�ΧΪ [0, i-1]������
            low = 0;
            high = i - 1;
            // �����۰�����㷨���Ҳ����λ��
            while (low <= high)
            {
                // ��ȡ�м��±�
                mid = (low + high) / 2;
                if (key <= num[mid])
                {
                    // ���keyС���м�ֵ������С���ҷ�Χ����������
                    high = mid - 1;
                }
                else
                {
                    // ���key�����м�ֵ������С���ҷ�Χ����������
                    low = mid + 1;
                }
            }
            // �������
            for ( j = i - 1; j >= high + 1; j--)
            {
                num[j + 1] = num[j];
            }
            // ��������
            num[high + 1] = key;
        }
    }
}

int main()
{
    int i, num[size] = {578, 432, 1325, 384, 5432, 651, 3817, 564, 387, 5};
    BInsertSort(num, size);

    for (i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
