#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int>w1;
vector<int>w2;
vector<int>w3;
vector<int>w4;
bool visit[5];

void rotate_w(int num, int dir) {
	int first, last;
	if (num == 1) {
		if (dir == 1) {
			last = w1[w1.size() - 1];
			w1.pop_back();
			w1.insert(w1.begin(), last);
		}
		else {
			first = w1[0];
			w1.erase(w1.begin());
			w1.push_back(first);
		}
	}
	if (num == 2) {
		if (dir == 1) {
			last = w2[w2.size() - 1];
			w2.pop_back();
			w2.insert(w2.begin(), last);
		}
		else {
			first = w2[0];
			w2.erase(w2.begin());
			w2.push_back(first);
		}
	}
	if (num == 3) {
		if (dir == 1) {
			last = w3[w3.size() - 1];
			w3.pop_back();
			w3.insert(w3.begin(), last);
		}
		else {
			first = w3[0];
			w3.erase(w3.begin());
			w3.push_back(first);
		}
	}
	if (num == 4) {
		if (dir == 1) {
			last = w4[w4.size() - 1];
			w4.pop_back();
			w4.insert(w4.begin(), last);
		}
		else {
			first = w4[0];
			w4.erase(w4.begin());
			w4.push_back(first);
		}
	}

}


void go(int num, int dir) {
	visit[num] = true;
	if (num == 1) {
		if (w1[2] != w2[6] && visit[2] == false) {
			go(2, -dir);
		}
		rotate_w(num, dir);
	}
	else if (num == 2) {
		if (w2[6] != w1[2] && visit[1] == false) {
			go(1, -dir);
		}
		if (w2[2] != w3[6] && visit[3] == false) {
			go(3, -dir);
		}
		rotate_w(num, dir);
	}
	else if (num == 3) {
		if (w3[6] != w2[2] && visit[2] == false) {
			go(2, -dir);
		}
		if (w3[2] != w4[6] && visit[4] == false) {
			go(4, -dir);
		}
		rotate_w(num, dir);
	}
	else {
		if (w4[6] != w3[2] && visit[3] == false) {
			go(3, -dir);
		}
		rotate_w(num, dir);
	}
}

int main() {

	int K;
	queue<pair<int, int>>command;

	int temp;
	int temp_num, temp_dir;
	//input
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &temp);
		w1.push_back(temp);
	}
	for (int i = 0; i < 8; i++) {
		scanf("%1d", &temp);
		w2.push_back(temp);
	}	for (int i = 0; i < 8; i++) {
		scanf("%1d", &temp);
		w3.push_back(temp);
	}	for (int i = 0; i < 8; i++) {
		scanf("%1d", &temp);
		w4.push_back(temp);
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &temp_num, &temp_dir);
		command.push(make_pair(temp_num, temp_dir));
	}

	for (int i = 0; i < K; i++) {
		int num, dir;
		num = command.front().first;
		dir = command.front().second;
		command.pop();
		for (int j = 1; j < 5; j++) {
			visit[j] = false;
		}
		go(num, dir);
	}

	int answer = 0;
	if (w1[0] == 1) answer += 1;
	if (w2[0] == 1) answer += 2;
	if (w3[0] == 1) answer += 4;
	if (w4[0] == 1) answer += 8;
	
	printf("%d\n", answer);


	return 0;
}