#include <stdio.h>
#include <string.h>
#define  size 10    // 数组长度
#define  D 5        // 最大位数

//取整数M的第i位数
int GetDigit(int M, int i) 
{
 while(i > 1)
 {
  M /= 10;
  i--;
 }
 return M % 10;
}

// 基数排序
void RadixSort(int *num, int len)
{
    int i, j, k, l, digit;
    int allot[10][size];   // 分配数组
    
    // 初始化分配数组全为0
    memset(allot, 0, sizeof(allot));
    
    // 遍历
    for (i = 1; i <= D; i++)
    {
        // 将每个数据的第i位数分配到allot数组中
        for (j = 0; j < len; j++)
        {
            // 获取当前数据 num[j] 的 第i位数
            digit = GetDigit(num[j], i);  
            k = 0;
            // 查找插入的位置
            while (allot[digit][k])
            {
                k++;
            }
            // 将num[j]添加到分配数组allot的第digit行的末尾
            allot[digit][k] = num[j];
        }
        // 将分配数组的数据收集到原数组中
        l = 0;
        for (j = 0; j < 10; j++)
        {
            k = 0;
            // 获取数组allot的每一行的数据 到 原数组中
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
