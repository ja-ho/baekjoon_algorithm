#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int preprocessing(char *board)
{
	//int m = sizeof(board) / sizeof(char) + 1;  wrong
	int m = strlen(board);
	vector<int> pi(m);
	int j = 0;
	pi[0] = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && board[i] != board[j]) {
			j = pi[j - 1];
		}
		if (board[i] == board[j]) {
			pi[i] = j + 1;
			j++;
		}
		else {
			pi[i] = 0;
		}
	}
	return pi[m - 1];
}

int main() {
	int l;
	char board[1000003];

	//cin >> l;
	//cin.get();
	//cin.getline(board, l + 2);
	cin >> l >> board;
	cout << l - preprocessing(board) << '\n';
	return 0;
}