#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int n, m;

char map[15][15];
char temp_map[15][15];


pair<int, int> rb;
pair<int, int> bb;
pair<int, int> change_rb;
pair<int, int> change_bb;
pair<int, int> hole;

typedef struct _info {
	pair<int, int> rb;
	pair<int, int> bb;
	char temp_map[15][15];
	int cnt;
	int before_dir;
} info;

int moving(int x, int y, int dir, char type) {	//return 값이 0 = 구멍에 빠짐, 1 = 벽이나 공에 막힘
	if (dir == 1) {
		while (true) {
			if (temp_map[y - 1][x] == '.') {
				temp_map[y][x] = '.';
				temp_map[y - 1][x] = type;
				y--;
			}
			else if (map[y - 1][x] == 'O') {
				temp_map[y][x] = '.';
				return 0;
			}
			else {
				if (type == 'R') {
					change_rb = make_pair(x, y);
				}
				else {
					change_bb = make_pair(x, y);
				}
				return 1;
			}
		}
	}
	if (dir == 2) {
		while (true) {
			if (temp_map[y][x + 1] == '.') {
				temp_map[y][x] = '.';
				temp_map[y][x + 1] = type;
				x++;
			}
			else if (map[y][x + 1] == 'O') {
				temp_map[y][x] = '.';
				return 0;
			}
			else {
				if (type == 'R') {
					change_rb = make_pair(x, y);
				}
				else {
					change_bb = make_pair(x, y);
				}
				return 1;
			}
		}
	}
	if (dir == 3) {
		while (true) {
			if (temp_map[y + 1][x] == '.') {
				temp_map[y][x] = '.';
				temp_map[y + 1][x] = type;
				y++;
			}
			else if (map[y + 1][x] == 'O') {
				temp_map[y][x] = '.';
				return 0;
			}
			else {
				if (type == 'R') {
					change_rb = make_pair(x, y);
				}
				else {
					change_bb = make_pair(x, y);
				}
				return 1;
			}
		}
	}
	if (dir == 4) {
		while (true) {
			if (temp_map[y][x - 1] == '.') {
				temp_map[y][x] = '.';
				temp_map[y][x - 1] = type;
				x--;
			}
			else if (map[y][x - 1] == 'O') {
				temp_map[y][x] = '.';
				return 0;
			}
			else {
				if (type == 'R') {
					change_rb = make_pair(x, y);
				}
				else {
					change_bb = make_pair(x, y);
				}
				return 1;
			}
		}
	}
}


//dir 1 == north, 2 == east, 3 == south, 4 == west
pair<int,int> move_command(pair<int, int> rb, pair<int, int> bb, int dir)
{
	int rb_x = rb.first;
	int rb_y = rb.second;
	int bb_x = bb.first;
	int bb_y = bb.second;
	int red_ret, blue_ret;
	if (dir == 1 || dir == 3) {		//위아래로 굴리기
		if (rb_x == bb_x) {	//같은 줄 
			if (dir == 1) {
				if (rb_y < bb_y) {	//빨간 공이 더 위
					red_ret = moving(rb_x, rb_y, dir, 'R');
					blue_ret = moving(bb_x, bb_y, dir, 'B');
				}
				else {
					blue_ret = moving(bb_x, bb_y, dir,'B');
					red_ret = moving(rb_x, rb_y, dir, 'R');
				}
			}
			else if (dir == 3) {
				if (rb_y < bb_y) {
					blue_ret = moving(bb_x, bb_y, dir, 'B');
					red_ret = moving(rb_x, rb_y, dir, 'R');
				}
				else {
					red_ret = moving(rb_x, rb_y, dir, 'R');
					blue_ret = moving(bb_x, bb_y, dir, 'B');
				}
			}

		}
		else {	//같은 줄 아니면 상관없다.
			red_ret = moving(rb_x, rb_y, dir, 'R');
			blue_ret = moving(bb_x, bb_y, dir, 'B');
		}
	}
	else if (dir == 2 || dir == 4) {	//좌우로 굴리기
		if (rb_y == bb_y) {	//같은 줄 
			if (dir == 2) {
				if (rb_x < bb_x) {	//빨간 공이 더 왼쪽
					blue_ret = moving(bb_x, bb_y, dir, 'B');
					red_ret = moving(rb_x, rb_y, dir, 'R');
				}
				else {
					red_ret = moving(rb_x, rb_y, dir, 'R');
					blue_ret = moving(bb_x, bb_y, dir, 'B');
				}
			}
			else if (dir == 4){
				if (rb_x < bb_x) {
					red_ret = moving(rb_x, rb_y, dir, 'R');
					blue_ret = moving(bb_x, bb_y, dir, 'B');
				}
				else {
					blue_ret = moving(bb_x, bb_y, dir, 'B');
					red_ret = moving(rb_x, rb_y, dir, 'R');
				}
			}

		}
		else {
			red_ret = moving(rb_x, rb_y, dir, 'R');
			blue_ret = moving(bb_x, bb_y, dir, 'B');
		}
	}
	return make_pair(red_ret, blue_ret);
}

int bfs()
{
	int red_ret, blue_ret;
	queue<info> q;
	info temp;
	info temp2;
	temp.rb = rb;
	temp.bb = bb;
	temp.cnt = 0;
	temp.before_dir = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp.temp_map[i][j] = map[i][j];
		}
	}
	q.push(temp);
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		pair<int, int> temp_rb = temp.rb;
		pair<int, int> temp_bb = temp.bb;
		int temp_cnt = temp.cnt;
		int before_dir = temp.before_dir;

		for (int i = 1; i <= 4; i++) {
			if (before_dir == 0) {
			
			} else if (before_dir == 2) {
				before_dir = 4;
			}
			else {
				before_dir = (before_dir + 2) % 4;
			}
			if (before_dir == i) continue;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					temp_map[i][j] = temp.temp_map[i][j];
				}
			}
			pair<int, int>cc = move_command(temp_rb, temp_bb, i);

			if (cc.second == 0) continue;
			else if (cc.first == 0) {
				return temp_cnt + 1;
			}
			else if (cc.first == 1) {
				temp2.rb = change_rb;
				temp2.bb = change_bb;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						temp2.temp_map[i][j] = temp_map[i][j];
					}
				}
				temp2.cnt = temp_cnt + 1;
				if (temp2.cnt > 10) return -1;
				temp2.before_dir = i;
				q.push(temp2);
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", &map[i]);
		//getchar();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R') {
				rb = make_pair(j, i);
			}
			else if (map[i][j] == 'B') {
				bb = make_pair(j, i);
			}
			else if (map[i][j] == 'O') {
				hole = make_pair(j, i);
			}
		}
	}

	int answer = bfs();
	printf("%d\n", answer);	

	return 0;
}