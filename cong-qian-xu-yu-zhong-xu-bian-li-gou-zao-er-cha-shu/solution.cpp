# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_map>
using namespace std;
// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
int init_num = -10000000;
struct BTree{
    int val;
    BTree *left;
    BTree *right;
    BTree() : val(0), left(nullptr), right(nullptr) {}
    BTree(int x) : val(x), left(nullptr), right(nullptr) {}
    BTree(int x, BTree *left, BTree *right) : val(x), left(left), right(right){}
};
class Solution {
private:
    unordered_map<int, int> index;

public:
    BTree* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        // 哈希表 index 对应 key - 二叉树元素值, value - 该元素对应中序遍历的列表中的位置
        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;      // 前序遍历中根节点索引
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];  // 中序遍历中根节点索引
        
        // 先把根节点建立出来
        BTree* root = new BTree(preorder[preorder_root]);
        
        int size_left_subtree = inorder_root - inorder_left;    // 得到左子树中的节点数目
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    BTree* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    // 时间复杂度：O(n)，其中 n 是树中的节点个数。

    // 空间复杂度：O(n)，除去返回的答案需要的 O(n) 空间之外，我们还需要使用 O(n) 的空间存储哈希映射，以及 O(h)（其中 h 是树的高度）的空间表示递归时栈空间。这里 h < n，所以总空间复杂度为 O(n)。
};
vector<int> inputclean(vector<int> input){
    int n = 0;
    for(auto element : input){
        if(element != init_num){
            n++;
        }
    }
    vector<int> inputreturn(n, init_num);
    n = 0;
    for(auto element : input){
        if(element != init_num){
            inputreturn[n++] = element;
        }
    }
    return inputreturn;
}
void preOrder(BTree *btree){
    if (btree == nullptr){
        return;
    }   
    cout << btree -> val << " ";
    preOrder(btree -> left);
    preOrder(btree -> right);
}
void inOrder(BTree *btree){
    if (btree == nullptr){
        return ;
    }
    inOrder(btree -> left);
    cout << btree -> val << " ";
    inOrder(btree -> right);
}
int main(){
    vector<int> preorder(100, init_num);
    char c;
    int n = 0;
    cout << "input preorder numslist" << endl;
    cin >> preorder[n++];
    while((c = getchar()) != '\n'){
        cin >> preorder[n++];
    }
    preorder = inputclean(preorder);

    vector<int> inorder(100, init_num);
    n = 0;
    cout << "input inorder numslist" << endl;
    cin >> inorder[n++];
    while((c = getchar()) != '\n'){
        cin >> inorder[n++];
    }
    inorder = inputclean(inorder);
    Solution solution;
    BTree *btree = solution.buildTree(preorder, inorder);
    cout << "val answer" << endl;
    preOrder(btree);
    cout << endl;
    inOrder(btree);

}