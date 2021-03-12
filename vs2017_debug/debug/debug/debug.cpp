# include<iostream>
using namespace std;
struct BTree {
	int val;
	BTree *left;
	BTree *right;
	BTree() : val(0), left(nullptr), right(nullptr) {}
	BTree(int x) : val(x), left(nullptr), right(nullptr) {}
	BTree(int x, BTree *left, BTree *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	void Create(BTree* root, BTree* myAnswer) {
		if (root == nullptr) {
			return;
		}

		myAnswer->val = root->val;
		myAnswer->left = nullptr;
		BTree *newNode = new BTree();
		myAnswer->right = newNode;
		Create(root->left, myAnswer->right);
		Create(root->right, myAnswer->right);
	}
	void flatten(BTree* root) {
		BTree *myAnswer = new BTree();
		Create(root, myAnswer);
		root = myAnswer;
	}
};
void creatBTree(int data, BTree *root) {
	BTree *newnode = new BTree(data);
	if (root == NULL) {
		root = newnode;
	}
	else {
		BTree *backTree = new BTree();
		BTree *currentTree = root;
		while (currentTree != NULL) {
			backTree = currentTree;
			if (currentTree->val > data) {
				currentTree = currentTree->left;
			}
			else {
				currentTree = currentTree->right;
			}
		}
		if (backTree->val > data) {
			backTree->left = newnode;
		}
		else {
			backTree->right = newnode;
		}
	}
}

int main() {
	BTree *btree = new BTree(1);
	int treeArray[] = { 2, 3, 4, 5,6 };
	int k;
	k = sizeof(treeArray) / sizeof(treeArray[0]);
	cout << "create order btree: " << endl;
	for (int i = 0; i < k; i++) {
		cout << treeArray[i] << " ";
		creatBTree(treeArray[i], btree);
	}
	cout << endl;
	BTree *temp = new BTree();
	Solution solution;
	solution.Create(btree, temp);
	cout << "answer: " << endl;
	while (btree) {
		cout << btree->val << " ";
		btree = btree->right;
	}
	cout << endl;

}