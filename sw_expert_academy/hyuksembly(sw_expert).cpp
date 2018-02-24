#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int Answer;

char code[21][21];
int R, C;

typedef struct _cur_info {
	int dir;
	int i;
	int j;
} cur_info;

void move(int dir, int *i, int *j) {
	if (dir == 1) {
		if (*j - 1 >= 0) *j -= 1;
		else *j = R - 1;
	}
	else if (dir == 2) {
		if (*i + 1 < C) *i += 1;
		else *i = 0;
	}
	else if (dir == 3) {
		if (*j + 1 < R) *j += 1;
		else *j = 0;
	}
	else {
		if (*i - 1 >= 0) *i -= 1;
		else *i = C - 1;
	}
}


bool go()
{
	int memory;
	int cnt;
	queue<cur_info> info;
	cur_info temp;
	bool over = false;
	cnt = 0;
	memory = 0;
	//1 == up, 2 == right, 3 == down, 4 == left
	temp.dir = 2;
	temp.i = 0;
	temp.j = 0;
	info.push(temp);

	while (!info.empty()) {
		if (cnt > 500) break;
		int dir = info.front().dir;
		int i = info.front().i; int j = info.front().j;
		info.pop();
		char cur = code[j][i];
		if (cur == '0' || cur == '1' || cur == '2' || cur == '3' || cur == '4' || cur == '5' || cur == '6'
			|| cur == '7' || cur == '8' || cur == '9') {
			memory = atoi(&cur);
		}
		else if (cur == '>' || cur == '<' || cur == '^' || cur == 'v') {	//1 == up, 2 == right, 3 == down, 4 == left
			if (cur == '>') dir = 2;
			else if (cur == '<') dir = 4;
			else if (cur == '^') dir = 1;
			else if (cur == 'v') dir = 3;
		}
		else if (cur == '_' || cur == '|') {
			if (cur == '_') {
				if (memory == 0) dir = 2;
				else dir = 4;
			}
			else {
				if (memory == 0) dir = 3;
				else dir = 1;
			}
		}
		else if (cur == '.');
		else if (cur == '+' || cur == '-') {
			if (cur == '+') {
				if (memory == 15) memory = 0;
				else memory++;
			}
			else {
				if (memory == 0) memory = 15;
				else memory--;
			}
		}
		else if (cur == '@') {
			over = true;
			break;
		}
		else if (cur == '?') {
			for (int k = 1; k <= 4; k++) {
				int temp_i = i;
				int temp_j = j;
				dir = k;
				move(dir, &temp_i, &temp_j);
				temp.dir = dir;
				temp.i = temp_i; temp.j = temp_j;
				info.push(temp);

				cnt++;
			}
			continue;
		}
		move(dir, &i, &j);
		temp.dir = dir;
		temp.i = i; temp.j = j;
		info.push(temp);
		cnt++;
	}
	return over;
}

int main() {
	int T, tc;
	cin >> T;
	for (tc = 0; tc < T; tc++) {
		scanf("%d %d", &R, &C);

		for (int i = 0; i < R; i++) {
			scanf("%s", code[i]);
		}

		if (go()) {
			cout << "#" << tc + 1 << " YES" << endl;
		}
		else {
			cout << "#" << tc + 1 << " NO" << endl;
		}

	}
	return 0;
}