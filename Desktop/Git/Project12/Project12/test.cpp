#include<iostream>
using namespace std;

template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
	: _pLeft(nullptr), _pRight(nullptr), _data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight; T _data;
};


template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
	void Destroy(BSTNode* del)
	{
		if (del)
		{
			delete(del);
			del = nullptr;
		}
	}
	void TreeDestroy(BSTNode* root)
	{
		if (root)
		{
			Destroy(root->_pLeft);
			Destroy(root->_pRight);
			Destroy(root);
			root = nullptr;
		}
	}
public:
	BSTree() : _pRoot(nullptr)
	{}
	~BSTree()
	{
		if (_pRoot)
		{
			TreeDestroy(_pRoot);
		}
	}
	// ���ݶ��������������ʲ��ң��ҵ�ֵΪdata�Ľڵ��ڶ����������е�λ��
	PNode Find(const T& data);
	bool Insert(const T& data)
	{
		// �����Ϊ�գ�ֱ�Ӳ���
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		// ���ն��������������ʲ���data�����еĲ���λ��
		PNode pCur = _pRoot;
		// ��¼pCur��˫�ף���Ϊ��Ԫ�����ղ�����pCur˫�����Һ��ӵ�λ��
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight; // Ԫ���Ѿ������д���
			else
				return false;
		}
		// ����Ԫ��
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}
	bool Erase(const T& data)
	{
		// �����Ϊ�գ�ɾ��ʧ��
		if (nullptr == _pRoot)
			return false;
		// ������data�����е�λ��
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		// data���ڶ����������У��޷�ɾ��
		if (nullptr == pCur)
			return false;
		// �������������ɾ����ͬѧ���Լ���ͼ�������
		if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ�����ӻ�������Ϊ��---��ֱ��ɾ��
		}
		else if (nullptr == pCur->_pRight)
		{
			// ��ǰ�ڵ�ֻ���Һ���---��ֱ��ɾ��
		}
		else
		{
			// ��ǰ�ڵ����Һ��Ӷ����ڣ�ֱ��ɾ������ɾ��������������������һ�������㣬���磺
			// �����������е����ڵ㣬�������������Ҳ�Ľڵ㣬������������������С�Ľڵ㣬������������С�Ľڵ�
				// ����ڵ��ҵ��󣬽�����ڵ��е�ֵ������ɾ���ڵ㣬ת����ɾ������ڵ�
		}
		return true;
	}
	void InOrder();
private:
	PNode _pRoot;
};



int main()
{	
	BSTree<int> s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(3);
	s.Insert(4);
	s.Insert(5);
	s.Insert(6);
	s.Insert(7);
	s.Insert(8);
	return 0;
}