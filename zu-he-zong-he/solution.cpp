# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
int init_num = -100;

class Solution {
public:
    // 表示当前在 candidates 数组的第 idx 位 还剩 target 要组合。已经组合的列表为 combine。
    // 递归终止的条件为 target <= 0 或者 candidates 数组被全部用完
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {    // 递归函数
        if (idx == candidates.size()) { // candidates 数组被全部用完
            return;
        }
        if (target == 0) {              // 已满足条件，递归终止
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
    // 时间复杂度：O(S)，其中 S 为所有可行解的长度之和。从分析给出的搜索树我们可以看出时间复杂度取决于搜索树所有叶子节点的深度之和，即所有可行解的长度之和。在这题中，我们很难给出一个比较紧的上界，我们知道 O(n×2^n) 是一个比较松的上界
    // 即在这份代码中，n 个位置每次考虑选或者不选，如果符合条件，就加入答案的时间代价。但是实际运行的时候，因为不可能所有的解都满足条件，递归的时候我们还会用 target - candidates[idx] >= 0 进行剪枝，所以实际运行情况是远远小于这个上界的。

    // 空间复杂度：O(target)。除答案数组外，空间复杂度取决于递归的栈深度，在最差情况下需要递归 O(target) 层。
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
int main(){
    char c;
    int n = 0;
    vector<int> input(100,init_num);
    cout << "input numlists" << endl;;
    cin >> input[n++];
    while((c=getchar()) != '\n'){
        cin >> input[n++];
    }
    input = inputclean(input);
    // for(auto element : input){
    //     cout << element << " ";
    // }
    Solution solution;
    cout << "input target" << endl;
    int target;
    cin >> target;
    vector<vector<int>> answer = solution.combinationSum(input, target);
    cout << "answer :" << endl;
    for(auto elements : answer){
        for(auto element : elements){
            cout << element << " ";
        }
        cout << endl;
    }
}