#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;
int N;
vector<int> jump;

int jump_diff(int a, int b)
{
	return b-a;
}

int find_minimum()
{
	int max_jump = 0;
	int half_length = N / 2;
	if (max_jump < jump[N - 1] - jump[N - 3]) max_jump = jump[N - 1] - jump[N - 3];
	if (max_jump < jump[N - 1] - jump[N - 2]) max_jump = jump[N - 1] - jump[N - 2];
	if (max_jump < jump[2] - jump[0]) max_jump = jump[2] - jump[0];
	if (max_jump < jump[1] - jump[0]) max_jump = jump[1] - jump[0];
	
	if (N % 2 == 1) {
		for (int i = 1; i < N - 2; i++) {
			int temp = jump_diff(jump[i], jump[i + 2]);
			if (max_jump < temp) max_jump = temp;
		}
	}
	else {
		for (int i = 1; i <= N / 2; i++) {
			int temp = jump_diff(jump[i], jump[i + 2]);
			if (max_jump < temp) max_jump = temp;
		}
		for (int i = N / 2; i < N; i++) {
			int temp = jump_diff(jump[i], jump[i + 2]);
			if (max_jump < temp) max_jump = temp;
		}
	}
	return max_jump;
}

int main() {
	int T, tc;

	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		Answer = 0;
		cin >> N;
		jump.clear();
		jump.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> jump[i];
		}
		sort(jump.begin(), jump.end());

		Answer = find_minimum();

		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}