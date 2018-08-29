#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}

	int front = 1;
	int rear = 1;
	int sum = nums[1];
	int ans = 0;
	while (front <= rear && rear <= n) {
		if (sum < m) {
			sum += nums[++rear];
		}
		else if (sum == m) {
			ans++;
			rear++;
			//if (rear > n) break;
			sum += nums[rear];
		}
		else {
			sum -= nums[front++];
			if (front > rear && front <= n) {
				rear = front;
				sum = nums[front];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
