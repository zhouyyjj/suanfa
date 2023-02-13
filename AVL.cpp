//����ƽ���������1.5h��
#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	char data;
	struct TreeNode *lchild,*rchild;
};
//�������
void PreNode(struct TreeNode *root)
{
	if(!root)
	{
		return;
	}
	printf("%c ",root -> data);
	PreNode(root -> lchild);
	PreNode(root -> rchild);
}
//�������
void MidNode(struct TreeNode *root)
{
	if(!root)
	{
		return;
	}
	MidNode(root -> lchild);
	printf("%c ",root -> data);
	MidNode(root -> rchild);
}
//�������
void LastNode(struct TreeNode *root)
{
	if(!root)
	{
		return;
	}
	LastNode(root -> lchild);
	LastNode(root -> rchild);
	printf("%c ",root -> data);
}
//�ݻ���
void DstrotyTree(struct TreeNode *root)
{
	if(!root)
	{
		return;
	}
	DstrotyTree(root -> lchild);
	DstrotyTree(root -> rchild);
	free(root);
}
//�ݹ�������
int GetTreeHeight(struct TreeNode *root)
{
	if(!root)
	{
		return 0;
	}
	int Lheight  = GetTreeHeight(root -> lchild);
	int Rheight = GetTreeHeight(root -> rchild);
	return (Lheight > Rheight ? Lheight : Rheight ) + 1;
}
//ƽ������� ������˳ʱ�룩
struct TreeNode *AVL_Right(struct TreeNode *p)
{
	struct TreeNode *q = p -> lchild;
	p -> lchild = q -> rchild;
	q -> rchild = p;
	return q;
}
//ƽ������� ��������ʱ�룩
struct TreeNode *AVL_Left(struct TreeNode *p)
{
	struct TreeNode *q = p -> rchild;
	p -> rchild = q -> lchild;
	q -> lchild = p;
	return q;
}
//ƽ������� ������������ʱ�룬˳ʱ�룩
struct TreeNode *AVL_Left_Right(struct TreeNode *p)
{
	p -> lchild = AVL_Left(p -> lchild);
	return AVL_Right(p);

}
//ƽ������� ����������˳ʱ�룬��ʱ�룩
struct TreeNode *AVL__Right__Left(struct TreeNode *p)
{
	p -> rchild = AVL_Left(p -> rchild);
	return AVL_Left(p);
}
//�ݹ���ӽڵ�
struct TreeNode *AVL_DiGui_AddNode(struct TreeNode *root,struct TreeNode *p)
{
	//����ڵ�
	if(!root)
	{
		return p;
	}
	if(root -> data > p -> data)//���
	{
		root -> lchild = AVL_DiGui_AddNode(root -> lchild,p);
	}
	else if(root -> data < p -> data)//�ұ�
	{
		root -> rchild = AVL_DiGui_AddNode(root -> rchild,p);
	}
	else//���
	{
		return root;
	}
	//ƽ��
	if(abs(GetTreeHeight(root -> lchild) - GetTreeHeight(root -> rchild)) > 1)
	{
		if(root -> data > p -> data)//���
		{
			if(root -> lchild -> data > p -> data)//����
			{
				root = AVL_Right(root);
			}
			else if(root -> lchild -> data < p -> data)//����
			{
				root = AVL_Left_Right(root);
			}
		}
		else if(root -> data < p -> data)//�ұ�
		{
			if(root -> rchild -> data < p -> data)//����
			{
				root = AVL_Left(root);
			}
			else if(root -> rchild -> data > p -> data)//����
			{
				root = AVL__Right__Left(root);
			}
		}
	}
	return root;
}
//����ƽ�������
struct TreeNode *CreatTree(char *str)
{
	struct TreeNode *root = NULL; 
	while(*str)
	{
		struct TreeNode *p = malloc(sizeof(*p));
		p -> data = *str;
		p -> lchild = p -> rchild = NULL;
		root = AVL_DiGui_AddNode(root,p);
		str++;
	}
	return root;
}

int main()
{
	char str[128];
	scanf("%s",str);
	struct TreeNode * root = CreatTree(str);//����ƽ�������
	printf("����");
	PreNode(root);//����
	printf("\n");
	printf("����");
	MidNode(root);//����
	printf("\n");
	printf("����");
	LastNode(root);//����
	printf("\n");
	int height = GetTreeHeight(root);//�ݹ�������
	printf("Tree_Height = %d\n",height);
	DstrotyTree(root);//�ݻ���
	return 0;
}
