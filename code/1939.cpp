#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> map[10001];
bool visit[10001];

int N, M;
int Start, End;

bool find(int node, int limit);

int main() {
	int answer = 1;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		map[A].push_back(make_pair(B, C));
		map[B].push_back(make_pair(A, C));
	}

	scanf("%d %d", &Start, &End);

	int left = 1;
	int right = 1000000000;

	while (left <= right) {
		int mid = (left + right) / 2;
		memset(visit, false, sizeof(visit));
		if (find(Start, mid)) {
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	printf("%d", answer);
	return 0;
}

bool find(int node, int limit)
{
	if (visit[node]) return false;
	visit[node] = true;
	
	if (node == End) return true;

	for (auto &p : map[node]) {
		int next = p.first;
		int weight = p.second;
		if (weight >= limit) {
			if (find(next, limit)) {
				return true;
			}
		}
	}
	return false;
}