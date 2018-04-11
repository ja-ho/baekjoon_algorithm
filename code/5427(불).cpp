#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int t;
int w, h;

typedef struct _point {
	int x;
	int y;
	int seconds;
	bool type;		//0 == fire, 1 == me
} point;

char map[1003][1003];
bool visit[1003][1003];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

pair<int, int>start_point;
int Answer;
queue<point>q;


int go()
{
	point temp;
	temp.x = start_point.first;
	temp.y = start_point.second;
	temp.seconds = 0;
	temp.type = 1;
	q.push(temp);
	visit[temp.y][temp.x] = true;

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		int current_x = temp.x;
		int current_y = temp.y;
		int current_seconds = temp.seconds;
		bool type = temp.type;

		if (type && (current_x >= w - 1|| current_x <= 0 || current_y >= h - 1 || current_y <= 0)) {
			return current_seconds + 1;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = current_x + dx[i];
			int ny = current_y + dy[i];
			
			if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
			if (map[ny][nx] == '#' || map[ny][nx] == '*') continue;
			if (visit[ny][nx]) continue;
			if (type) {
				visit[ny][nx] = true;
			}
			else {
				map[ny][nx] = '*';
			}
			temp.x = nx; temp.y = ny;
			temp.seconds = current_seconds + 1; temp.type = type;
			q.push(temp);
		}
	}
	return 0;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> w >> h;
		while (!q.empty()) {
			q.pop();
		}
		for (int i = 0; i < h; i++) {
			cin >> map[i];
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '*') {
					point temp;
					temp.x = j;
					temp.y = i;
					temp.seconds = 0;
					temp.type = 0;
					q.push(temp);
				}
				if (map[i][j] == '@') {
					start_point = make_pair(j, i);
				}
				visit[i][j] = false;
			}
		}
		Answer = go();
		if (Answer == 0) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << Answer << endl;
		}
	}
	return 0;
}