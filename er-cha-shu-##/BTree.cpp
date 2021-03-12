# include<iostream>
using namespace std;
int n = 0;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 二叉树的最大深度
int maxDepth(TreeNode* root) {
	if (root == nullptr) return 0;
	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
// 创建二叉树(有序)
void creatTreeNode(int data, TreeNode *root) {
	TreeNode *newNode = new TreeNode;
	newNode -> val = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
	if (root == NULL) {
		root = newNode;
	}
	else {
		TreeNode *backTree = NULL;
		TreeNode *currentTree = root;
		while (currentTree != NULL) {
			backTree = currentTree;
			if (currentTree -> val > data) {
				currentTree = currentTree -> left;
			}
			else {
				currentTree = currentTree -> right;
			}
		}
		if (backTree -> val > data) {
			backTree -> left = newNode;
		}
		else {
			backTree -> right = newNode;
		}
	}
}
// 根据输入顺序创建无序二叉树
// void creatTreeNode(int data, TreeNode* root){
//     TreeNode *newNode = new TreeNode;
//     newNode -> val = data;
//     newNode -> left = NULL;
//     newNode -> right = NULL;
//     if(root == NULL){
//         root = newNode;
//     }
//     else{
//         TreeNode *currentNode = root;
//         TreeNode *backNode = NULL;
//         while(currentNode != NULL){
//             backNode = currentNode;
//             if(currentNode -> left == NULL){
//                 currentNode = currentNode ->left;
//             }
//             else{
//                 currentNode = currentNode -> right;
//             }
//         }
//         if(backNode -> left == NULL){
//             backNode -> left = newNode;
//         }
//         else{
//             backNode -> right = newNode;
//         }
//     }
// }
// 先序遍历（递归方法）
void preOrder(TreeNode* temp) {
	if (temp != NULL) {
		cout << temp -> val << " ";
		preOrder(temp -> left);
		preOrder(temp -> right);
	}
}

// 中序遍历（递归方法）
void inOrder(TreeNode* temp) {
	if (temp != NULL) {
		inOrder(temp -> left);
		cout << temp -> val << " ";
		inOrder(temp -> right);
	}
}

// 后序遍历（递归方法）
void postOrder(TreeNode* temp) {
	if (temp != NULL) {
		postOrder(temp -> left);
		postOrder(temp -> right);
		cout << temp -> val << " ";
	}
}

// 计算叶子结点的个数
int countLeaf(TreeNode* temp) {
	if (temp == NULL) {
		return 0;
	}
	else {
		if (temp -> left == NULL && temp -> right == NULL) {
			return n += 1;
		}
		else {
			countLeaf(temp -> left);
			countLeaf(temp -> right);
		}
		return n;
	}
}

// 计算二叉树中的节点个数
int countTree(TreeNode* temp) {
	if (temp == NULL)
		return 0;
	else
		return countTree(temp -> left) + countTree(temp -> right);
}
int main() {
	TreeNode *btree = new TreeNode(7);
	int treeArray[] = { 4, 2, 3, 15, 35, 6, 45, 55, 20, 1, 14, 56, 57, 58 };
	int k;
	k = sizeof(treeArray) / sizeof(treeArray[0]);
	cout << "建立排序二叉树顺序: " << endl;
	for (int i = 0; i < k; i++) {
		cout << treeArray[i] << " ";
		creatTreeNode(treeArray[i], btree);
	}
	cout << endl;

	cout << "二叉树的节点个数：" << countTree(btree) << endl;
	cout << "二叉树的叶子个数：" << countLeaf(btree) << endl;

	cout << "二叉树先序遍历序列: " << endl;
	preOrder(btree);
	cout << endl;

	cout << "二叉树中序遍历序列: " << endl;
	inOrder(btree);
	cout << endl;

	cout << "二叉树后序遍历序列: " << endl;
	postOrder(btree);
	cout << endl;

}
