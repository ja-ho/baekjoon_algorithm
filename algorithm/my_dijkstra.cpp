#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> edge;
int N, M, S, u, v, w;

vector<int> dijkstra(int start)
{
	vector<int>dist(N + 1, -1);
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(-dist[start], start));	//min-heap으로 이용하기 위해 -를 붙여준다.

	while (!pq.empty()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (here_dist > dist[here]) continue;
		for (int i = 0; i < edge[here].size(); i++) {
			int there = edge[here][i].first;
			int there_dist = dist[here] + edge[here][i].second;
			if (dist[there] == -1 || dist[there] > there_dist) {
				dist[there] = there_dist;
				pq.push(make_pair(-dist[there], there));
			}
		}
	}

	return dist;
}

int main() {
	vector<int> dist;
	cin >> N >> M >> S;
	edge.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(v, w));
	}
	dist = dijkstra(S);


	for (int i = 1; i <= N; i++) {
		cout << dist[i] << endl;
	}

	return 0;
}