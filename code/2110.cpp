#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000001;

bool check(vector<int> &distance, int C, int key);

int main() {
	int N, C;
	vector<int> distance;
	int temp;

	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		distance.push_back(temp);
	}
	sort(distance.begin(), distance.end());

	int first = 1;
	int end = distance[N - 1] - distance[0];

	int answer = 1;
	while (first <= end) {
		int mid = (first + end) / 2;

		if (check(distance, C, mid)) {
			if (answer < mid) {
				answer = mid;
			}

			first = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	printf("%d", answer);

	return 0;
}

bool check(vector<int> &distance, int C, int key)
{
	int count = 1;
	int last = distance[0];
	for (int i : distance) {
		if (i - last >= key) {
			count++;
			last = i;
		}
	}
	return count >= C;
}
