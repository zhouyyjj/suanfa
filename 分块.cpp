#include<stdio.h>
#define size 10 
// 索引表结构
typedef struct
{
    int maxKey;     // 索引区间的最大键值
    int address;    // 索引区间的起始地址（下标）
}Index;

int BlockSearch(int *num, Index *index, int numLen, int indexLen, int key)
{
    // 先折半查找索引表，找到关键值的索引区间
    int low = 0, high = indexLen - 1;
    int mid = (low + high) / 2;
    while (low < high)
    {
        if (key == index[mid].maxKey)
        {
            break;
        }
        else if (key < index[mid].maxKey)
        {
            // key可能在mid对应的索引区间内
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
        // 因为折半查找结束后需要 mid下标来获取对应的索引区间
        // 查找结束时，low = high，故放在最后进行二分
        mid = (low + high) / 2;
    }
    // printf("折半查找索引表: \n\t区间索引表下标\t= %d\n\t区间最大值\t= %d\n\t区间起始地址\t= %d\n\n", mid, index[mid].maxKey, index[mid].address);
    
    // 获取索引区间
    int i, start = index[mid].address, end;
    if (mid == indexLen - 1)
    {
        // 如果是最后一个索引区间，则结束位置为序列长度
        end = numLen;
    }
    else
    {
        // 否则结束位置为下一个索引区间的起始位置
        end = index[mid + 1].address;
    }
    // printf("顺序查找索引区间: [%d,  %d)", start, end);
    
    // 在折半查找到的区间内进行顺序查找
    for (i = start; i < end; i++)
    {
        if (key == num[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int i, num[size] = {3, 2, 1, 0, 5, 4, 9, 8, 7, 6};

    // 建立索引表
    Index index[3];

    // 最大键值 = 3， 起始下标 = 0
    index[0].maxKey = 3;
    index[0].address = 0;
    // 最大键值 = 4， 起始下标 = 4
    index[1].maxKey = 5;
    index[1].address = 4;
    // 最大键值 = 9， 起始下标 = 6
    index[2].maxKey = 9;
    index[2].address = 6;
	
	// 查找 key=8 的下标位置
    int pos = BlockSearch(num, index, size, 3, 8);
    printf("查找成功, 位置 = %d\n", pos);

    return 0;
}



