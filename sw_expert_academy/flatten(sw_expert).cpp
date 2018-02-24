#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int Answer;
int boxes[101];

int num_moved_box(int num_dump)
{
	int moved_box = 0;
	int temp_moved_box;
	int i;
	bool over = true;
	for (i = 100; i > 1; i--) {
		if (boxes[i] != boxes[i - 1]) {
			temp_moved_box = boxes[i] - boxes[i - 1];
			over = false;
			break;
		}
	}
	if (over) {
		return 0;
	}

	if (temp_moved_box * (100 - i + 1) <= num_dump) {
		for (int j = i; j <= 100; j++) {
			boxes[j] -= temp_moved_box;
		}
		return temp_moved_box * (100 - i + 1);
	}


	if (100 - i + 1 <= num_dump) {
		for (int j = i; j <= 100; j++) {
			boxes[j] -= 1;
		}
		num_dump -= 100 - i + 1;
		moved_box += 100 - i + 1;
	}
	else {
		for (int j = i; j <= i + num_dump - 1; j++) {
			boxes[j] -= 1;
		}
		moved_box += num_dump;
		num_dump = 0;
	}
	return moved_box;
}

void num_needed_box(int moved_box)
{
	int needed_box = 0;
	int i;
	while (moved_box) {
		for (i = 1; i < 100; i++) {
			if (boxes[i] != boxes[i + 1]) {
				needed_box = boxes[i + 1] - boxes[i];
				break;
			}
		}

		if (i <= moved_box) {
			for (int j = 1; j <= i; j++) {
				boxes[j] += 1;
			}
			moved_box -= i;
		}

		else {
			for (int j = i; j >= i - moved_box + 1; j--) {
				boxes[j] += 1;
			}
			moved_box = 0;
		}
	}
}


void flatten(int num_dump) 
{
	int i, j;
	int moved_box;
	int needed_box;
	sort(boxes + 1, boxes + 101);
	while (num_dump) {
		moved_box = num_moved_box(num_dump);	//옮길 수 있는 박스들
		if (moved_box == 0) break;
		
		num_needed_box(moved_box);				//최저층부터 채워넣음

		num_dump -= moved_box;					//옮길 수 있는 횟수에서 옮긴 박스개수만큼 제한다.
	}
}

int main() {
	int tc;
	freopen("input.txt", "r", stdin);
	for (tc = 1; tc <= 10; tc++) {
		int num_dump;
		cin >> num_dump;
		for (int i = 0; i < 100; i++) {
			cin >> boxes[i + 1];
		}
		flatten(num_dump);
		sort(boxes + 1, boxes + 101);
		Answer = boxes[100] - boxes[1];

		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}

