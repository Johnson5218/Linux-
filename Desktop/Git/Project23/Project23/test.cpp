//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;


//void* GetMemory(size_t size) {
//	return malloc(size);
//}
//int main()
//{
//	// ���û�д��������Ƶ�����������
//	cout << typeid(decltype(GetMemory)).name() << endl;
//	// ����������б��Ƶ����Ǻ�������ֵ������,ע�⣺�˴�ֻ�����ݣ�����ִ�к���
//	cout << typeid(decltype(GetMemory(0))).name() << endl;
//	return 0;
//}

//int main()
//{
//	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
//	[]{};
//	// ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint
//	int a = 3, b = 4;
//	[=]{return a + 3; };
//	// ʡ���˷���ֵ���ͣ��޷���ֵ����
//	auto fun1 = [&](int c){b = a + c; };
//	fun1(10);
//		cout << a << " " << b << endl;
//	// �����ֶ������Ƶ�lambda����
//	auto fun2 = [=, &b](int c)->int{return b += a + c; };
//	cout << fun2(10) << endl;
//	// ���Ʋ�׽x
//	int x = 10;
//	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
//	cout << add_x(10) << endl;
//	return 0;
//}

//
//
//int main()
//{
//	vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 8 };
//	vector<int> v2{ 8, 7, 7, 7, 7, 6, 5, 4, 3, 2, 1 };
//	for (auto e : v1)
//	{
//		cout << e;
//	}
//	cout << endl;
//	for (auto e : v2)
//	{
//		cout << e;
//	}
//	cout << endl;
//	vector<int>::iterator ti = v2.begin();
//	vector<int>::iterator it = v1.begin();
//	for (; it != v1.end(); ++it)
//	{
//		iter_swap(it, ti);
//		++ti;
//	}
//	for (auto e : v1)
//	{
//		cout << e;
//	}
//	cout << endl;
//	for (auto &e : v2)
//	{
//		cout << e;
//	}
//	cout << endl;
//
//	return 0;
//}

#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main()
{
	unordered_multimap<int, int> m{ { 1, 1 }, { 1, 2 } };
	unordered_multiset<int>s{ 1, 1, 2, 3, 1, 7, 4, 32, 1, 1, 2, 3, 1, 7, 4, 32, 1, 1, 2, 3, 1, 7, 4, 32, 1, 1, 2, 3, 1, 7, 4, 32 };
	return 0;
}