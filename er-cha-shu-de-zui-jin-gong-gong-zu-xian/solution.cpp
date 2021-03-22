# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
    // 递归遍历整棵二叉树，定义 fx 表示 x 节点的子树中是否包含 p 节点或 q 节点，如果包含为 true，否则为 false
    // 那么符合条件的最近公共祖先 x 一定满足如下条件：
    // (flson && frson) ∣∣ ((x = p ∣∣ x = q) && (flson∣∣frson))
    // 其中 lson 和 rson 分别代表 x 节点的左孩子和右孩子。
    // flson && frson 说明左子树和右子树均包含 p 节点或 q节点
    // 如果左子树包含的是 p 节点，那么右子树只能包含 q 节点，反之亦然，因为 p 节点和 q 节点都是不同且唯一的节点
    // 因此如果满足这个判断条件即可说明 x 就是我们要找的最近公共祖先。
    // 再来看第二条判断条件，这个判断条件即是考虑了 x 恰好是 p 节点或 q 节点且它的左子树或右子树有一个包含了另一个节点的情况，因此如果满足这个判断条件亦可说明 x 就是我们要找的最近公共祖先。
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
    // 时间复杂度：O(N)，其中 N 是二叉树的节点数。二叉树的所有节点有且只会被访问一次，因此时间复杂度为 O(N)。

    // 空间复杂度：O(N) ，其中 N 是二叉树的节点数。递归调用的栈深度取决于二叉树的高度，二叉树最坏情况下为一条链，此时高度为 N，因此空间复杂度为 O(N)。
};
struct queue                                //队列的数据结构
{
	TreeNode *data[MAXSIZE];
	int front, rear;
};

void creat(queue &q)                        //创建一个空队列
{
	q.front = q.rear = 0;
}

void enqueue(queue &q, TreeNode *t)         //将t入队    
{
	if ((q.rear + 1) % MAXSIZE == q.front)
	{
		cout << "queue is full, can not put TreeNode in" << endl;
		return;
	}
	q.rear = (q.rear + 1) % MAXSIZE;
	q.data[q.rear] = t;
}

TreeNode *dequeue(queue &q)                 //出队，并返回对头元素
{
	TreeNode *t;
	q.front = (q.front + 1) % MAXSIZE;
	t= q.data[q.front];	
	return t;
}

bool isempty(queue &q)                      //判断队列是否为空
{
	return (q.front == q.rear);
}
 
TreeNode* creatBTree(vector<int> input){    //按层次顺序创建一棵二叉树，并返回根节点
    //1.先将根节点入队，当队列不为空时，循环执行以下操作：
	//2.输入左子树的值，不为空，将其入队
	//3.输入右子树的值，不为空，将其入队
    int val;
    int n = 0;
    val = input[n++];
    queue Q;
    creat(Q);
    TreeNode* root = new TreeNode(init_Node);
    if (val == -1){
        return NULL;
    }
    else{
        root -> val = val;
        enqueue(Q, root);
    }
    while(!isempty(Q)){
        TreeNode* temp = dequeue(Q);
        val = input[n++];
        if(val == -1){
            temp -> left = nullptr;
        }
        else{
            temp -> left = new TreeNode(init_Node);
            temp -> left -> val = val;
            enqueue(Q, temp -> left);
        }
        val = input[n++];
        if(val == -1){
            temp -> right = nullptr;
        }
        else{
            temp -> right = new TreeNode(init_Node);
            temp -> right -> val = val;
            enqueue(Q, temp -> right);
        }
    }
    return root;
}

void showBTree(TreeNode *root){             //层次遍历二叉树
    //1.先将根节点入队，当队列不为空时，循环执行以下操作：
	//2.出队一个元素，访问它
	//3.若左子树不为空，将其入队
	//4.若右子树不为空，将其入队
    queue Q;
    TreeNode *temp;
    creat(Q);
    if (root == NULL){
        return;
    }
    enqueue(Q, root);
    while(!isempty(Q)){
        temp = dequeue(Q);
        cout << temp -> val << " ";
        if (temp -> left){
            enqueue(Q, temp -> left);
        }
        if (temp -> right){
            enqueue(Q, temp -> right);
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
    int p, q;
    cout << "input p value" << endl;
    cin >> p;
    cout << "input q value" << endl;
    cin >> q;
    TreeNode* p_Node = new TreeNode(p);
    TreeNode* q_Node = new TreeNode(q);
    Solution solution;
    TreeNode* answer = solution.lowestCommonAncestor(root, p_Node, q_Node);
    cout << "lowestCommonAncestor: " << answer -> val << endl;

}