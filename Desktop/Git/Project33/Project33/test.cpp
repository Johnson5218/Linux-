//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//
//int main()
//{
//	int len = s.size();
//	if (len == 0 || len == 1)
//		return s;
//	int start = 0;//���Ĵ���ʼλ��
//	int max = 1;//���Ĵ���󳤶�
//	vector<vector<int>>  dp(len, vector<int>(len));//�����ά��̬����
//	for (int i = 0; i<len; i++)//��ʼ��״̬
//	{
//		dp[i][i] = 1;
//		if (i<len - 1 && s[i] == s[i + 1])
//		{
//			dp[i][i + 1] = 1;
//			max = 2;
//			start = i;
//		}
//	}
//	for (int i = 3; i <= len; i++)//i��ʾ�������Ӵ����ȣ�����3��ʾ�ȼ�������Ϊ3���Ӵ�
//	{
//		for (int j = 0; i + j - 1 < len; j++)
//		{
//			int k = i + j - 1;//��ֹ�ַ�λ��
//			if (s[j] == s[k] && dp[j + 1][k - 1] == 1)//״̬ת��
//			{
//				dp[j][k] = 1;
//				start = j;
//				max = i;
//			}
//		}
//	}
//	return s.substr(start, max);//��ȡ������Ӵ�
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	int count = 0;
	if (m == 1)
	{
		for (auto e : v)
			count += *e;
	}
	while (1)
	{

	}
	cout << n << endl;
}