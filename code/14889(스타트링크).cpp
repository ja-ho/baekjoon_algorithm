#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int S[21][21];
bool visit[21];
int diff = 10000;

void go() {
	for (int i = 1; i <= N; i++) visit[i] = true;
	for (int i = 1; i <= N / 2; i++) {
		visit[i] = false;
	}

	do {
		int start_score = 0;
		int link_score = 0;
		vector<int> start;
		vector<int> link;
		for (int i = 1; i <= N; i++) {
			if (visit[i]) {
				start.push_back(i);
			}
			else link.push_back(i);
		}

		for (int i = 0; i < start.size(); i++) {
			for (int j = i + 1; j < start.size(); j++) {
				start_score += S[start[i]][start[j]] + S[start[j]][start[i]];
			}
		}
		for (int i = 0; i < link.size(); i++) {
			for (int j = i + 1; j < link.size(); j++) {
				link_score += S[link[i]][link[j]] + S[link[j]][link[i]];
			}
		}


		int temp_min;
		if (start_score - link_score < 0) temp_min = -(start_score - link_score);
		else temp_min = start_score - link_score;
		if (diff > temp_min) diff = temp_min;

	} while (next_permutation(visit + 1, visit + 1 + N));
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &S[i][j]);
		}
	}

	go();
	printf("%d\n", diff);
	return 0;
}