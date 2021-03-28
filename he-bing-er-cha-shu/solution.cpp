# include<iostream>
# include<vector>
# include<queue>
using namespace std;
// https://leetcode-cn.com/problems/merge-two-binary-trees
#define MAXSIZE 100
int init_Node = -100;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
    // 时间复杂度：O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点个数。
    // 对两个二叉树同时进行深度优先搜索，只有当两个二叉树中的对应节点都不为空时才会对该节点进行显性合并操作，因此被访问到的节点数不会超过较小的二叉树的节点数。

    // 空间复杂度：O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点个数。
    // 空间复杂度取决于递归调用的层数，递归调用的层数不会超过较小的二叉树的最大高度，最坏情况下，二叉树的高度等于节点数。

};

TreeNode* creatBTree(vector<int> input){    //按层次顺序创建一棵二叉树，并返回根节点
    //1.先将根节点入队，当队列不为空时，循环执行以下操作：
	//2.输入左子树的值，不为空，将其入队
	//3.输入右子树的值，不为空，将其入队
    int val;
    int n = 0;
    val = input[n++];
    queue<TreeNode*> Q;
    TreeNode* root = new TreeNode(init_Node);
    if (val == -1){
        return NULL;
    }
    else{
        root -> val = val;
        Q.push(root);
    }
    while(!Q.empty()){
        TreeNode* temp = Q.front();
        Q.pop();
        val = input[n++];
        if(val == -1){
            temp -> left = nullptr;
        }
        else{
            temp -> left = new TreeNode(init_Node);
            temp -> left -> val = val;
            Q.push(temp -> left);
        }
        val = input[n++];
        if(val == -1){
            temp -> right = nullptr;
        }
        else{
            temp -> right = new TreeNode(init_Node);
            temp -> right -> val = val;
            Q.push(temp -> right);
        }
    }
    return root;
}

void showBTree(TreeNode *root){             //层次遍历二叉树
    //1.先将根节点入队，当队列不为空时，循环执行以下操作：
	//2.出队一个元素，访问它
	//3.若左子树不为空，将其入队
	//4.若右子树不为空，将其入队
    queue<TreeNode*> Q;
    TreeNode *temp;
    if (root == NULL){
        return;
    }
    Q.push(root);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        cout << temp -> val << " ";
        if (temp -> left){
            Q.push(temp -> left);
        }
        if (temp -> right){
            Q.push(temp -> right);
        }
    }
    cout << endl;
}

vector<int> creatVector_int(){
    vector<int> input;
    char c;
    int n = 0;
    int temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    return input;
}
int main(){
    cout << "input TreeNode value, -1 respresent NULL " << endl;
    vector<int> input_vector1 = creatVector_int();
    TreeNode* root1 = creatBTree(input_vector1);
    cout << "create result" << endl;
    showBTree(root1);

    cout << "input TreeNode value, -1 respresent NULL " << endl;
    vector<int> input_vector2 = creatVector_int();
    TreeNode* root2 = creatBTree(input_vector2);
    cout << "create result" << endl;
    showBTree(root2);

    cout << "answer: " << endl;
    Solution solution;
    TreeNode* answer = solution.mergeTrees(root1, root2);
    showBTree(answer);
}