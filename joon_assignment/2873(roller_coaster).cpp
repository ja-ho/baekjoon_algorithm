#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

int r, c;

int map[1001][1001];

vector<char>A;
stack<char>B;
void go(int x, int y)
{
	pair<int, int> A_pos = make_pair(0, 0);
	pair<int, int> B_pos = make_pair(r - 1, c - 1);
	while (A_pos.first != B_pos.first && A_pos.second != B_pos.second) {
		if (x - A_pos.first > 1) {
			for (int j = 0; j < 2; j++) {
				for (int i = 0; i < c - 1; i++) {
					if (j == 0) A.push_back('R');
					else A.push_back('L');
				}
				A.push_back('D');
			}
			A_pos.first += 2;
		}
		if (B_pos.first - x > 1) {
			for (int j = 0; j < 2; j++) {
				for (int i = 0; i < c - 1; i++) {
					if (j == 1) B.push('L');
					else B.push('R');
				}
				if (j == 0) B.push('D');
			}
			B.push('D');
			B_pos.first -= 2;
		}
		if (B_pos.first - A_pos.first == 1) {
			if (y - A_pos.second > 1) {
				A.push_back('D'); A.push_back('R'); A.push_back('U'); A.push_back('R');
				A_pos.second += 2;
			}
			if (B_pos.second - y > 1) {
				B.push('D'); B.push('R'); B.push('U'); B.push('R');
				B_pos.second -= 2;
			}
			if (B_pos.second - A_pos.second == 1) {
				if (A_pos.second == y) {
					A.push_back('R'); A.push_back('D');
				}
				else {
					A.push_back('D'); A.push_back('R');
				}
				A_pos.first += 1; A_pos.second += 1;
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	if (r % 2 == 1 || c % 2 == 1) {
		if (r % 2 == 1) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c - 1; j++) {
					if (i % 2 == 0) {
						cout << 'R';
					}
					else {
						cout << 'L';
					}
				}
				if (i != r - 1)
					cout << 'D';
			}
		}
		else {
			for (int j = 0; j < c; j++) {
				for (int i = 0; i < r - 1; i++) {
					if (j % 2 == 1) {
						cout << 'U';
					}
					else cout << 'D';
				}
				if (j != c - 1) cout << 'R';
			}
		}

	}
	else {
		int x, y;
		int choose = 1000;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if ((i + j) % 2 == 1) {
					if (choose > map[i][j]) {
						choose = map[i][j];
						x = i; y = j;
					}
				}
			}
		}
		go(x, y);
		int a_length = A.size();
		int b_length = B.size();
		for (int i = 0; i < a_length; i++) {
			cout << A[i];
		}
		while (!B.empty()) {
			cout << B.top();
			B.pop();
		}
		cout << '\n';
	}
	return 0;
}