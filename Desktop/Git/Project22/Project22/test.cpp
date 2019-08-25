//#include<iostream>
//#include<map>
//using namespace std;
//
//
//int main()
//{
//	map<int, int> m;
//	m.insert(make_pair(1, 2));
//	m[2] = 3;
//	for (auto& t : m)
//	{
//		cout << t.first << "----" << t.second << endl;
//	}
//	return 0;
//}


#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
class Mul2
{
public:
	void operator()(int& data)
	{
		data <<= 1;
	}
};
class Mod3
{
public:
	bool operator()(int data)
	{
		return 0 == data % 3;
	}
};
int main()
{
	// ��������ÿ��Ԫ�س�2
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for_each(v.begin(), v.end(), Mul2());
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	// ɾ��������3�ı���
	auto pos = remove_if(v.begin(), v.end(), Mod3());
	v.erase(pos, v.end());
	// �������е�Ԫ�ش�ӡ����
	// ע�⣺���ڹ��ܼ򵥵Ĳ���������ʹ��C++11�ṩ��lambda���ʽ������
	// lambda���ʽʵ�ּ򵥣����ڵײ���º�����ԭ����ͬ���������Ὣlambda���ʽת��Ϊ�º���
	for_each(v.begin(), v.end(), [](int data){cout << data << " "; });
	cout << endl;
	return 0;
}