#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;
vector<int> height_v;

int max_of_four(int a, int b, int c, int d)
{
	if (a > b) {
		if (a > c) {
			if (a > d) return a;
			else return d;
		} 
		else {
			if (c > d) return c;
			else return d;
		}
	}
	else {
		if (b > c) {
			if (b > d) return b;
			else return d;
		}
		else {
			if (c > d) return c;
			else return d;
		}
	}
}


int go(int width) 
{
	int cnt = 0;
	for (int i = 3; i <= width - 2; i++) {
		int height = height_v[i];
		if (height_v[i] > height_v[i - 1] && height_v[i] > height_v[i + 1] && height_v[i] > height_v[i-2] &&
			height_v[i] > height_v[i+2]) {
			int more_height = max_of_four(height_v[i - 2], height_v[i - 1], height_v[i + 1], height_v[i + 2]);
			cnt += height_v[i] - more_height;
		}
	}
	return cnt;
}


int main() {
	int tc;

	for (tc = 0; tc < 10; tc++) {
		int width;
		cin >> width;
		height_v.clear();
		height_v.resize(width + 1);

		for (int i = 1; i <= width; i++) {
			int height;
			cin >> height_v[i];
		}
		Answer = go(width);

		cout << "#" << tc + 1 << " " << Answer << endl;
	}
	return 0;
}