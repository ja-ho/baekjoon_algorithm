#include <cstdio>
#include <vector>
using namespace std;

bool check(vector<int>& v, int M, int key);

int main() {
	int N, M;
	int temp;
	
	int first = 0;
	int end = 0;
	vector<int> v;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		v.push_back(temp);
		if (end < v[i]) {
			end = v[i];
		}
	}

	int answer = end;
	while (first <= end) {
		int mid = (first + end) / 2;
		if (check(v, M, mid)) {
			if (answer > mid) {
				answer = mid;
			}
			end = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}

	printf("%d", answer);
	return 0;
}

bool check(vector<int>& v, int M, int key)
{
	int length = v.size();
	int minimum = v[0];
	int maximum = v[0];
	int count = 1;

	for (int i = 1; i < length; i++) {
		if (minimum > v[i]) {
			minimum = v[i];
		}
		if (maximum < v[i]) {
			maximum = v[i];
		}

		if (maximum - minimum > key) {
			count += 1;
			minimum = v[i];
			maximum = v[i];
		}
	}

	return count <= M;
}
