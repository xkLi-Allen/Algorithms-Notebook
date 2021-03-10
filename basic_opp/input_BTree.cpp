# include<iostream>
using namespace std;
struct BTree{
    int val;
    BTree *left;
    BTree *right;
    BTree() : val(0), left(nullptr), right(nullptr) {}
    BTree(int x) : val(x), left(nullptr), right(nullptr) {}
    BTree(int x, BTree *left, BTree *right) : val(x), left(left), right(right){}
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