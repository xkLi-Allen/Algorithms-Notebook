# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/permutations/
int init_num = -100;
class Solution {
    // 回溯法：一种通过探索所有可能的候选解来找出所有的解的算法。
    // 如果候选解被确认不是一个解（或者至少不是最后一个解），回溯算法会通过在上一步进行一些变化抛弃该解，即回溯并且再次尝试。
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);   // 二维 vector 插入一维 vector
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);     // 进行回溯操作时，需要进行一些操作来使输入数组返回上一步的结果
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());  // 0 表示一个 n 列的待填字符中该填第 0 位
        return res;
    }
    // 时间复杂度 O(n×n!)，其中 n 为序列的长度。
    // 空间复杂度：O(n)，其中 n 为序列的长度。除答案数组以外，递归函数在递归过程中需要为每一层递归函数分配栈空间，所以这里需要额外的空间且该空间取决于递归的深度，这里可知递归调用深度为 O(n)。
};

vector<int> _inputClean(vector<int> input){
    int n = 0;
    for(auto element: input){
        if (element != init_num){
            n++;
        }
    }
    vector<int> return_vector(n, init_num);
    n = 0;
    for(auto element: input){
        if(element != init_num){
            return_vector[n++] = element;
        }
    }
    return return_vector;
}
int main(){
    int n = 0;
    char c;
    vector<int> input(100, init_num);
    cout << "input numlists" << endl;
    cin >> input[n++];
    while((c = getchar()) != '\n'){
        cin >> input[n++];
    }
    input = _inputClean(input);
    // for(auto element: input){
    //     cout << element << " ";
    // }
    Solution solution;
    vector<vector<int>> answer = solution.permute(input);
    for (auto elements : answer){
        for (auto element : elements){
            cout << element << " ";
        }
        cout << endl;
    }

}