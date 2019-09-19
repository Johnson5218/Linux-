//#include<iostream>
//#include<string>
//using namespace std;
//int StrtoInt(string str)
//{
//	int sum = 0;
//	int len = str.length();
//	for (int i = 0; i<len; i++)
//	{
//		if (str[i] >= '0'&&str[i] <= '9')
//			sum = sum * 18 + str[i] - '0';
//		else if (str[i] >= 'A'&&str[i] <= 'H')
//			sum = sum * 18 + str[i] - 'A' + 10;
//	}
//	return sum;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	int result = StrtoInt(s);
//	cout << result << endl;
//	return 0;
//}


//��һ������Ķ������������ڸ��ڵ㡣ͬʱ����ǧ���̶߳����ݽ��в����������ʵ��һ���̰߳�ȫ��insert������


/*
1.���ڸ��ڵ�:
����˵һ���ڵ���һ���ṹ�壬��������ָ�룬һ���洢������
�ܴ󣬷Ų����ڴ棬
2.�̰߳�ȫ:
�����Ϳ��Խ��
*/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;

typedef struct BSTreeNode
{
	struct BSTreeNode *_left;
	struct BSTreeNode *_right;
	int _val;
}BSTreeNode;


 //�����ڵ�
BSTreeNode *BuyTreeNode(int x)
{
	BSTreeNode *node = new(BSTreeNode);

	node->_val = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}



int BSTreeNodeInsert(BSTreeNode **pptree, int x) 
{
	m.lock();
	BSTreeNode *parent = NULL;
	BSTreeNode *cur = *pptree;
	if (*pptree == NULL)
	{
		*pptree = BuyTreeNode(x);
		return 0;
	}
	while (cur)
	{
		parent = cur;
		if (cur->_val > x)
			cur = cur->_left;
		else if (cur->_val < x)
			cur = cur->_right;
		else
			return -1;
	}

	if (parent->_val > x)
		parent->_left = BuyTreeNode(x);
	else
		parent->_right = BuyTreeNode(x);
	m.unlock();
	return 0;
}


int main()
{
	BSTreeNode* pRoot = new(BSTreeNode);
	pRoot->_val = 3;
	pRoot->_left = nullptr;
	pRoot->_right = nullptr;

	BSTreeNodeInsert(&pRoot,1);
	return 0;
}