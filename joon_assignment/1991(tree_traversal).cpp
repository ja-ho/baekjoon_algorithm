#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	int left;
	int right;
} node;

node a[27];

void preorder(int node_num)
{
	if (node_num == -1) return;
	cout << (char)('A' + node_num);
	preorder(a[node_num].left);
	preorder(a[node_num].right);
	return;
}

void inorder(int node_num)
{
	if (node_num == -1) return;
	inorder(a[node_num].left);
	cout << (char)('A' + node_num);
	inorder(a[node_num].right);
	return;
}

void postorder(int node_num)
{
	if (node_num == -1) return;
	postorder(a[node_num].left);
	postorder(a[node_num].right);
	cout << (char)('A' + node_num);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<node> tree;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		if (y != '.') {
			a[x - 'A'].left = y - 'A';
		}
		else {
			a[x - 'A'].left = -1;
		}
		if (z != '.') {
			a[x - 'A'].right = z - 'A';
		}
		else {
			a[x - 'A'].right = -1;
		}
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';

	return 0;
}