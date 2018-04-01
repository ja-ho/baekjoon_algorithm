#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_SIZE 101001
#define INF 100000

vector<int> v[MAX_SIZE];
int N, K, M;
int pos;

int dist[MAX_SIZE];
bool visit[MAX_SIZE];

void dijkstra()			//cost는 하이퍼튜브간의 이동은 0, 역간 이동은 1
{
	for (int i = 2; i < pos; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(-1, 1));

	while (!pq.empty()) {
		int cnt = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (visit[from]) continue;
		visit[from] = true;

		for (int i = 0; i < v[from].size(); i++) {
			int to = v[from][i];
			int add = 1;

			if (to > N) add--;

			if (dist[to] > cnt + add) {
				dist[to] = cnt + add;
				pq.push(make_pair(-dist[to], to));
			}
		}
	}


}


int main()
{
	cin >> N >> K >> M;
	pos = N + 1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			int temp;
			cin >> temp;
			v[pos].push_back(temp);
			v[temp].push_back(pos);
		}
		pos++;
	}
	dijkstra();

	printf("%d\n", (dist[N] == INF) ? -1 : dist[N]);

	return 0;
}