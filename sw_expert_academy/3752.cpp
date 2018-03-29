#include <iostream>
#include <vector>
using namespace std;

int T, N;
int Answer;
vector<int> scores;

bool visit[10001];

void go(int n, int sum)
{
	visit[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= 0; j--) {
			if (visit[j]) {
				visit[j + scores[i]] = true;
			}
		}
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int sum = 0;
		Answer = 0;
		scores.clear();
		cin >> N;
		scores.resize(N);
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			scores[i] = temp;
			sum += temp;
		}

		for (int i = 0; i < 10001; i++) {
			visit[i] = false;
		}
		
		go(N, sum);

		for (int i = 0; i < 10001; i++) {
			if (visit[i]) {
				Answer++;
			}
		}

		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}
