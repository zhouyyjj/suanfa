#include <stdio.h>
#define size 10

void Swap(int *num, int i, int j)
{
    int temp;
    temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

// ���ѵ���
void Heapify(int *num, int len, int k)
{
    if (k < len)
    {
        int root = k;           // �����
        int lchild = 2*k + 1;   // ���ӽ��
        int rchild = 2*k + 2;   // �Һ��ӽ��
        // �������Һ��ӽ���е������
        if (lchild < len && num[root] < num[lchild])
        {
            root = lchild; 
        }
        if (rchild < len && num[root] < num[rchild])
        {
            root = rchild;
        }
        
        // ��������㵽�����
        if (root != k)
        {
            Swap(num, root, k);
            // ÿ�ν���������Ӱ�쵽��Ӧ���ӽ��������˳��
            // ������Ҫ�Խ�����ĺ��ӽ�������������ѵ���
            Heapify(num, len, root);
        }
    }
}

// ��������
void CreateHeap(int *num, int len)
{
    int i;
    // ���һ������±�
    int last = len - 1;   
    // ���һ�����ĸ�����±�      
    int parent = (last - 1) / 2;
    // �����һ�����ĸ���㵽����㣬���ν������ѵ���
    for (i = parent; i >= 0; i--)
    {
        Heapify(num, len, i);
    }
}

// ������
void HeapSort(int *num, int len)
{
    // �������Ѳ��������ѵ���
    CreateHeap(num, len);
    printf("���ѵ���!\n");
    int i;
    // ����ȡ������㣨���ֵ��
    for (i = len - 1; i >= 0; i--)
    {
        // �����ѵĸ���㣨���ֵ���������һ�����
        Swap(num, i, 0);
        // ������������ĸ���㷢���˸ı䣬�ʻ���Ը���������ѵ������ѽ�����ĩβ��㲻���������
        // ����ʱ�����С�����и���㣬����ڵ���ʱֻ�迼������ӵķ�֧����
        Heapify(num, i, 0); 
    }   
}

int main()
{
    int i, num[size] = {8, 4, 3, 1, 6, 9, 5, 7, 2, 0};
    HeapSort(num, size);

    for (i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
