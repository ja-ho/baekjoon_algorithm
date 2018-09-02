#include <iostream>
#include <vector>
using namespace std;

#define swap(a, b) {int t; t = a; a = b; b = t;}

typedef struct _heap {
	int root;
	int size;
	int heap[100001];
} heap_root;

heap_root root;

void init_heap()
{
	root.root = 0;
	root.size = 0;
	for (int i = 0; i < 100001; i++) {
		root.heap[i] = 0;
	}
}

int push(int x)
{
	int child = root.size;
	root.heap[root.size++] = x;
	while (child != root.root) {
		if (root.heap[child] > root.heap[(child - 1) / 2]) {
			swap(root.heap[child], root.heap[(child - 1) / 2]);
			child = (child - 1) / 2;
		}
		else break;
	}
	return 0;
}

int pop()
{
	int ret = root.heap[0];
	swap(root.heap[0], root.heap[root.size - 1]);
	root.size--;
	int current = 0;
	int child = current * 2 + 1;
	while (child <= root.size - 1) {
		if (child + 1 <= root.size - 1 && root.heap[child + 1] > root.heap[child]) child++;
		if (root.heap[current] < root.heap[child]) {
			swap(root.heap[current], root.heap[child]);
			current = child;
			child = current * 2 + 1;
		}
		else break;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	init_heap();
	while (n--) {
		int x;
		cin >> x;
		if (x == 0) {	//delete 연산
			if (root.size == 0) cout << 0 << '\n';
			else {
				cout << pop() << '\n';
			}
		}
		else {			//add 연산
			push(x);
		}
	}

	return 0;
}