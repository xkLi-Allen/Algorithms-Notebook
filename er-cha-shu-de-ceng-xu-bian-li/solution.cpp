# include<iostream>
# include<vector>
# include<queue>
using namespace std;
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(BTree* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }

        queue <BTree*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return ret;
    }
    // 记树上所有节点的个数为 n。

    // 时间复杂度：每个点进队出队各一次，故渐进时间复杂度为 O(n)。
    // 空间复杂度：队列中元素的个数不超过 n 个，故渐进空间复杂度为 O(n)。
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
	cout << "create order btree: " << endl;
	for (int i = 0; i < k; i++) {
		cout << treeArray[i] << " ";
		creatBTree(treeArray[i], btree);
	}
    cout << endl;
    cout << "answer" << endl;
    Solution solution;
	vector <vector<int>> answer = solution.levelOrder(btree);
    for (auto elements : answer){
        for (auto element : elements){
            cout << element << " ";
        }
        cout << endl;
    }

}