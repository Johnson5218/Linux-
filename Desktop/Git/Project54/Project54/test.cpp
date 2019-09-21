//#include<iostream>
//using namespace std;
//class CExample
//{
//private:
//	int a;
//public:
//	//���캯��
//	CExample(int b)
//	{
//		//a = b;
//		printf("constructor is called\n");
//	}
//	//�������캯��
//	CExample(const CExample & c)
//	{
//		a = c.a;
//		printf("copy constructor is called\n");
//	}
//	//��������
//	~CExample()
//	{
//		cout << "destructor is called\n";
//	}
//	void Show()
//	{
//		cout << a << endl;
//	}
//};
//CExample g_fun()
//{
//	CExample temp(0);
//	return temp;
//}
//int main()
//{
//
//	g_fun();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class CExample
//{
//private:
//	int a;
//public:
//	CExample(int b)
//	{
//		a = b;
//		printf("constructor is called\n");
//	}
//	CExample(const CExample & c)
//	{
//		a = c.a;
//		printf("copy constructor is called\n");
//	}
//	~CExample()
//	{
//		cout << "destructor is called\n";
//	}
//	void Show()
//	{
//		cout << a << endl;
//	}
//};
//void g_fun(CExample c)
//{
//	cout << "g_func" << endl;
//}
//int main()
//{
//	CExample A(100);
//	CExample B = A;
//	B.Show();
//	g_fun(A);
//	return 0;
//}


//#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string>
//#include<sstream>
//using namespace std;
//int main()
//{
//	char* s = "aisufbhiaubnf";
//	int a;
//	stringstream str;
//	str << s;
//	str >> a;
//	cout << a << endl;
//	return 0;
//}


#include<iostream>
#include<algorithm>
using namespace std;


int SelectPivot(int arr[], int low, int high)
{
	return arr[low];//ѡ��ѡȡ���еĵ�һ��Ԫ����Ϊ��׼
}


/*���ѡ�������λ�ã�������low��high֮��*/
int SelectPivotRandom(int arr[], int low, int high)
{
	//���������λ��
	srand((unsigned)time(NULL));
	int pivotPos = rand() % (high - low) + low;

	//������λ�õ�Ԫ�غ�lowλ��Ԫ�ػ�������ʱ���Ժ���ͨ�Ŀ���һ�����û��ֺ���
	swap(arr[pivotPos], arr[low]);
	return arr[low];
}



/*�������ã�ȡ������������low��mid��high����λ�������ݣ�ѡȡ�����м���Ǹ�������Ϊ����*/
int SelectPivotMedianOfThree(int arr[], int low, int high)
{
	int mid = low + ((high - low) >> 1);//���������м��Ԫ�ص��±�

	//ʹ������ȡ�з�ѡ������
	if (arr[mid] > arr[high])//Ŀ��: arr[mid] <= arr[high]
	{
		swap(arr[mid], arr[high]);
	}
	if (arr[low] > arr[high])//Ŀ��: arr[low] <= arr[high]
	{
		swap(arr[low], arr[high]);
	}
	if (arr[mid] > arr[low]) //Ŀ��: arr[low] >= arr[mid]
	{
		swap(arr[mid], arr[low]);
	}
	//��ʱ��arr[mid] <= arr[low] <= arr[high]
	return arr[low];
	//low��λ���ϱ���������λ���м��ֵ
	//�ָ�ʱ����ֱ��ʹ��lowλ�õ�Ԫ����Ϊ���ᣬ�����øı�ָ����
}

void QSort(int arr[], int low, int high)
{
	int first = low;
	int last = high;

	int left = low;
	int right = high;

	int leftLen = 0;
	int rightLen = 0;

	if (high - low + 1 < 10)
	{
		InsertSort(arr, low, high);
		return;
	}

	//һ�ηָ�
	int key = SelectPivotMedianOfThree(arr, low, high);//ʹ������ȡ�з�ѡ������

	while (low < high)
	{
		while (high > low && arr[high] >= key)
		{
			if (arr[high] == key)//�������Ԫ��
			{
				swap(arr[right], arr[high]);
				right--;
				rightLen++;
			}
			high--;
		}
		arr[low] = arr[high];
		while (high > low && arr[low] <= key)
		{
			if (arr[low] == key)
			{
				swap(arr[left], arr[low]);
				left++;
				leftLen++;
			}
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = key;

	//һ�ο��Ž���
	//��������key��ͬ��Ԫ���Ƶ���������λ����Χ
	int i = low - 1;
	int j = first;
	while (j < left && arr[i] != key)
	{
		swap(arr[i], arr[j]);
		i--;
		j++;
	}
	i = low + 1;
	j = last;
	while (j > right && arr[i] != key)
	{
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	QSort(arr, first, low - 1 - leftLen);
	QSort(arr, low + 1 + rightLen, last);
}