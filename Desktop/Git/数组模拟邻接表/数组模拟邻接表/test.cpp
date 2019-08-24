/*������ͻȻ�Ż��ˣ��ֳ���Ҫ������ɢ�����ǹ��������̫խ�ˣ�ͬʱֻ������һ����ͨ��������֪������������������λ�ֲ�����λ�ֲ�ͼ��һ��������֪ÿ����λ�϶�����һ���ˣ���ȫ���������ĸ�����Ҳ����1�Ž���λ���ϡ������ڵ��ϵ���ÿ�붼����������ǰ��һ����㣬���ǳ��˰�ȫ�������⣬û���κ�һ��������ͬʱ�������������ϵ��ˣ������Ҫһ�ֲ��ԣ���ʹ����Ⱥ������ɢ�����ڲ�ȡ���Ų��Ե�����£��������������ڶ೤ʱ������ɢ��ɡ�


��������:
��һ�а���һ��������n�������Ľ��������1<=n<=100000���� ��������n-1�У�ÿ��������������x��y����ʾ��x��y���֮�����һ���ߡ�(1<=x��y<=n)

�������:
���������һ������������ʾ����Ҫ�����ʱ��

��������1:
6
2 1
3 2
4 3
5 2
6 1

�������1:
4
*/


#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
struct Edge {
	int to, next;
} edge[M];

int head[N], idx, n;

void add(int a, int b)
{
	edge[idx].to = b;
	edge[idx].next = head[a];
	head[a] = idx++;
}
//�������
int dfs(int u, int fa)
{
	int res = 1;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		if (edge[i].to != fa) res += dfs(edge[i].to, u);
	}
	return res;
}
int main()
{
	cin >> n;
	memset(head, -1, sizeof head);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	int res = 0;
	for (int i = head[1]; ~i; i = edge[i].next)
		res = max(res, dfs(edge[i].to, 1));
	cout << res << endl;
	return 0;
}






/*

int q[N];
bool visited[N];
int bfs(int u)
{
	int hh = 0, tt = 0;
	q[0] = u;
	visited[u] = true;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = head[t]; ~i; i = edge[i].next)
		{
			int son = edge[i].to;
			if (!visited[son])
			{
				q[++tt] = son;
				visited[son] = true;
			}
		}
	}
	return tt + 1;
}
int main()
{
	...
		visited[1] = true;
	for (int i = head[1]; ~i; i = edge[i].next)
		res = max(res, bfs(edge[i].to));
	cout << res << endl;
	return 0;
}
*/

/*����m���ַ���S1��S2��...��Sm��һ���������ַ���T������T��ѡ�������ܶ���Ӵ�ͬʱ���㣺 
1����Щ�Ӵ���T�л����ཻ��
2����Щ�Ӵ�����S1��S2��...��Sm�е�ĳ������  �������ѡ�����ٸ��Ӵ���


��������:
��һ��һ����m��1��m��10����������m�У�ÿ��һ���������һ������һ����T�����������е������ĳ��Ȳ�����100000������ֻ�����Сд��ĸ��

�������:
���һ�����������ѡ�����ٴ���

��������1:
3
aa
b
ac
bbaac

�������1:
3*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxCount(vector<string>& sub, string& src) {
	vector<int> result(src.length() + 1, 0);
	sort(sub.begin(), sub.end(), [](string& s1, string& s2)->bool {return s1.length() < s2.length(); });
	int maxLen;
	for (int i = 1; i <= src.length(); i++) {
		maxLen = 0;
		for (int j = 0; j < sub.size() && sub[j].length() <= i; j++) {
			int k = sub[j].length() - 1;
			for (; k >= 0; --k) {
				if (sub[j][k] != src[i - sub[j].length() + k]) {
					break;
				}
			}
			if (k == -1) {
				maxLen = result[i - sub[j].length()] + 1;
				break;
			}
		}
		result[i] = max(maxLen, result[i - 1]);
	}
	return result[src.length()];
}


int main() {
	int nums;
	vector<string> subStrs;
	string terget;

	cin >> nums;
	for (int i = 0; i < nums; i++) {
		cin >> terget;
		subStrs.push_back(terget);
	}
	cin >> terget;
	cout << maxCount(subStrs, terget);
}
