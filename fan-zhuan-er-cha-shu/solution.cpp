# include<iostream>
using namespace std;
// https://leetcode-cn.com/problems/invert-binary-tree
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
    BTree* invertTree(BTree* root) {
        if (root == nullptr) {
            return nullptr;
        }
        BTree* left = invertTree(root->left);
        BTree* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    // 时间复杂度：O(N)，其中 N 为二叉树节点的数目。
    // 我们会遍历二叉树中的每一个节点，对每个节点而言，我们在常数时间内交换其两棵子树。

    // 空间复杂度：O(N)。使用的空间由递归栈的深度决定，它等于当前节点在二叉树中的高度。
    // 在平均情况下，二叉树的高度与节点个数为对数关系，即 O(logN)。而在最坏情况下，树形成链状，空间复杂度为 O(N)。

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
	cout << "建立排序二叉树顺序: " << endl;
	for (int i = 0; i < k; i++) {
		cout << treeArray[i] << " ";
		creatBTree(treeArray[i], btree);
	}
	cout << endl;

}