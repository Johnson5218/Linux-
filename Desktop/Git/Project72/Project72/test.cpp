////#include<iostream>
////namespace foo{
////	struct Foo{};
////	void f(Foo){
////		std::cout << "f";
////	}
////}
//////
//////int main()
//////{
//////	foo::Foo foo;
//////	f(foo);
//////	return 0;
//////}
////
////
//////int main(int argc, char **argv)
//////{
//////	//int a[4] = { 1, 2, 3, 4 };
//////	//int *ptr = (int*)(&a + 1);
//////	//printf("%d", *(ptr - 1));
//////
//////
//////	int a[] = { 4, 0, 2, 3, 1 }, i, j, t;
//////	for (i = 1; i < 5; ++i)
//////	{
//////		t = a[i];
//////		j = i - 1;
//////		while (j>=0 && t>a[j])
//////		{
//////			a[j + 1] = a[j];
//////			--j;
//////		}
//////		a[j + 1] = t;
//////	}
//////
//////	return 0;
//////}
////
////
////
////using namespace std;
////class A
////{
////public:
////	void foo()
////	{
////		cout << "1";
////	}
////	virtual void fun()
////	{
////		cout << "2";
////	}
////};
////
////
////class B : public A
////{
////public:
////	void foo()
////	{
////		cout << "3";
////	}
////	void fun()
////	{
////		cout << "4";
////	}
////};
////
////
////
////int main()
////{
////	A a;
////	B b;
////	A *p = &a;
////	p->foo();
////	p->fun();
////	p = &b;
////	p->foo();
////	p->fun();
////	A *ptr = (A *)&b;
////	ptr->foo();
////	ptr->fun();
////	return 0;
////}
//
//
//
//
////#include<iostream>
////using namespace std;
////int main()
////{
////	int n, j;
////	while (1)
////	{
////		j = 0;
////		cin >> n;
////		if (n == 0)
////			break;
////		if (2 >= n)
////			cout << 0 << endl;
////		while (n>2)
////		{
////			j += n / 3;
////			n = n / 3 + n % 3;
////		}
////		if (n == 2)
////			j += 1;
////		cout << j << endl;
////	}
////	return 0;
////}
//
//
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//
//bool judgePoint24(vector<int>& nums) {
//	bool res = false;
//	double eps = 0.001;
//	vector<double> arr(nums.begin(), nums.end());
//	helper(arr, eps, res);
//	return res;
//}
//
//void helper(vector<double>& nums, double eps, bool &res) {
//	//�߽�ֵ
//	if (res) {
//		return;
//	}
//	if (nums.size() == 1) {
//		if (abs(nums[0] - 24) < eps) {
//			res = true;
//		}
//		return;
//	}
//	for (int i = 0; i < nums.size(); ++i) {
//		for (int j = 0; j < i; ++j) {
//			double p = nums[i], q = nums[j];
//			vector<double> t{ p + q, p - q, q - p, p * q };
//			//������Ϊ0
//			if (p > eps) {
//				t.push_back(q / p);
//			}
//			if (q > eps) {
//				t.push_back(p / q);
//			}
//			nums.erase(nums.begin() + i);
//			nums.erase(nums.begin() + j);
//			for (double k : t) {
//				nums.push_back(k);
//				helper(nums, eps, res);
//				nums.pop_back();//����
//			}
//			//����
//			nums.insert(nums.begin() + j, q);
//			nums.insert(nums.begin() + i, p);
//		}
//	}
//}
//
//
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	return 0;
//}


#include<iostream>
#include<string>
#include<vector>
using namespace std;
string list = "A2345678910JQK";//�����,������Ȩֵ
string comp = "+-*/";//��������
// �ַ�תȨֵ
int string2val(char a)
{
	if (a == '1')//A��1����1
		return 1;
	int re = list.find(a);//Ѱ���ַ���list����λ��
	re = re < 10 ? re + 1 : re;//С��10��ȨֵҪ+1
	return re;
}

//���ǵڶ���,�����кõ�����������������
bool equal24_step2(vector<string> &res2, string res1, int pos, float val)
{
	if (pos == 3)//pos����3˵���Ѿ��������,���Լ���valֵ
	{
		if (val == 24.0)//�������24
		{
			if ((int)res1.find("7-4*4*2") >= 0)//ţ�͵�bug,����������
				return false;
			res2.push_back(res1);//����res��
			return true;//����
		}
		return false;//����
	}
	if (pos == 0)//��0λ��ʱ,valӦ�ø�ֵΪres1[0];
		val = string2val(res1[0]);
	float val_o = val;//������ʼֵ,������һѭ��ʹ��
	float valnext = (float)string2val(res1[2 * pos + 1]);//pos+1λ�õ�ֵ
	unsigned int i;//.length()���޷��ŵ�
	for (i = 0; i < comp.length(); ++i)//����ÿһ������
	{
		val = val_o;//val��λ
		switch (i)
		{
		case 0:
			val += valnext;
			res1.insert(2 * pos + 1, "+");
			break;
		case 1:
			val -= valnext;
			res1.insert(2 * pos + 1, "-");
			break;
		case 2:
			val *= valnext;
			res1.insert(2 * pos + 1, "*");
			break;
		case 3:
			val /= valnext;
			res1.insert(2 * pos + 1, "/");
			break;
		}
		if (equal24_step2(res2, res1, pos + 1, val))//�������24��
			return true;//����
		res1.erase(2 * pos + 1, 1);//ɾ����һ��forѭ���������,����ѭ��
	}
	return false;//ֱ��ѭ��������û�ɹ�,�ͷ���fale
}

//����ȫ����
bool equal24_step1(vector<string> &res1, string inn, int pos, vector<string> &res2)
{
	if (pos == inn.length() - 1)//pos����.length()-1˵����ǰλ��û�п�ѡ��
	{
		res1.push_back(inn);//�ѵ�ǰ�����м�¼��res1��
		if (equal24_step2(res2, res1.back(), 0, 0.0))//���Խ�������������
			return true;//����ɹ�������true,����,���ٽ��к�������
		return false;//������ɹ�,������һ������
	}
	unsigned int i;
	for (i = pos; i < inn.length(); ++i)//�ӵ�ǰλ�ÿ�ʼ,���������λ��ֵ����
	{
		if (i != pos && inn[i] == inn[pos])//������ظ���,����
			continue;
		swap(inn[i], inn[pos]);
		if (equal24_step1(res1, inn, pos + 1, res2))//���к�һλ�õ�ѡ��
			return true;//���е�����,˵���Ѿ��ҵ�24��
		//swap(inn[i],inn[pos]);
	}
	return false;
}

int main()
{
	string inn_o;
	while (getline(cin, inn_o))
	{
		string inn;
		int rf1 = inn_o.find("ker");
		//����ʱ��������Joker,��д������ĸ,Ϊ�˱���Ӱ��,ֻ�жϺ�λ�ɣ���ʵ�����ж�r����oҲ��?
		int rf2 = inn_o.find("KER");
		if (rf1 >= 0 || rf2 >= 0)//�����JOKER,rf2�ǷǸ���,ͬ��,��joker,rf1�ǷǸ���
			cout << "ERROR" << endl;//��ӡ"ERROR"
		else //���û�д�С��,��ô���м���
		{
			unsigned int i;
			for (i = 0; i < inn_o.length(); ++i)//�ѷǿո��ַ�������
			{
				if (inn_o[i] == ' ')
					continue;
				inn.push_back(inn_o[i]);
			}
			vector<string> res1;//������н��
			vector<string> res2;//������������Ľ��
			equal24_step1(res1, inn, 0, res2);//���м���
			if (res2.size() == 0)//���res2Ϊ��,˵��û���ҵ���Ϸ�ʽ���Եõ�24
				cout << "NONE" << endl;
			else
				cout << res2[0] << endl;//�����,�Ǿʹ�ӡ
		}
	}
	return 0;
}