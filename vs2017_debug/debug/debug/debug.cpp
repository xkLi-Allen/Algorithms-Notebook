# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		vector<vector<int>> dp(nums.size(), vector<int>(2001));
		dp[0][nums[0] + 1000] = 1;
		dp[0][-nums[0] + 1000] = 1;
		for (int i = 0; i < nums.size(); i++) {
			for (int sum = -1000; sum <= 1000; sum++) {
				if (dp[i - 1][sum + 1000] > 0) {
					dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
					dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
				}
			}
		}
		return S > 1000 ? 0 : dp[nums.size() - 1][S + 1000];
	}
	// 时间复杂度：O(N∗sum)，其中 N 是数组 nums 的长度。

	// 空间复杂度：O(N∗sum)。
};
int main() {
	vector<int> input;
	char c;
	int n = 0;
	cout << "input numslist" << endl;
	int temp;
	cin >> temp;
	input.push_back(temp);
	while ((c = getchar()) != '\n') {
		cin >> temp;
		input.push_back(temp);
	}
	cout << "input S value" << endl;
	int S;
	cin >> S;
	Solution solution;
	int answer = solution.findTargetSumWays(input, S);
	cout << "answer: " << answer << endl;

}