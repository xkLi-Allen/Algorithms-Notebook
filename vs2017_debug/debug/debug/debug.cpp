# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int init_num = -10000000;
vector<int> inputclean(vector<int> input) {
	int n = 0;
	for (auto element : input) {
		if (element != init_num) {
			n++;
		}
	}
	vector<int> inputreturn(n, init_num);
	n = 0;
	for (auto element : input) {
		if (element != init_num) {
			inputreturn[n++] = element;
		}
	}
	return inputreturn;
}
//class Solution {
//private:
//	int maxSum = -10000;
//
//public:
//	int maxGain(TreeNode* node) {
//		if (node == nullptr) {
//			return 0;
//		}
//
//		// 递归计算左右子节点的最大贡献值
//		// 只有在最大贡献值大于 0 时，才会选取对应子节点
//		int leftGain = max(maxGain(node->left), 0);
//		int rightGain = max(maxGain(node->right), 0);
//
//		// 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
//		int priceNewpath = node->val + leftGain + rightGain;
//
//		// 更新答案
//		maxSum = max(maxSum, priceNewpath);
//
//		// 返回节点的最大贡献值
//		return node->val + max(leftGain, rightGain);
//	}
//
//	int maxPathSum(TreeNode* root) {
//		maxGain(root);
//		return maxSum;
//	}
//	// 时间复杂度：O(N)，其中 N 是二叉树中的节点个数。对每个节点访问不超过 2 次。
//
//	// 空间复杂度：O(N)，其中 N 是二叉树中的节点个数。空间复杂度主要取决于递归调用层数，最大层数等于二叉树的高度，最坏情况下，二叉树的高度等于二叉树中的节点个数。
//};

void creatTreeNode(int data, TreeNode* root) {
	TreeNode *newNode = new TreeNode;
	newNode->val = data;
	newNode->left = NULL;
	newNode->right = NULL;
	if (root == NULL) {
		root = newNode;
	}
	else {
		TreeNode *currentNode = root;
		TreeNode *backNode = NULL;
		while (currentNode != NULL) {
			backNode = currentNode;
			if (currentNode->left == NULL) {
				currentNode = currentNode->left;
			}
			else {
				currentNode = currentNode->right;
			}
		}
		if (backNode->left == NULL) {
			backNode->left = newNode;
		}
		else {
			backNode->right = newNode;
		}
	}
}
// 中序遍历（递归方法）
void inOrder(TreeNode* temp) {
	if (temp != NULL) {
		inOrder(temp->left);
		cout << temp->val << " ";
		inOrder(temp->right);
	}
}
int main() {
	cout << "input numlists" << endl;
	vector<int> input(100, init_num);
	char c;
	int n = 0;
	cin >> input[n++];
	while ((c = getchar()) != '\n') {
		cin >> input[n++];
	}
	input = inputclean(input);
	TreeNode *bTree = new TreeNode(input[0]);
	for (int i = 1; i < input.size(); i++) {
		cout << input[i] << endl;
		creatTreeNode(input[i], bTree);
	}
	cout << "中序遍历" << endl;
	inOrder(bTree);
	cout << endl;
	//Solution solution;
	//int answer = solution.maxPathSum(bTree);
	//cout << "answer: " << answer << endl;
}
