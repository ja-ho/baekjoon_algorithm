#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int r, c;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

char map[21][21];
bool alphabet[26];

int go(int x, int y)
{
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (alphabet[map[nx][ny] - 'A']) continue;
		alphabet[map[nx][ny] - 'A'] = true;
		int next = go(nx, ny);
		alphabet[map[nx][ny] - 'A'] = false;
		if (ans < next) ans = next;
	}

	return ans + 1;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}
	alphabet[map[0][0] - 'A'] = true;
	int answer = go(0, 0);
	cout << answer << '\n';
	return 0;
}