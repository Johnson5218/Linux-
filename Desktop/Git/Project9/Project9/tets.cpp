//#include<iostream>
//
//using namespace std;
//int main()
//{
//
//	int i = 10;
//	double d = i;
//	cout << d << "   " << i << endl;
//	int *t = &i;
//	int addr = (int)t;
//	cout << addr << "        " << *t << endl;
//	return 0;
//}

//static_cast��reinterpret_cast��const_cast��dynamic_cast



//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	double d = 1.34;
//	int i = static_cast<int> (d);
//	cout << d << endl;
//	cout << i << endl;
//	return 0;
//}
//


//#include<iostream>
//using namespace std;
//
//typedef void(*FUNC)();
//int DoSomething(int i)
//{
//	cout << "DoSomething" << endl;
//	return 0;
//}
//void Test()
//{
//	//
//	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����
//	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������
//	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��
//	//
//	FUNC f = reinterpret_cast< FUNC>(DoSomething);
//	f();
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//const_cast

//#include<iostream>
//using namespace std;
//
//
//int main()
//{
//	const int a = 4;
//	cout << "a = " << a << endl;
//	cout << endl;
//	int *i = const_cast<int*>(&a);
//	*i = 3;
//	cout << "a = " << a << endl;
//	cout << "i = " << *i << endl;
//	return 0;
//}

//dynamic_cast

/*
dynamic_cast���ڽ�һ����������ָ��ת��Ϊ��������ָ�������(��̬ת��)
����ת�ͣ��������ָ��->����ָ��/����(����Ҫת������ֵ���ݹ���) 
����ת�ͣ��������ָ��->����ָ��/����(��dynamic_castת���ǰ�ȫ��)
ע�⣺ 
1. dynamic_castֻ�����ں����麯������ 
2. dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�0
*/
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void f(){}
//};
//class B : public A
//{};
//void fun(A* pa)
//{
//	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}
//int main()
//{
//	A a; B b;
//	fun(&a);
//	fun(&b);
//	return 0;
//}


#include<iostream>
using namespace std;

class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};
int main()
{
	A a1(1);
	// ��ʽת��-> A tmp(1); A a2(tmp);
	//A a2 = 1;
}