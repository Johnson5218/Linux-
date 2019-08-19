////���demoģ��ʵ��һ��smart_ptr
//
//#include<iostream>
//
//using namespace std;
//
//template <class T>
//class Smart_ptr
//{
//public:
//	Smart_ptr(T* str = nullptr)
//		:_str(str)
//	{}
//	~Smart_ptr()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//	T& operator*()
//	{
//		return *_str;
//	}
//
//	T* operator->()
//	{
//		return	_str;
//	}
//private:
//	T* _str;
//};
//
//
//struct time
//{
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Smart_ptr<int> s(new int);
//	*s = 10;
//	cout << *s << endl;
//
//	Smart_ptr<time> s1(new time);
//		
//	//���ﱾ��Ӧ����s1.operator->()->_year = 2019;
//	//Ϊ�˿ɶ��ԣ�����ֱ��д��s1->_year;
//	s1->_year = 2019;
//	s1->_month = 8;
//	s1->_day = 18;
//	return 0;
//}


//���demoģ��ʵ����auto_ptr
//#include<iostream>
//using namespace std;
//
//template <class T>
//class Auto_ptr
//{
//public:
//	Auto_ptr(T* str = nullptr)
//		:_str(str)
//	{}
//	~Auto_ptr()
//	{
//		if (_str)
//		{
//			delete _str;
//			_str = nullptr;
//		}
//	}
//
//	//һ�������������ͽ�����Ȩת�Ƹ���ǰ����Ȼ����ǰ���������Ŀռ�Ͽ���ϵ
//	//�����Ͳ�����ֶ���������һ�ݿռ�����⣬Ҳ�Ͳ�����ֶ�һ�ݵ�ַ�ͷŶ�ε�����
//	Auto_ptr(Auto_ptr<T>& str)
//		:_str(str._str)
//	{
//		if (&str != this)
//		{
//			str._str = nullptr;
//		}
//	}
//
//	Auto_ptr<T>& operator=(const Auto_ptr<T>& str)
//	{
//		if (str != *this)
//		{
//			if (_str)
//				delete _str;
//
//			_str = str._str;
//			str._str = nullptr;
//		}
//		return *this;
//	}
//
//	T* operator->()
//	{
//		return _str;
//	}
//
//	T& operator*()
//	{
//		return *_str;
//	}
//
//private:
//	T* _str;
//};
//
//
//
//int main()
//{
//	Auto_ptr<int> s(new int);
//	*s = 10;
//	Auto_ptr<int> s1(s);
//	cout << *s1 << endl;
//	return 0;
//}



////���demoģ��ʵ����unqiue_ptr
//#include<iostream>
//using namespace std;
//
//template <class T>
//class Unique_ptr
//{
//public:
//	Unique_ptr(T* str = nullptr)
//		:_str(str)
//	{}
//	~Unique_ptr()
//	{
//		if (_str)
//		{
//			delete _str;
//			_str = nullptr;
//		}
//	}
//	T& operator*()
//	{
//		return _str;
//	}
//
//	T* operator->()
//	{
//		return *_str;
//	}
//private:
//	//C++98��ʵ��
//	Unique_ptr(Unique_ptr<T> & str);
//	Unique_ptr& operator=(const Unique_ptr<T> & str);
//	/*
//	C++11��ʵ��
//	Unique_ptr(Unique_ptr<T> const str) = delete;
//	T& operator=(const Unique_ptr<T> const str) = delete;
//	*/
//
//private:
//	T* _str;
//};
//
//
//int main()
//{
//	Unique_ptr<int> s;
//	//Unique_ptr s1(s);
//	return 0;
//}


//
//#include<iostream>
//using namespace std;
//
////ʹ�ø�����
//template<class T>
//class SmartPtr;
//
///*
//�����������
//1�����ü�����_count;
//2��ָ��ʵ�ʿռ��ָ��_ptr;
//*/
//template<class T>
//class Asistant
//{
//	friend class SmartPtr<T>;
//private:
//	Asistant(T *ptr) :_count(1), _ptr(ptr)
//	{}
//	~Asistant(){
//		delete _ptr;
//		_ptr = NULL;
//	}
//	int _count;
//	T *_ptr;
//};
//
///*
//����ָ����:(����)
//1��ָ�������ָ��
//*/
//template<class T>
//class SmartPtr{
//public:
//	SmartPtr(T *ptr) :_p(new Asistant<T>(ptr))
//	{}
//	SmartPtr(const SmartPtr<T> &sp){
//		_p = sp._p;
//		_p->_count++;
//	}
//	SmartPtr& operator=(const SmartPtr<T> &sp){
//		if (this != &sp){
//			//�����ԭ���Ĺ�ϵ---->ע�⣺������롰ǰ�ޡ��Ĺ�ϵ
//			if (--(_p->_count) == 0){
//				delete _p;         //���ȵ��ø��������������(�ͷ�ʵ�ʿռ�),���ͷŸ��������ռ�
//			}
//			//ָ���µĸ����ռ�
//			_p = sp._p;
//			(_p->_count)++;
//		}
//		return *this;
//	}
//	~SmartPtr(){
//		if (--(_p->_count) == 0){
//			delete _p;
//			_p = NULL;
//		}
//	}
//	T* operator->(){
//		return _p->_ptr;
//	}
//	T& operator*(){
//		return *(_p->_ptr);
//	}
//
//private:
//	Asistant<T> *_p;
//};
//
//////////////////////////////////////////////////////////////////////////////
//
////��һ������ʵ������ָ��
//template<class T>
//class SmartPtr1{
//public:
//	SmartPtr1(T *ptr) :_countPtr(new int(1)), _ptr(ptr)
//	{}
//	~SmartPtr1(){
//		if (--(*_countPtr) == 0){
//			delete _ptr;
//			delete _countPtr;
//			_ptr = NULL;
//			_countPtr = NULL;
//		}
//	}
//	SmartPtr1(const SmartPtr1<T> &sp){
//		_countPtr = sp._countPtr;
//		++(*_countPtr);
//		_ptr = sp._ptr;
//	}
//	/*
//	operator=�Ĳ�����
//	1������Ը�ֵ
//	2������ǰ��һ�����ϡ�
//	3��ָ��������
//	4��return *this
//	*/
//	SmartPtr1& operator=(const SmartPtr1<T> &sp){
//		if (this != &sp){
//			if (--(*_countPtr) == 0){
//				delete _countPtr;
//				delete _ptr;
//				_countPtr = NULL;
//				_ptr = NULL;
//			}
//			_countPtr = sp._countPtr;
//			++(*_countPtr);
//			_ptr = sp._ptr;
//		}
//		return *this;
//	}
//	T* operator->(){
//		return _ptr;
//	}
//	T& operator*(){
//		return *_ptr;
//	}
//private:
//	int *_countPtr;//ָ�����ü�����ָ��
//	T *_ptr;       //ָ��ʵ�ʿռ��ָ��
//};
//
//
//
////����ָ�룺ָ���ѱ��ͷſռ��ָ��
//void HangPtr()
//{
//	int *ptr1 = new int(10);
//	int *ptr2 = ptr1;
//	int *ptr3 = ptr1;
//
//	cout << "before delete:" << endl;
//	cout << *ptr1 << endl;
//	cout << *ptr2 << endl;
//	cout << *ptr3 << endl;
//
//	cout << "after delete:" << endl;
//	delete ptr1;
//	cout << *ptr2 << endl;//��ָ��Ŀռ��ѱ��ͷ�--->����ָ�룬���������ָ�տɴ���
//	cout << *ptr3 << endl;
//}
//
////SmartPtr
////-------------------> SmartPtr <---------------------------
////���Կ������캯��
//void test1(){
//	int *p = new int(10);
//	SmartPtr<int> sp(p);
//	{
//		SmartPtr<int> sp1(sp);
//	}
//	SmartPtr<int> sp2(sp);
//}
//
////����operator=
//void test2()
//{
//	int *p = new int(10);
//	SmartPtr<int> ptr(p);
//
//	int *p1 = new int(20);
//	SmartPtr<int> ptr1(p1);
//
//	ptr1 = ptr;
//	cout << *ptr << endl;
//	cout << *ptr1 << endl;
//}
//
////-------------------> SmartPtr1 <---------------------------
////���Կ������캯��
//void test3(){
//	int *p = new int(10);
//
//	SmartPtr1<int> sp(p);
//	{
//		SmartPtr1<int> sp1(sp);
//	}
//	SmartPtr1<int> sp2(sp);
//}
//
////����operator=
//void test4()
//{
//	int *p = new int(10);
//	SmartPtr<int> ptr(p);
//
//	int *p1 = new int(20);
//	SmartPtr<int> ptr1(p1);
//
//	ptr1 = ptr;
//	cout << *ptr << endl;
//	cout << *ptr1 << endl;
//}
//int main()
//{
//	test4();
//	system("pause");
//	return 0;
//}

//// 1.��ʾ���ü����̰߳�ȫ���⣬�Ͱ�AddRefCount��SubRefCount�е���ȥ��
//// 2.��ʾ���ܲ������̰߳�ȫ���⣬��Ϊ�̰߳�ȫ������ż�������⣬main������n�Ĵ�һЩ���ʾͱ���ˣ������׳����ˡ�
//// 3.�����������ʹ��SharedPtr��ʾ����Ϊ�˷�����ʾ���ü������̰߳�ȫ���⣬�������е�SharedPtr����sshared_ptr���в��ԣ�������֤���shared_ptr�����ֽ�����һ���ġ�
//void SharePtrFunc(SharedPtr<Date>& sp, size_t n) {
//	cout << sp.Get() << endl;
//	for (size_t i = 0; i < n; ++i)
//	{
//		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
//		SharedPtr<Date> copy(sp);
//		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ�������
//		�տ����Ľ������һ���Ǽ���2n
//			copy->_year++;
//		copy->_month++;
//		copy->_day++;
//	}
//}
//int main()
//{
//	SharedPtr<Date> p(new Date);
//	cout << p.Get() << endl;
//	const size_t n = 100;
//	thread t1(SharePtrFunc, p, n);
//	thread t2(SharePtrFunc, p, n);
//	t1.join();
//	t2.join();
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//	return 0;
//}



//struct ListNode
//{
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//	~ListNode(){ cout << "~ListNode()" << endl; }
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}


// �º�����ɾ����
template<class T>
struct FreeFunc {
	void operator()(T* ptr)
	{
		cout << "free:" << ptr << endl;
		free(ptr);
	}
};
template<class T>
struct DeleteArrayFunc {
	void operator()(T* ptr)
	{
		cout << "delete[]" << ptr << endl;
		delete[] ptr;
	}
};
int main()
{
	FreeFunc<int> freeFunc;
	shared_ptr<int> sp1((int*)malloc(4), freeFunc);
	DeleteArrayFunc<int> deleteArrayFunc;
	shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);
	return 0;
}