#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	//int t = srand(time(0)) % 5;
	switch ((rand()%5)*101010101%5)
	{
	case 1:
		cout << "�Ը����" << endl;
		break;
	case 2:
		cout << "�Թ���" << endl;
		break;
	case 3:
		cout << "������" << endl;
		break;
	case 4:
		cout << "����" << endl;
		break;
	case 5:
		cout << "�ǽ���" << endl;
		break;
	default:
		break;
	}
	return 0;
}