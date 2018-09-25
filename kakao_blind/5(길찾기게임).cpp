#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class Data {
public:
	int idx, x, y;
	Data() : idx(0), x(0), y(0) {

	};
	Data(int idx, int x, int y) : idx(idx), x(x), y(y) {

	};
};

class Node {
public:
	Data data;
	Node *left;
	Node *right;
	Node() {
		left = right = NULL;
	}

	Node(Data data) : data(data) {
		left = right = NULL;
	}
};

class Tree {
public:
	Node *root;
	vector<int> pre_list, post_list;
	Tree() {
		root = NULL;
	};

	void AddNode(Node *root, Node *newNode)
	{
		if (root->data.x > newNode->data.x) {
			if (root->left != NULL) {
				AddNode(root->left, newNode);
			}
			else root->left = newNode;
		}
		else {
			if (root->right != NULL){
				AddNode(root->right, newNode);
			}
			else root->right = newNode;
		}
	}

	void Preorder(Node *root)
	{
		if (root == NULL) return;
		pre_list.push_back(root->data.idx);
		Preorder(root->left);
		Preorder(root->right);
	}

	void Postorder(Node *root)
	{
		if (root == NULL) return;
		Postorder(root->left);
		Postorder(root->right);
		post_list.push_back(root->data.idx);
	}
};

bool Compare(const Data& a, const Data& b)
{
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y > b.y;
	}
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<Data> datas;
	Tree tree;
	int nodeinfo_size = nodeinfo.size();
	for (int i = 0; i < nodeinfo_size; i++) {
		Data temp;
		temp.idx = i + 1;
		temp.x = nodeinfo[i][0];
		temp.y = nodeinfo[i][1];
		datas.push_back(Data(i+1, nodeinfo[i][0], nodeinfo[i][1]));		
	}
	sort(datas.begin(), datas.end(), Compare);
	Node root;
	root.data = datas[0];
	root.left = root.right = NULL;
	tree.root = &root;

	for (int i = 1; i < nodeinfo_size; i++) {
		Node *node = new Node();
		node->data = datas[i];
		node->left = node->right = NULL;
		tree.AddNode(tree.root, node);
	}

	tree.Preorder(tree.root);
	tree.Postorder(tree.root);

	answer.push_back(tree.pre_list);
	answer.push_back(tree.post_list);

	return answer;
}

int main() {
	vector<vector<int>> nodeinfo = { {5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2} };
	auto it = solution(nodeinfo);

	return 0;
}