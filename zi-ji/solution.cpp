# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/subsets/
int init_num = -10000000;
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) {  // dfs(cur,n) 参数表示当前位置是cur，原序列总长度为 n
        cout << "cur: " << cur << "    ";
        if (cur == nums.size()) {
            ans.push_back(t);
            for (auto element : t){
                cout << element << " ";
            }
            cout << endl;
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
    // 时间复杂度：O(n×2^n)。一共 2^n个状态，每种状态需要 O(n) 的时间来构造子集。

    // 空间复杂度：O(n)。临时数组 t 的空间代价是 O(n)，递归时栈空间的代价为 O(n)。
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
    vector<int> input(100, init_num);
    char c;
    int n = 0;
    cout << "input numslist" << endl;
    cin >> input[n++];
    while((c = getchar()) != '\n'){
        cin >> input[n++];
    }
    input = inputclean(input);
    // for(auto element : input){
    //     if(element != init_num){
    //         cout << element << " ";
    //     }
    // }
    cout << "Solution" << endl;
    Solution solution;
    vector<vector<int>> answer = solution.subsets(input);
    cout << "answer: " << endl;
    for (auto elements : answer){
        for (auto element : elements){
            cout << element << " ";
        }
        cout << endl;
    }

}