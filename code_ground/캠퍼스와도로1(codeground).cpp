#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<vector<pair<int, int>>> street;

int answer[1001];
int N, M;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(N + 1, -1);
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int here = pq.top().second;
		int here_dist = -pq.top().first;
		pq.pop();

		if (here_dist > dist[here])
			continue;	//Todo : need to check

		for (int i = 0; i < street[here].size(); i++) {
			int there = street[here][i].first;
			int next_dist = street[here][i].second + here_dist;

			if (dist[there] == -1 || next_dist < dist[there]) {
				dist[there] = next_dist;
				pq.push(make_pair(-dist[there], there));	//min-heap으로 이용하기 위해 -를 붙여줌.
			}			
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (i == start) continue;
		for (int j = 0; j < street[i].size(); j++) {
			if (street[i][j].second + dist[i] == dist[street[i][j].first]) {
				answer[i] = false;
			}
		}
	}

}

int main() {
	int T;
	int tc = 1;
	int u, v, d;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		street.clear();
		street.resize(N + 1);
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &u, &v, &d);
			street[u].push_back(make_pair(v, d));
			street[v].push_back(make_pair(u, d));
		}

		for (int i = 1; i <= N; i++) {	//initialize answer
			answer[i] = true;
		}

		for (int i = 1; i <= N; i++) {
			dijkstra(i);
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (answer[i] == true)
				cnt++;
		}
		printf("Case #%d\n", tc);
		cout << cnt << " ";
		for (int i = 1; i <= N; i++) {
			if (answer[i] == true) {
				cout << i << " ";
			}
		}
		cout << endl;
		tc++;
	}
	return 0;
}