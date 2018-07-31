#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool map[16][16];
bool col[16];
bool dig[31];
bool dig_2[31];
int n;
int answer;

bool check(int i, int j)
{
	if (map[i][j]) return false;
	if (col[j]) return false;
	if (dig[i + j]) return false;
	if (dig_2[i - j + n]) return false;
	return true;
}



void go(int index)
{
	if (index == n) {
		answer++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check(index, i)) {
			map[index][i] = true;
			col[i] = true;
			dig[index + i] = true;
			dig_2[index - i + n] = true;
			go(index + 1);
			map[index][i] = false;
			dig[index + i] = false;
			dig_2[index - i + n] = false;
			col[i] = false;
		}
	}
	return;
}

int main() {
	cin >> n;
	go(0);
	cout << answer << '\n';
	return 0;
}