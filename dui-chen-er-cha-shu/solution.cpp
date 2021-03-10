# include<iostream>
using namespace std;
struct BTree{
    int val;
    BTree *left;
    BTree *right;
    BTree() : val(0), left(nullptr), right(nullptr) {}
    BTree(int x) : val(x), left(nullptr), right(nullptr) {}
    BTree(int x, BTree *left, BTree *right) : val(x), left(left), right(right){}
};
class Solution {
public:
    bool check(BTree *p, BTree *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(BTree* root) {
        return check(root, root);
    }
    // 时间复杂度：这里遍历了这棵树，渐进时间复杂度为 O(n)。
    // 空间复杂度：这里的空间复杂度和递归使用的栈空间有关，这里递归层数不超过 n，故渐进空间复杂度为 O(n)。
};
void creatBTree (int data, BTree *root){
    BTree *newnode = new BTree(data);
    if (root == NULL){
        root = newnode;
    }
    else{
        BTree *backTree = new BTree();
        BTree *currentTree = root;
        while (currentTree != NULL){
            backTree = currentTree;
            if (currentTree -> val > data){
                currentTree = currentTree -> left;
            }
            else{
                currentTree = currentTree -> right;
            }
        }
        if (backTree -> val > data){
            backTree -> left = newnode;
        }
        else{
            backTree -> right = newnode;
        }
    }
}

int main() {
	BTree *btree = new BTree(7);
	int treeArray[] = { 4, 2, 3, 15, 35, 6, 45, 55, 20, 1, 14, 56, 57, 58 };
	int k;
	k = sizeof(treeArray) / sizeof(treeArray[0]);
	cout << "create sorted btree " << endl;
	for (int i = 0; i < k; i++) {
		cout << treeArray[i] << " ";
		creatBTree(treeArray[i], btree);
	}
	cout << endl;
    Solution solution;
    bool answer = solution.isSymmetric(btree);
    cout << "answer: " << answer;

}