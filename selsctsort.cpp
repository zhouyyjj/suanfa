//简单选择排序 
#include <stdio.h>
#define size 10

void SelectSort(int *num, int len)
{
    int i, j, min, temp;
    for (i = 0; i < len; i++)
    {
        // 初始最小值下标
        min = i;
        // 查找后面最小值的下标
        for (j = i + 1; j < len; j++)
        {
            if (num[min] > num[j])
            {
                min = j;
            }
        }
        // 交换最小值
        if (min != i)
        {
            temp = num[i];
            num[i] = num[min];
            num[min] = temp;
        }
    }
}

int main()
{
    int i, num[size] = {65874, 432, 45, 54, 541, 32, 213, 2, 354, 342};
    SelectSort(num, size);

    for (i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
