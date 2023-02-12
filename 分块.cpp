#include<stdio.h>
#define size 10 
// ������ṹ
typedef struct
{
    int maxKey;     // �������������ֵ
    int address;    // �����������ʼ��ַ���±꣩
}Index;

int BlockSearch(int *num, Index *index, int numLen, int indexLen, int key)
{
    // ���۰�����������ҵ��ؼ�ֵ����������
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
            // key������mid��Ӧ������������
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
        // ��Ϊ�۰���ҽ�������Ҫ mid�±�����ȡ��Ӧ����������
        // ���ҽ���ʱ��low = high���ʷ��������ж���
        mid = (low + high) / 2;
    }
    // printf("�۰����������: \n\t�����������±�\t= %d\n\t�������ֵ\t= %d\n\t������ʼ��ַ\t= %d\n\n", mid, index[mid].maxKey, index[mid].address);
    
    // ��ȡ��������
    int i, start = index[mid].address, end;
    if (mid == indexLen - 1)
    {
        // ��������һ���������䣬�����λ��Ϊ���г���
        end = numLen;
    }
    else
    {
        // �������λ��Ϊ��һ�������������ʼλ��
        end = index[mid + 1].address;
    }
    // printf("˳�������������: [%d,  %d)", start, end);
    
    // ���۰���ҵ��������ڽ���˳�����
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

    // ����������
    Index index[3];

    // ����ֵ = 3�� ��ʼ�±� = 0
    index[0].maxKey = 3;
    index[0].address = 0;
    // ����ֵ = 4�� ��ʼ�±� = 4
    index[1].maxKey = 5;
    index[1].address = 4;
    // ����ֵ = 9�� ��ʼ�±� = 6
    index[2].maxKey = 9;
    index[2].address = 6;
	
	// ���� key=8 ���±�λ��
    int pos = BlockSearch(num, index, size, 3, 8);
    printf("���ҳɹ�, λ�� = %d\n", pos);

    return 0;
}



