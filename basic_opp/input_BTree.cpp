// # include<iostream>
// using namespace std;
// struct BTree{
//     int val;
//     BTree *left;
//     BTree *right;
//     BTree() : val(0), left(nullptr), right(nullptr) {}
//     BTree(int x) : val(x), left(nullptr), right(nullptr) {}
//     BTree(int x, BTree *left, BTree *right) : val(x), left(left), right(right){}
// };

// void creatBTree (int data, BTree *root){
//     BTree *newnode = new BTree(data);
//     if (root == NULL){
//         root = newnode;
//     }
//     else{
//         BTree *backTree = new BTree();
//         BTree *currentTree = root;
//         while (currentTree != NULL){
//             backTree = currentTree;
//             if (currentTree -> val > data){
//                 currentTree = currentTree -> left;
//             }
//             else{
//                 currentTree = currentTree -> right;
//             }
//         }
//         if (backTree -> val > data){
//             backTree -> left = newnode;
//         }
//         else{
//             backTree -> right = newnode;
//         }
//     }
// }

// int main() {
// 	BTree *btree = new BTree(7);
// 	int treeArray[] = { 4, 2, 3, 15, 35, 6, 45, 55, 20, 1, 14, 56, 57, 58 };
// 	int k;
// 	k = sizeof(treeArray) / sizeof(treeArray[0]);
// 	cout << "建立排序二叉树顺序: " << endl;
// 	for (int i = 0; i < k; i++) {
// 		cout << treeArray[i] << " ";
// 		creatBTree(treeArray[i], btree);
// 	}
// 	cout << endl;

// }


# include<iostream>
# include<vector>
# include<queue>
using namespace std;
#define MAXSIZE 100
int init_Node = -100;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
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