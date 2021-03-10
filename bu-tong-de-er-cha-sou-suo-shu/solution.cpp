# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);    // G(n) 长度为 n 的序列能构成的不同二叉搜索树的个数 
        G[0] = 1;
        G[1] = 1;
        // 当确定序列长度时，还需要确定以序列中的那个节点当作根节点。确定根节点之后构成的二叉搜索树是左右子树可能情况的笛卡尔积
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {  // 该循环为确认序列长度后遍历所有可能的顶点取值
                G[i] += G[j - 1] * G[i - j];    // 计算左右子树的笛卡尔积
            }
        }
        return G[n];
    }
    // 时间复杂度 : O(n^2)，其中 n 表示二叉搜索树的节点个数。G(n) 函数一共有 n 个值需要求解，每次求解需要 O(n) 的时间复杂度，因此总时间复杂度为 O(n^2)。

    // 空间复杂度 : O(n)。我们需要 O(n) 的空间存储 G 数组。
};
int main(){
    cout << "input number" << endl;
    int n;
    cin >> n;
    Solution solution;
    int answer = solution.numTrees(n);
    cout << "answer: " << answer;
}