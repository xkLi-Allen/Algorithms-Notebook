# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) { // 当房屋数量为 0 时，直接返回 0
            return 0;
        }
        int size = nums.size();
        if (size == 1) {    // 当房屋数量为 1 时，只能选择偷窃当前房屋
            return nums[0];
        }
        vector<int> dp = vector<int>(size, 0);  // 创建动态规划数组，记录偷窃到当前房屋时所获得钱数的最大值
        dp[0] = nums[0];                        // 当只有一间房屋时，只能偷取当前房屋
        dp[1] = max(nums[0], nums[1]);          // 当有两间房屋时，选取其中钱数最大的那间房屋
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);    // 有两种策略：偷取当前 k 房屋，则 k-1 和 k+1 不可偷取，只能加上 k-2 的最大金额
        }//两种策略取 max                                    //            不偷取当前 k 房屋，则 k-1 和 k+1 可偷取，计算 k-1 的金额最大值
        return dp[size - 1];
    }
};
int main(){
    vector<int> input;
    char c;
    int n = 0;
    cout << "input numslist" << endl;
    int temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    Solution solution;
    int answer = solution.rob(input);
    cout << "answer: " << answer << endl;

}