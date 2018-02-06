#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

queue<pair<int, char>>command;

typedef struct point {
	int x_start;
	int x_end;
	int y_start;
	int y_end;
} Point;

int N, L;


long long go() {
	Point tempPoint;
	vector<Point> points;
	int start_x = 0;
	int start_y = 0;
	int end_x = 0;
	int end_y = 0;
	int dir = 1;		//dir  0은 위 1은 오른쪽 2는 아래 3은 왼쪽
	long long totalCount = 0;
	long long tempCount = 0;
	int MIN = 99999999;
	bool over = false;

	//초기화

	int temp_sec = command.front().first;
	int temp_command = command.front().second;
	command.pop();

	if (temp_command == 'L') dir = 0;
	else dir = 2;

	//범위 저장
	tempPoint.x_start = 0 - L - 1;
	tempPoint.x_end = 0 + L + 1;
	tempPoint.y_start = 0 - L - 1;
	tempPoint.y_end = 0 - L - 1;
	points.push_back(tempPoint);

	tempPoint.x_start = 0 - L - 1;
	tempPoint.x_end = 0 + L + 1;
	tempPoint.y_start = 0 + L + 1;
	tempPoint.y_end = 0 + L + 1;
	points.push_back(tempPoint);


	tempPoint.x_start = 0 - L - 1;
	tempPoint.x_end = 0 - L - 1;
	tempPoint.y_start = 0 - L - 1;
	tempPoint.y_end = 0 + L + 1;
	points.push_back(tempPoint);

	tempPoint.x_start = 0 + L + 1;
	tempPoint.x_end = 0 + L + 1;
	tempPoint.y_start = 0 - L - 1;
	tempPoint.y_end = 0 + L + 1;
	points.push_back(tempPoint);


	//처음 꺼
	tempPoint.x_start = start_x;
	tempPoint.x_end = temp_sec + start_x;
	tempPoint.y_start = start_y;
	tempPoint.y_end = end_y;

	points.push_back(tempPoint);

	start_x = tempPoint.x_end;
	totalCount += temp_sec;
	end_x = start_x + temp_sec;
	end_y = start_y;
	
	//Todo : 범위검사


	if (temp_sec > L) return L+1;	//첨부터 뒤짐

	while (!command.empty()) {
		int temp_sec = command.front().first;
		int temp_command = command.front().second;
		command.pop();
		totalCount += temp_sec;
		if (dir == 0) {
			end_y = start_y + temp_sec;
			end_x = start_x;
		}
		else if (dir == 1) {
			end_x = start_x + temp_sec;
			end_y = start_y;
		}

		else if (dir == 2) {
			end_y = start_y;
			start_y = start_y - temp_sec;
			end_x = start_x;
		}
		else if (dir == 3) {
			end_x = start_x;
			start_x = start_x - temp_sec;
			end_y = start_y;
		}
		//////
		//검사
		for (int i = 0; i < points.size()-1; i++) {
			tempCount = totalCount;
			if (points[i].y_end == points[i].y_start) {	//수평
				if (points[i].x_start <= start_x && points[i].x_end >= start_x) {
					if (start_y <= points[i].y_end && end_y >= points[i].y_end) {
						if (dir == 0) {
							tempCount -= end_y - points[i].y_start;
							if (MIN > tempCount) {
								MIN = tempCount;
								over = true;
							}
						}
						else if(dir == 2) {
							tempCount -= points[i].y_start - start_y;
							if (MIN > tempCount) {
								MIN = tempCount;
								over = true;
							}
						}
					}
				}
			}
			else {	//수직
				if (points[i].y_start <= start_y && points[i].y_end >= start_y) {
					if (start_x <= points[i].x_end && end_x >= points[i].x_end) {
						
						if (dir == 1) {
							tempCount -= end_x - points[i].x_start;
							if (MIN > tempCount) {
								MIN = tempCount;
								over = true;
							}
						}
						else if (dir == 3) {
							tempCount -= points[i].x_start - start_x;
							if (MIN > tempCount) {
								MIN = tempCount;
								over = true;
							}
						}
					}
				}
			}
		}

		if (over) {
			return MIN;
		}

		//저장
		tempPoint.x_start = start_x;
		tempPoint.x_end = end_x;
		tempPoint.y_start = start_y;
		tempPoint.y_end = end_y;
		points.push_back(tempPoint);

		//초기화

		if (dir == 0 || dir == 1) {
			start_x = end_x;
			start_y = end_y;
		}
		
		//방향바꾸기
		if (temp_command == 'L') {
			if (dir == 0) dir = 3;
			else dir--;
		}
		else if (temp_command == 'R') {
			if (dir == 3) dir = 0;
			else dir++;
		}
	}

	//int final_min = 9999999;

	//for (int i = 0; i < points.size(); i++) {
	//	if (dir == 0) {
	//		if (points[i].y_end == points[i].y_start) {
	//			if (points[points.size() - 1].y_end < points[i].y_end) {
	//				if (final_min > points[i].y_end - points[points.size() - 1].y_end) {
	//					final_min = points[i].y_end - points[points.size() - 1].y_end;
	//				}
	//			}
	//		}
	//	}
	//	else if (dir == 1) {
	//		if (points[i].x_end == points[i].x_start) {
	//			if (points[points.size() - 1].x_end < points[i].x_end) {
	//				if (final_min > points[i].x_end - points[points.size() - 1].x_end) {
	//					final_min = points[i].x_end - points[points.size() - 1].x_end;
	//				}
	//			}
	//		}
	//	}

	//	else if (dir == 2) {
	//		if (points[i].y_end == points[i].y_start) {
	//			if (points[points.size() - 1].y_end > points[i].y_end) {
	//				if (final_min > points[points.size() - 1].y_end - points[i].y_end) {
	//					final_min = points[points.size() - 1].y_end - points[i].y_end;
	//				}
	//			}
	//		}
	//	}

	//	else {
	//		if (points[i].x_end == points[i].x_start) {
	//			if (points[points.size() - 1].x_end > points[i].x_end) {
	//				if (final_min > points[points.size() - 1].x_end - points[i].x_end) {
	//					final_min = points[points.size() - 1].x_end - points[i].x_end;
	//				}
	//			}
	//		}
	//	}
	//}
	//return totalCount + final_min;
}

int main() {
	int sec;
	char direction;
	cin >> L >> N;
	for (int i = 0; i < N; i++) {
		cin >> sec >> direction;
		command.push(make_pair(sec, direction));
	}
	command.push(make_pair(9999999, 'R'));
	printf("%lld\n", go());


	return 0;
}bx