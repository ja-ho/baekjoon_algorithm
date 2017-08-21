//#include <cstdio>
//#include <queue>
//using namespace std;
//
//bool visit[111111];
//int d[111111];
//int MAX = 100000;
//int COUNT[111111];
//
//int main() {
//	int N, K;
//	scanf("%d %d", &N, &K);
//	queue<int> q;
//	q.push(N);
//	visit[N] = true;
//	d[N] = 0;
//	COUNT[N] = 1;
//	while (!q.empty()) {
//		int currentPosition = q.front();
//		q.pop();
//		for (int nextPosition : {currentPosition * 2, currentPosition + 1, currentPosition - 1})
//		{
//			if (nextPosition <= MAX && nextPosition >= 0) {
//				if (visit[nextPosition] == false) {
//					q.push(nextPosition);
//					visit[nextPosition] = true;
//					d[nextPosition] = d[currentPosition] + 1;
//					COUNT[nextPosition] = COUNT[currentPosition];
//
//				}
//				else if (d[nextPosition] == d[currentPosition] + 1) {
//					COUNT[nextPosition] += COUNT[currentPosition];
//				}
//
//			}
//		}
//		
//	}
//
//	printf("%d\n", d[K]);
//	printf("%d\n", COUNT[K]);
//
//	return 0;
//
//}