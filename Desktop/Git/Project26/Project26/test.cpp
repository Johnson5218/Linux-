#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string s = "asjfhbaskufhsa";
	string res{ s.begin(), s.end() };
	return 0;
}



class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//���Ĵ���ʼλ��
		int max = 1;//���Ĵ���󳤶�
		vector<vector<int>>  dp(len, vector<int>(len));//�����ά��̬����
		for (int i = 0; i<len; i++)//��ʼ��״̬
		{
			dp[i][i] = 1;
			if (i<len - 1 && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				max = 2;
				start = i;
			}
		}
		for (int i = 3; i <= len; i++)//i��ʾ�������Ӵ����ȣ�����3��ʾ�ȼ�������Ϊ3���Ӵ�
		{
			for (int j = 0; i + j - 1 < len; j++)
			{
				int k = i + j - 1;//��ֹ�ַ�λ��
				if (s[j] == s[k] && dp[j + 1][k - 1] == 1)//״̬ת��
				{
					dp[j][k] = 1;
					start = j;
					max = i;
				}
			}
		}
		return s.substr(start, max);//��ȡ������Ӵ�
	}
};


class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//��¼�����Ӵ���ʼλ��
		int end = 0;//��¼�����Ӵ���ֹλ��
		int mlen = 0;//��¼�������Ӵ��ĳ���
		for (int i = 0; i<len; i++)
		{
			int len1 = expendaroundcenter(s, i, i);//һ��Ԫ��Ϊ����
			int len2 = expendaroundcenter(s, i, i + 1);//����Ԫ��Ϊ����
			mlen = max(max(len1, len2), mlen);
			if (mlen>end - start + 1)
			{
				start = i - (mlen - 1) / 2;
				end = i + mlen / 2;
			}
		}
		return s.substr(start, mlen);
		//�ú�������˼�ǻ�ȡ��start��ʼ����Ϊmlen���ȵ��ַ���
	}
private:
	int expendaroundcenter(string &s, int left, int right)
		//������left��rightΪ���ĵĻ��Ĵ�����
	{
		int L = left;
		int R = right;
		while (L >= 0 && R<s.length() && s[R] == s[L])
		{
			L--;
			R++;
		}
		return R - L - 1;
	}
};