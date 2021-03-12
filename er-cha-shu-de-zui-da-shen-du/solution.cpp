# include<iostream>
using namespace std;
// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
struct BTree{
    int val;
    BTree *left;
    BTree *right;
    BTree() : val(0), left(nullptr), right(nullptr) {}
    BTree(int x) : val(x), left(nullptr), right(nullptr) {}
    BTree(int x, BTree *left, BTree *right) : val(x), left(left), right(right){}
};
int maxDepth(BTree* root) {
	if (root == nullptr) return 0;
	return max(maxDepth(root->left), maxDepth(root->right)) + 1;

    // 时间复杂度：O(n)，其中 n 为二叉树节点的个数。每个节点在递归中只被遍历一次。

    // 空间复杂度：O(height)，其中 height 表示二叉树的高度。递归函数需要栈空间，而栈空间取决于递归的深度，因此空间复杂度等价于二叉树的高度。
}
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
	cout << "create order btree: " << endl;
	for (int i = 0; i < k; i++) {
		cout << treeArray[i] << " ";
		creatBTree(treeArray[i], btree);
	}
	cout << endl;
    int answer = maxDepth(btree);
    cout << "answer : " << answer << endl;

}