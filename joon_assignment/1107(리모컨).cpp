#include <iostream>
#include <vector>
using namespace std;

bool broken[10];

//�����ϸ� Ƚ��, �Ұ����ϸ� 0 ����
int possible(int c)
{
	if (c == 0) {
		if (broken[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (c) {
		if (broken[c % 10]) return 0;
		c /= 10;
		len++;
	}
	return len;
}

int abs(int a, int b)
{
	if (a > b) return a - b;
	else return b - a;
}

int main() {
	int n, m;
	
	cin >> n >> m;
		
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		broken[temp] = true;
	}

	int min_cnt = abs(n, 100);

	for (int i = 0; i < 1000000; i++) {
		int temp;
		if (temp = possible(i)) {
			temp += abs(n, i);
		}

		if (min_cnt > temp && temp != 0) {
			min_cnt = temp;
		}
	}

	cout << min_cnt << '\n';

	return 0;
}