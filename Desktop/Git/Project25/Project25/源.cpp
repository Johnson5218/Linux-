#include<iostream>
#include<vector>
using namespace std;

struct node{
	int to;    //�յ� 
	int v;     //Ȩ 
}rt;
vector<node>v[10];
void add(int a, int b, int c){  //��a��b��һ��Ȩc�ı� 
	rt.to = b, rt.v = c;
	v[a].push_back(rt);
}

int main()
{
	add(1, 1, 1);
	add(1, 2, 1);
	add(1, 3, 1);
	add(1, 4, 1);
	add(1, 5, 1);
	add(1, 6, 1);
	add(1, 7, 1);
	return 0;
}