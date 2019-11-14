#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool helper(vector<vector<char>>& board, string& word, int i, int j, int length){
		if (i >= board.size() || j >= board[0].size() || i<0 || j<0 || length >= word.size() || word[length] != board[i][j]){
			return false;
		}
		if (length == word.size() - 1 && word[length] == board[i][j]){
			return true;
		}
		char temp = board[i][j];
		board[i][j] = '-';//�ҵ�֮������޸�һ��ֵ
		bool flag = helper(board, word, i, j + 1, length + 1) || helper(board, word, i, j - 1, length + 1) || helper(board, word, i + 1, j, length + 1) || helper(board, word, i - 1, j, length + 1);
		board[i][j] = temp;//����֮���ٸ��ָ�
		return flag;
	}
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i<board.size(); i++){
			for (int j = 0; j<board[0].size(); j++){
				if (helper(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	vector<vector<char>> v{ { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
	string str = "hello";
	bool ok = s.exist(v, "hello");
	cout << ok << endl;
	return 0;
}