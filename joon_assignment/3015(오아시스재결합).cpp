#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long ans = 0;
	int temp;
	stack<pair<int, int>> st;
	int equal_cnt = 1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		pair<int, int>tmp = make_pair(temp, 1);
		while (!st.empty() && st.top().first <= temp) {
			ans += (long long)st.top().second;					//���ο� �Ͱ� ���ִ�� top ���ֺ���
			if (temp == st.top().first) {
				tmp.second += st.top().second;
			}
			st.pop();
		}
		if (!st.empty()) ans++;			//���ο� �Ͱ� ���� st�� top���� ���ֺ���
		st.push(tmp);
	}

	cout << ans << '\n';
	return 0;
}