#include <iostream>
#include <vector>
using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		//��ʱ�࿪��һ���ռ�
		_bits.resize(range / 32 + 1);
	}
	void Set(size_t x)
	{
		int index = x / 32;//ȷ���ĸ����ݣ����䣩
		int temp = x % 32;//ȷ���ĸ�Bitλ
		_bits[index] |= (1 << temp);//λ��������
	}
	void Reset(size_t x)
	{
		int index = x / 32;
		int temp = x % 32;
		_bits[index] &= ~(1 << temp);//ȡ��
	}
	bool Test(size_t x)
	{
		int index = x / 32;
		int temp = x % 32;
		if (_bits[index] & (1 << temp))
			return 1;
		else
			return 0;
	}

private:
	vector<int> _bits;
};

void TestBitMap()
{
	BitMap am(-1);
	BitMap bm(200);
	bm.Set(136);
	bm.Set(1);
	cout << bm.Test(136) << endl;
	bm.Reset(136);
	cout << bm.Test(136) << endl;
}

int main()
{
	TestBitMap();
	return 0;
}