
/*����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��*/
#include<iostream>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		TreeNode* pre = NULL;//�˴���Ҫ��ʼ��������ѭ����������д�
		MiddleList(pRootOfTree, pre);
		while (pre->left != NULL)
			pre = pre->left;
		return pre;
	}
	void MiddleList(TreeNode* pRoot, TreeNode* &pre)//��������ɵ�˫������
	{
		if (pRoot == NULL)
			return;
		MiddleList(pRoot->left, pre);
		if (pre != NULL)//�ı�ָ���ָ��
		{
			pRoot->left = pre;
			pre->right = pRoot;
		}
		pre = pRoot;//��¼ǰһ��ָ��
		MiddleList(pRoot->right, pre);
	}
};

int main(){

	system("pause");
	return 0;
}