#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define MAX(a, b)	((a) > (b) ? (a) : (b))

int L, N;

typedef struct _line {
	int start_x;
	int end_x;
	int start_y;
	int end_y;
} line;

void set_point(line *temp, int start_x, int start_y, int end_x, int end_y) {
	temp->start_x = start_x; temp->start_y = start_y;
	temp->end_x = end_x; temp->end_y = end_y;
}


int go(queue<pair<int, char>> c) {
	vector<line>lines;
	line temp;
	int count = 0;
	int sec;
	char command_dir;
	int now_dir;
	int end_x, end_y;
	set_point(&temp, -L - 1, -L - 1, L + 1, -L - 1);	//아랫변
	lines.push_back(temp);
	set_point(&temp, -L - 1, L + 1, L + 1, L + 1);	//윗변
	lines.push_back(temp);
	set_point(&temp, -L - 1, -L - 1, -L - 1, L + 1);	//왼쪽변
	lines.push_back(temp);
	set_point(&temp, L + 1, -L - 1, L + 1, L + 1);	//오른쪽변
	lines.push_back(temp);
	
	//첫번째 명령은 우선 실행
	sec = c.front().first;
	command_dir = c.front().second;
	c.pop();
	set_point(&temp, 0, 0, 0 + sec, 0);
	now_dir = 1;		//0은 위, 1은 오른쪽, 2는 아래, 3은 왼쪽
	if (command_dir == 'L') {
		if (now_dir == 0) {
			now_dir = 3;
		}
		else {
			now_dir -= 1;
		}
	}
	else {
		if (now_dir == 3) {
			now_dir = 0;
		}
		else now_dir += 1;
	}
	end_x = sec; end_y = 0;	//처음 것만 초기화
	//Todo: 검사 조건 필요.

	if (end_x > L) {
		return L + 1;
	}
	count += sec;
	lines.push_back(temp);
	
	while (!c.empty()) {
		sec = c.front().first;
		command_dir = c.front().second;
		c.pop();

		if (now_dir == 0) {	//좌표 설정
			set_point(&temp, end_x, end_y, end_x, end_y + sec);
			end_y += sec;
		}
		else if (now_dir == 1) {
			set_point(&temp, end_x, end_y, end_x + sec, end_y);
			end_x += sec;
		}
		else if (now_dir == 2) {
			set_point(&temp, end_x, end_y - sec, end_x, end_y);
			end_y -= sec;
		}
		else {
			set_point(&temp, end_x - sec, end_y, end_x, end_y);
			end_x -= sec;
		}

		int MIN = 2 * L + 1;
		bool over = false;

		//살아남는 지 체크(테두리, 있던 영역 침범 여부)
		for (int i = 0; i < lines.size() - 1; i++) {
			if (temp.start_x == temp.end_x) {		//수직이라면 두가지 체크 1. 수평여부, 같은 위치의 수직
				if (lines[i].start_y == lines[i].end_y) {	//수평이라면
					if (lines[i].start_y >= temp.start_y && lines[i].start_y <= temp.end_y) {
						if (lines[i].end_x < temp.start_x || lines[i].start_x > temp.start_x) {	//지나지 않으면
							continue;
						}
						else {
							if (now_dir == 0) {
								if (MIN > lines[i].start_y - temp.start_y) {
									MIN = lines[i].start_y - temp.start_y;
								}
								over = true;
							}
							else if (now_dir == 2) {
								if (MIN > temp.end_y - lines[i].start_y) {
									MIN = temp.end_y - lines[i].start_y;
								}
								over = true;
							}
						}
					}
				}
				else if (lines[i].start_x == temp.start_x) {	//같은 x좌표의 수직일 경우
															//높이가 겹친다면
					if (temp.end_y < lines[i].start_y || temp.start_y > lines[i].end_y) {
						if (now_dir == 0) {		//올라갈 때
							if (MIN > lines[i].start_y - temp.start_y) {
								MIN = lines[i].start_y - temp.start_y;
							}
							over = true;
						}
						else if (now_dir == 2) {	//내려갈 떄
							if (MIN > temp.end_y - lines[i].end_y) {
								MIN = temp.end_y - lines[i].end_y;
							}
							over = true;
						}
					}
					continue;	//높이 안겹치면
				}
			}
			else {	//수평이라면		두 가지 체크 1.수직여부, 2. 같은 높이의 수평
				if (lines[i].end_x == lines[i].start_x) {
					if (lines[i].start_x < temp.start_x || lines[i].start_x > temp.end_x) {
						continue;
					}
					else {
						if (lines[i].start_y <= temp.start_y && lines[i].end_y >= temp.start_y) {
							if (now_dir == 1) {
								if (MIN > lines[i].start_x - temp.start_x) {
									MIN = lines[i].start_x - temp.start_x;
								}
								over = true;
							}
							else if (now_dir == 3) {
								if (MIN > temp.end_x - lines[i].start_x) {
									MIN = temp.end_x - lines[i].start_x;
								}
								over = true;
							}
						}
						continue;
					}
				}
				else {
					if (lines[i].end_y == temp.end_y) {		//같은 높이의 수평이야?
						if (temp.start_x > lines[i].end_x || temp.end_x < lines[i].start_x) {
							continue;
						}
						else {
							if (now_dir == 1) {
								if (MIN > lines[i].start_x - temp.start_x) {
									MIN = lines[i].start_x - temp.start_x;
								}
								over = true;
							}
							else if (now_dir == 3) {
								if (MIN > temp.end_x - lines[i].end_x) {
									MIN = temp.end_x - lines[i].end_x;
								}
								over = true;
							}
						}
					}	
				}
			}
		}

		lines.push_back(temp);
		
		if (over) {
			return count += MIN;
		}

		if (command_dir == 'L') {	//방향 설정
			if (now_dir == 0) {
				now_dir = 3;
			}
			else {
				now_dir -= 1;
			}
		}
		else {
			if (now_dir == 3) {
				now_dir = 0;
			}
			else now_dir += 1;
		}
		
		count += sec;
	}
	return count;
}



int main() {
	int sec;
	char dir;
	queue<pair<int, char>>command;
	scanf("%d", &L); scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %c", &sec, &dir);
		command.push(make_pair(sec, dir));
	}
	command.push(make_pair(100000000, 'L'));
	printf("%d\n", go(command));

	return 0;
}