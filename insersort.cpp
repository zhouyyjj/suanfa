#include <stdio.h>
#define size 10

void InsertSort(int *num, int len)
{
    int i, j, temp;
    for (i = 1; i < len; i++)
    {
        // num[i]之前的序列是有序的，num[i - 1]为有序部分的最大值
        // 故只需要与有序部分的最大值进行比较，即可判断是否需要插入
        if (num[i - 1] > num[i])
        {
            // 获取需要插入的数据
            temp = num[i];         
            // 依次后移，查找插入位置
            for ( j = i - 1; j >= 0 && num[j] > temp; j--)
            {
                num[j + 1] = num[j];
            }
            // 完成插入
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
