//
//
///*��Ŀ1:
//һ������ΪN����������(N>2)���ҳ������������2��������Arr=[1,2,3],�����ֵΪ2X3=6������ 2,3
//ֻ��ʵ��һ���������������壺int fun(Arr){return �������2����;}
//*/
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int fun(vector<int> Arr)
//{
//	if (Arr.empty())
//		return 0;
//	int max = Arr[0], min = Arr[0];
//	int sec_max = 0, sec_min = 0;
//	for (int i = 1; i < Arr.size(); ++i)
//	{
//		//�����ʹδ������ֵ
//		if (Arr[i] > max){
//			sec_max = max;
//			max = Arr[i];
//		}
//		if (Arr[i] > sec_max && Arr[i] < max){
//			sec_max = Arr[i];
//		}
//
//		//����С�ʹ�С������ֵ
//		if (Arr[i] < min){
//			sec_min = min;
//			min = Arr[i];
//		}
//		if (Arr[i] < sec_min && Arr[i] > min){
//			sec_min = Arr[i];
//		}
//	}
//	return (max*sec_max) > (min*sec_min) ? (max*sec_max) : (min*sec_min);
//}
//
//int main()
//{
//	vector<int> v0{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	vector<int> v{ 1, 1, 2, 4, 5, 6 };
//	vector<int> v1{ -1, -1, -2, -4, -5, -6 };
//	vector<int> v2{ -3, -1, 0, 3 };
//	vector<int> v3{ -1, 0, 1 };
//	cout << fun(v0) << endl;
//	cout << fun(v) << endl;
//	cout << fun(v1) << endl;
//	cout << fun(v2) << endl;
//	cout << fun(v3) << endl;
//	return 0;
//}




/*��Ŀ2:
һ����С��M*N��С�İ�ɫ����P, ��M����*N����,ÿ��������r��g��b�� 3����ɫ���,ÿ����ɫֵ��0~255�����һ�����������ݽṹ��
���Զ�����ͼƬ����һ��ʵ�ľ��Ρ�������������� draw(P, �������ݣ� ������ɫ)����ӡ���ս���� 
��r,g,b��(r,g,b) (r,g,b).....
��r,g,b��(r,g,b) (r,g,b).....
��r,g,b��(r,g,b) (r,g,b).....
...
*/

#include<iostream>
#include<vector>
using namespace std;
  
//��һ���ṹ���ʶ���ص�
//Ҳ������һ��������ʾ������λͼӳ���˼��
struct pixel
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

void draw(vector<vector<pixel>>& P, int left, int right, int top, int low, int color)
{
	//								   r		g		b	
	//��һ��������ʾcolor 00000000 00000000 00000000 00000000
	//
	//Ҳ�����ýṹ������ʾ��Ҫ��ʾ����ɫ
	//�˴���һ��������ʾ�����ص���ɫ�����ֱ�����ø��Ӹ���

	pixel t;
	unsigned char x = 0;
	vector<unsigned char> v;
	
	//ȡ��ɫ����
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 8; ++j){
			x *= 10;
			x += (color & 1);
			color >>= 1;
		}
		v.push_back(x);
		x = 0;
	}
	t.b = v[0];
	t.g = v[1];
	t.r = v[2];
	//�ڻ����ϻ�ͼ
	for (int i = top; i <= low; ++i){
		//��ֹԽ��
		if (i >= P.size()) break;

		for (int j = left; j <= right; ++j){
			//��ֹԽ��
			if (j >= P[0].size()) break;
			P[i][j] = t;
		}
	}
}

int main()
{
	int M, N;
	M = 20;
	N = 20;
	vector<vector<pixel>> v;
	pixel t;
	t.r = 0;
	t.g = 0;
	t.b = 0;
	vector<pixel> temp;
	for (int i = 0; i < 20; ++i){
		temp.push_back(t);
	}
	for (int i = 0; i < 20; ++i){
		v.push_back(temp);
	}
	//     (�� �� �� ��)  
	draw(v, 5, 15, 5, 15, 0x00ffffff);
	draw(v, 0, 20, 0, 20, 0x00ffffff);
	return 0;
}