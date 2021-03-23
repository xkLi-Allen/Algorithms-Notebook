# include<iostream>
# include<algorithm>
# include<vector>
# include<limits>
using namespace std;
// https://leetcode-cn.com/problems/perfect-squares/
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, 0);	// 首先初始化长度为 n+1 的数组 dp，每个位置都为 0
		for (int i = 0; i <= n; i++) { // 对数组进行遍历，下标为 i，每次都将当前数字先更新为最大的结果，即 dp[i]=i，比如 i=4，最坏结果为 4=1+1+1+1 即为 4 个数字
			dp[i] = i;
			for (int j = 1; i - j * j >= 0; j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);	// 动态转移方程为：dp[i] = MIN(dp[i], dp[i - j * j] + 1)，i 表示当前数字，j*j 表示平方数
			}
		}


		return dp[n];
	}
	// 时间复杂度：O(n∗sqrt(n))，sqrt 为平方根
};
int main() {
	cout << "input n value" << endl;
	int n;
	cin >> n;
	Solution solution;
	int answer = solution.numSquares(n);
	cout << "answer: " << answer;

}