# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        // 这里的「处于冷冻期」指的是在第 i 天结束之后的状态。也就是说：如果第 i 天结束之后处于冷冻期，那么第 i+1 天无法买入股票。
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            // 对于 f[i][0]，我们目前持有的这一支股票可以是在第 i−1 天就已经持有的，对应的状态为 f[i−1][0]；
            // 或者是第 i 天买入的，那么第 i−1 天就不能持有股票并且不处于冷冻期中，对应的状态为 f[i−1][2] 加上买入股票的负收益 prices[i]。因此状态转移方程为：
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            // 对于 f[i][1]，我们在第 i 天结束之后处于冷冻期的原因是在当天卖出了股票，那么说明在第 i−1 天时我们必须持有一支股票，对应的状态为 f[i−1][0] 加上卖出股票的正收益 prices[i]。因此状态转移方程为：
            f[i][1] = f[i - 1][0] + prices[i];
            // 对于 f[i][2]，我们在第 i 天结束之后不持有任何股票并且不处于冷冻期，说明当天没有进行任何操作，即第 i−1 天时不持有任何股票：
            // 如果处于冷冻期，对应的状态为 f[i−1][1]；如果不处于冷冻期，对应的状态为 f[i−1][2]。因此状态转移方程为：
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        // 注意到如果在最后一天（第 n−1 天）结束之后，手上仍然持有股票，那么显然是没有任何意义的。因此更加精确地，最终的答案实际上是 f[n−1][1] 和 f[n−1][2] 中的较大值，即：
        return max(f[n - 1][1], f[n - 1][2]);
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
    int answer = solution.maxProfit(input);
    cout << "answer: " << answer << endl;
    

}