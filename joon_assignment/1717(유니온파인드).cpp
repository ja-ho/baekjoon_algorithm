#include <iostream>

using namespace std;

int nums[1000001];

int find(int a)
{
	if (a == nums[a]) {
		return nums[a];
	}
	else {
		return nums[a] = find(nums[a]);
	}
}


int union_(int a, int b)
{
	int x = find(a);
	int y = find(b);
	nums[y] = x;
	return nums[y];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		nums[i] = i;
	}

	while (m--) {
		int command, a, b;
		cin >> command >> a >> b;
		if (command == 0) {
			union_(a, b);
		}
		else if (command == 1) {
			if (find(a) == find(b)) {
				cout << "yes" << '\n';
			}
			else cout << "no" << '\n';
		}
	}

	return 0;
}