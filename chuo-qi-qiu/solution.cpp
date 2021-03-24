# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/burst-balloons
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();    // 获取数组大小，也就是气球的数量
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));     // dp 初始化 dp[i][j] 表示填满开区间 (i,j) 能得到的最多硬币数，那么边界条件是 i ≥ j−1，此时有 dp[i][j]=0。
        vector<int> val(n + 2);     // 预处理数组，根据题中条件，防止数组越界
        val[0] = val[n + 1] = 1;    // 根据题意，防止越界，边界值置为 1
        for (int i = 1; i <= n; i++) {  // 赋值操作，获取气球本身的分数
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], sum);
                }
            }
        }
        return dp[0][n + 1];
    }
    // 时间复杂度：O(n^3)，其中 n 是气球数量。状态数为 n^2，状态转移复杂度为 O(n)，最终复杂度为 O(n^2 x n) = O(n^3)
    // 空间复杂度：O(n^2)，其中 n 是气球数量。
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
    int answer = solution.maxCoins(input);
    cout << "answer: " << answer << endl;

}