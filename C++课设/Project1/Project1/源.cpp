/*#include<iostream>
using namespace std;

const int length = 10;
typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} *BinTree;


void InsertSearchNode(BinTree& root, BinTree& T)
{
	if (root->data > T->data)
	{
		if (root->left == nullptr)
			root->left = T;
		else
			InsertSearchNode(root->left, T);
	}


	if (root->data < T->data)

	{
		if (root->right == nullptr)
			root->right = T;
		else
			InsertSearchNode(root->right, T);
	}


}

void Insert(BinTree& tree, BinTree& T)
{
	//��T����������Tree��������
	if (tree == nullptr)
		tree = T;
	else
		InsertSearchNode(tree, T);
}

void BuildBinTree(BinTree& tree, int* a)
{

	for (int i = 0; i < length; i++)
	{
		//�ȴ���һ���������������Ϊ������
		BinTree T = (BinTree)malloc(sizeof(TreeNode));
		T->data = a[i];
		T->left = T->right = nullptr; 
			Insert(tree, T);

	}



}
//�ݹ���� ���ص��ǽ���ָ��?
BinTree find1(BinTree& tree, int x)
{
	if (tree == nullptr)
		return NULL;
	if (x > tree->data)
		return find1(tree->right, x);
	else if (x < tree->data)
		return find1(tree->left, x);
	else
		return tree;
}

//�ǵݹ����
BinTree find2(BinTree& tree, int x)
{
	while (tree)
	{
		if (x > tree->data)
			tree = tree->right;
		else if (x < tree->data)
			tree = tree->left;
		else
			return tree;
	}
	return NULL;
}

//�������Ԫ�� ?�������ֿ϶�����������ĩβ��ͬ����С��������������ĩβ
int FindMax(BinTree& tree)
{
	if (tree == nullptr)
		return -1;
	while (tree->right)
		tree = tree->right;
	return tree->data;

}
// �ǵݹ�ʵ�� ���Ҷ������������
int FindMax1(BinTree& tree)
{
	if (tree == nullptr)
		return -1;
	if (!tree->right)
		return tree->data;
	else
		FindMax1(tree->right);

}

//�ǵݹ�ʵ�� ���Ҷ�������С��
BinTree FindMin(BinTree& tree)
{
	if (tree == nullptr)
		return NULL;
	if (!tree->left)
		return tree;
	else
		FindMin(tree->left);

}

//�������Ĳ���
BinTree numberInsert(BinTree& T, int x)
{
	if (T == nullptr)
	{
		T = (BinTree)malloc(sizeof(TreeNode));
		T->data = x;
		T->left = T->right = nullptr;
	}
	else if (T->data > x)
		T->left = numberInsert(T->left, x);
	else if (T->data < x)
		T->right = numberInsert(T->right, x);
	return T;
}

// ������ɾ��
BinTree Delete(int x, BinTree& tree)
{
	BinTree T;
	if (tree == nullptr)
	{
		return nullptr;
		cout << "������Ϊ�գ�����ɾ��" << endl;
	}
	else if (x < tree->data)
	{
		tree->left = Delete(x, tree->left);//�������ݹ�ɾ��
	}
	else if (x > tree->data)
	{
		tree->right = Delete(x, tree->right);//�������ݹ�ɾ��
	}
	else
	{
		if (tree->left && tree->right)//��ɾ���ڵ������������ӽڵ�
		{
			T = FindMin(tree->right); //��������������С��Ԫ�����ɾ���ڵ�
			tree->data = T->data;
			tree->right = Delete(tree->data, tree->right);//ɾ���������е���СԪ��
		}
		else //ɾ���Ľڵ���һ���������ӽڵ�
		{
			T = tree;
			if (!tree->left) //���Һ��ӻ����ӽڵ�
			{
				tree = tree->right;
			}
			else if (!tree->right) //�����ӻ����ӽڵ�
				tree = tree->left;
			free(T);
		}
	}
	return tree;
}

void ProOrderTraverse(BinTree tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << " ";
	ProOrderTraverse(tree->left);
	ProOrderTraverse(tree->right);
}
int main()
{
	int a[length] = { 20,30,15,10,4,3,5,6,8,45 };
	BinTree tree1;
	tree1 = nullptr;

	BuildBinTree(tree1, a);
	ProOrderTraverse(tree1);
	cout << endl;

	cout << find1(tree1, 6) << endl; //��ӡָ��
	ProOrderTraverse(tree1);
	cout << endl;

	cout << find2(tree1, 45) << endl;
	ProOrderTraverse(tree1);
	cout << endl;

	//cout << FindMax(tree1) << endl; ?//�ǵݹ�ʵ��
	//cout << FindMax1(tree1) << endl; //�ݹ�ʵ��
	//ProOrderTraverse(tree1);
	//cout << endl;

	//Delete(4, tree1);
	//ProOrderTraverse(tree1);

	return 0;
}*/

