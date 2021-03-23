# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/longest-increasing-subsequence/
class Solution{
    public:
        int lengthOfLIS(vector<int> &nums){
            if (nums.size() == 0){
                return 0;
            }
            vector<int> dp(nums.size()-1);
            for (int i = 1; i < nums.size(); i++){
                dp[i] = 1;
                for (int j = 0; j < i; j++){
                    if (nums[i] > nums[j]){
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            return *max_element(dp.begin(), dp.end());
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
    int answer = solution.lengthOfLIS(input);
    cout << "answer: " << answer << endl;

}