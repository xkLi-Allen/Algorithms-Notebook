# include<iostream>
# include<vector>
# include<algorithm>
# include<numeric>
using namespace std;
// https://leetcode-cn.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0, maxNum = 0;
        for (auto& num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<int> dp(target + 1, 0);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = target; j >= num; --j) {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
    // 时间复杂度：O(n×target)，其中 n 是数组的长度，target 是整个数组的元素和的一半。需要计算出所有的状态，每个状态在进行转移时的时间复杂度为 O(1)。

    // 空间复杂度：O(target)，其中 target 是整个数组的元素和的一半。空间复杂度取决于 dp 数组，在不进行空间优化的情况下，空间复杂度是 O(n×target)
    // 在进行空间优化的情况下，空间复杂度可以降到 O(target)。

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
    bool answer = solution.canPartition(input);
    cout << "answer: " << answer << endl;

}