#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _line {
	int x1, y1;
	int x2, y2;
} Line;

int Answer;

int dist(int x1, int x2, int y1, int y2) {
	return max(abs(x2 - x1), abs(y2 - y1));
}

bool check(vector<Line> &line, int mid) {
	int length = line.size();
	bool ok;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			int ax[] = { line[i].x1, line[i].x2 };
			int ay[] = { line[j].y1, line[j].y2 };
			for (int l1 = 0; l1 < 2; l1++) {
				for (int l2 = 0; l2 < 2; l2++) {
					int x = ax[l1] + mid;
					int y = ay[l2] + mid;
					ok = true;
					for (int k = 0; k < length; k++) {
						int dist1 = dist(x, line[k].x1, y, line[k].y1);
						int dist2 = dist(x, line[k].x2, y, line[k].y2);
						int d = min(dist1, dist2);
						if (d > mid) {
							ok = false;
							break;
						}
					}
					if (ok) {
						return true;
					}
				}
			}
		}
	}
	return false;
}


void go(vector<Line> &line) {
	int left = 0;
	int right = 100000000;
	Answer = right;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (check(line, mid)) {
			Answer = min(Answer, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
}



int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		vector<Line> line;
		Answer = 0;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x1, y1, x2, y2;
			Line temp_line;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			temp_line.x1 = 2 * x1; temp_line.y1 = 2 * y1;
			temp_line.x2 = 2 * x2; temp_line.y2 = 2 * y2;
			line.push_back(temp_line);
		}
		
		go(line);

		cout << "Case #" << test_case + 1 << endl;
		if (Answer % 2 == 0){
			cout << Answer / 2 << endl;
		}
		else {
			cout << Answer / 2 << ".5" << endl;
		}
	}

	return 0;
}

