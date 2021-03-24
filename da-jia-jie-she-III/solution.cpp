# include<iostream>
# include<vector>
# include<queue>
# include<unordered_map>
using namespace std;
#define MAXSIZE 100
// https://leetcode-cn.com/problems/house-robber-iii/
int init_Node = -100;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    // 用 f(o) 表示选择 o 节点的情况下，o 节点的子树上被选择的节点的最大权值和；
    // 用 g(o) 表示不选择 o 节点的情况下，o 节点的子树上被选择的节点的最大权值和；
    // l 和 r 代表 o 的左右孩子。
    unordered_map <TreeNode*, int> f, g;

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }

    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
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
    vector<int> input_vector = creatVector_int();
    TreeNode* root = creatBTree(input_vector);
    cout << "create result" << endl;
    showBTree(root);
    Solution solution;
    int answer = solution.rob(root);
    cout << "answer: " << answer << endl;
}