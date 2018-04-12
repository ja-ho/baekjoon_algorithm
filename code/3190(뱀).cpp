#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

int answer;
int n, k, l;

vector<pair<int, int>> apple;	//행, 열
queue<pair<int, char>> command;	//l = 왼쪽, d = 오른쪽
queue<pair<int, int>> snake;
bool map[102][102];



int go()
{
	int cnt = 0;
	int dir = 1;			//0 = 위, 1 = 오른쪽, 2 = 아래, 3 = 왼쪽
	int cx = 1;
	int cy = 1;
	int tail_x = 1;
	int tail_y = 1;
	int length = 1;
	int change_sec;
	char change_way;
	snake.push(make_pair(cx, cy));
	bool eat;

	map[1][1] = true;
	

	while (true) {
		eat = false;
		if (command.size()) {
			change_sec = command.front().first;
			change_way = command.front().second;
		}

		if (cnt == change_sec) {
			if (change_way == 'D') {
				dir += 1;
				if (dir == 4) dir = 0;
			}
			else if (change_way == 'L') {
				dir -= 1;
				if (dir == -1) dir = 3;
			}
			command.pop();
		}
		if (dir == 0) {	//위
			if ((cy - 1 < 1) || (map[cy - 1][cx])) {
				cnt++;
				break;
			}

			for (int i = 0; i < apple.size(); i++) {
				if (cy - 1== apple[i].first && cx == apple[i].second) {
					eat = true;
					apple[i] = make_pair(1000, 1000);	//이미 먹음
					break;
				}
			}
			if (eat) {
				map[cy - 1][cx] = true;
				cy--;
				snake.push(make_pair(cy, cx));
				length++;
			}
			else {			//사과를 먹지 않음
				map[cy - 1][cx] = true;
				cy--;
				snake.push(make_pair(cy, cx));
				tail_x = snake.front().second;
				tail_y = snake.front().first;
				map[tail_y][tail_x] = false;
				snake.pop();
				//
				//if (tail_x > cx) {
				//	tail_x--;
				//}
				//else if (tail_x < cx) {
				//	tail_x++;
				//}
				//else {
				//	tail_y--;
				//}

			}
			cnt++;
		}
		else if (dir == 1) { // 오른쪽
			if ((cx + 1 > n) || (map[cy][cx + 1])) {
				cnt++;
				break;
			}

			for (int i = 0; i < apple.size(); i++) {
				if (cy == apple[i].first && cx + 1 == apple[i].second) {
					eat = true;
					apple[i] = make_pair(1000, 1000);
					break;
				}
			}
			if (eat) {
				map[cy][cx + 1] = true;
				cx++;
				snake.push(make_pair(cy, cx));
				length++;
			}
			else {			//사과를 먹지 않음
				map[cy][cx + 1] = true;
				cx++;
				snake.push(make_pair(cy, cx));
				tail_x = snake.front().second;
				tail_y = snake.front().first;
				map[tail_y][tail_x] = false;
				snake.pop();

				//map[tail_y][tail_x] = false;
				//if (tail_y > cy) {
				//	tail_y--;
				//}
				//else if (tail_y < cy) {
				//	tail_y++;
				//}
				//else {
				//	tail_x++;
				//}

			}
			cnt++;
		}
		else if (dir == 2) {	//아래
			if ((cy + 1 > n) || (map[cy + 1][cx])) {
				cnt++;
				break;
			}

			for (int i = 0; i < apple.size(); i++) {
				if (cy + 1 == apple[i].first && cx == apple[i].second) {
					eat = true;
					apple[i] = make_pair(1000, 1000);
					break;
				}
			}
			if (eat) {
				map[cy + 1][cx] = true;
				cy++;
				snake.push(make_pair(cy, cx));
				length++;
			}
			else {			//사과를 먹지 않음
				map[cy + 1][cx] = true;
				cy++;
				snake.push(make_pair(cy, cx));
				tail_x = snake.front().second;
				tail_y = snake.front().first;
				map[tail_y][tail_x] = false;
				snake.pop();

				//map[tail_y][tail_x] = false;
				//if (tail_x > cx) {
				//	tail_x--;
				//}
				//else if (tail_x < cx) {
				//	tail_x++;
				//}
				//else {
				//	tail_y++;
				//}

			}
			cnt++;
		}
		else if (dir == 3) {	//왼쪽
			if ((cx - 1 < 1) || (map[cy][cx - 1])) {
				cnt++;
				break;
			}

			for (int i = 0; i < apple.size(); i++) {
				if (cy == apple[i].first && cx - 1 == apple[i].second) {
					eat = true;
					apple[i] = make_pair(1000, 1000);
					break;
				}
			}
			if (eat) {
				map[cy][cx - 1] = true;
				cx--;
				snake.push(make_pair(cy, cx));
				length++;
			}
			else {			//사과를 먹지 않음
				map[cy][cx - 1] = true;
				cx--;
				snake.push(make_pair(cy, cx));
				tail_x = snake.front().second;
				tail_y = snake.front().first;
				map[tail_y][tail_x] = false;
				snake.pop();

				//map[tail_y][tail_x] = false;
				//if (tail_y > cy) {
				//	tail_y--;
				//}
				//else if (tail_y < cy) {
				//	tail_y++;
				//}
				//else {
				//	tail_x--;
				//}

			}
			cnt++;
		}
	}
	return cnt;
}


int main() {
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &y, &x);
		apple.push_back(make_pair(y, x));
	}

	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		int x;
		char y;
		scanf("%d %c", &x, &y);
		command.push(make_pair(x, y));
	}

	answer = go();
	printf("%d\n", answer);
	return 0;
}