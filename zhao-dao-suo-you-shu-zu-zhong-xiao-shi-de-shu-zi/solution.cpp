# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_map>
using namespace std;
// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto& num : nums) {
            int x = (num - 1) % n;
            // cout << nums[x] << endl;

            nums[x] += n;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
    // 时间复杂度：O(n)。其中 n 是数组 nums 的长度。

    // 空间复杂度：O(1)。返回值不计入空间复杂度。
};
int main(){
    vector<int> input;
    char c;
    cout << "input numslist" << endl;
    int temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    Solution solution;
    vector<int> answer = solution.findDisappearedNumbers(input);
    cout << "answer: " << endl;
    for (auto element : answer){
        cout << element << " ";
    }
}