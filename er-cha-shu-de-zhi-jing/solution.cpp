# include<iostream>
# include<vector>
# include<queue>
using namespace std;
#define MAXSIZE 100
int init_Node = -100;
// https://leetcode-cn.com/problems/diameter-of-binary-tree/submissions/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
    // 时间复杂度：O(N)，其中 N 为二叉树的节点数，即遍历一棵二叉树的时间复杂度，每个结点只被访问一次。

    // 空间复杂度：O(Height)，其中 Height 为二叉树的高度。
    // 由于递归函数在递归过程中需要为每一层递归函数分配栈空间，所以这里需要额外的空间且该空间取决于递归的深度，
    // 而递归的深度显然为二叉树的高度，并且每次递归调用的函数里又只用了常数个变量，所以所需空间复杂度为 O(Height) 。

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
}