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
	//把T二叉树插入Tree二叉树中
	if (tree == nullptr)
		tree = T;
	else
		InsertSearchNode(tree, T);
}

void BuildBinTree(BinTree& tree, int* a)
{

	for (int i = 0; i < length; i++)
	{
		//先创建一个二叉树，数组变为二叉树
		BinTree T = (BinTree)malloc(sizeof(TreeNode));
		T->data = a[i];
		T->left = T->right = nullptr; 
			Insert(tree, T);

	}



}
//递归查找 返回的是结点的指针?
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

//非递归查找
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

//查找最大元素 ?最大的数字肯定在右子树的末尾，同理最小数在座左子树的末尾
int FindMax(BinTree& tree)
{
	if (tree == nullptr)
		return -1;
	while (tree->right)
		tree = tree->right;
	return tree->data;

}
// 非递归实现 查找二叉树最大数字
int FindMax1(BinTree& tree)
{
	if (tree == nullptr)
		return -1;
	if (!tree->right)
		return tree->data;
	else
		FindMax1(tree->right);

}

//非递归实现 查找二叉树最小数
BinTree FindMin(BinTree& tree)
{
	if (tree == nullptr)
		return NULL;
	if (!tree->left)
		return tree;
	else
		FindMin(tree->left);

}

//二叉树的插入
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

// 二叉树删除
BinTree Delete(int x, BinTree& tree)
{
	BinTree T;
	if (tree == nullptr)
	{
		return nullptr;
		cout << "二叉树为空，不能删除" << endl;
	}
	else if (x < tree->data)
	{
		tree->left = Delete(x, tree->left);//左子树递归删除
	}
	else if (x > tree->data)
	{
		tree->right = Delete(x, tree->right);//右子树递归删除
	}
	else
	{
		if (tree->left && tree->right)//被删除节点有左右连个子节点
		{
			T = FindMin(tree->right); //在右子树中找最小的元素填充删除节点
			tree->data = T->data;
			tree->right = Delete(tree->data, tree->right);//删除右子树中的最小元素
		}
		else //删除的节点有一个或者无子节点
		{
			T = tree;
			if (!tree->left) //有右孩子或无子节点
			{
				tree = tree->right;
			}
			else if (!tree->right) //有左孩子或无子节点
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

	cout << find1(tree1, 6) << endl; //打印指针
	ProOrderTraverse(tree1);
	cout << endl;

	cout << find2(tree1, 45) << endl;
	ProOrderTraverse(tree1);
	cout << endl;

	//cout << FindMax(tree1) << endl; ?//非递归实现
	//cout << FindMax1(tree1) << endl; //递归实现
	//ProOrderTraverse(tree1);
	//cout << endl;

	//Delete(4, tree1);
	//ProOrderTraverse(tree1);

	return 0;
}*/

