#include <cstdio>
using namespace std;

char nums[10][4] = { "zro", "one", "two", "thr", "for", "fiv", "six", "svn", "egt", "nin" };
int nums_list[10];

int main() {
	int t;
	scanf("%d", &t);
	int tc = 1;
	while (t--) {
		for (int i = 0; i < 10; i++) {
			nums_list[i] = 0;
		}
		char temp[5];
		int n;
		scanf("%s %d", &temp, &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", temp);
			if (temp[0] == 'z') nums_list[0]++;
			else if (temp[0] == 'o') nums_list[1]++;
			else if (temp[1] == 'w') nums_list[2]++;
			else if (temp[1] == 'h') nums_list[3]++;
			else if (temp[1] == 'o') nums_list[4]++;
			else if (temp[2] == 'v') nums_list[5]++;
			else if (temp[2] == 'x') nums_list[6]++;
			else if (temp[1] == 'v') nums_list[7]++;
			else if (temp[1] == 'g') nums_list[8]++;
			else if (temp[0] == 'n') nums_list[9]++;
		}
		printf("#%d\n", tc++);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < nums_list[i]; j++) {
				printf("%s ", nums[i]);
			}
		}
		printf("\n");
	}

	return 0;
}