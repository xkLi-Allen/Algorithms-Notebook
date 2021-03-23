# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1; 
        while (l <= r) {
            int mid = (l + r) / 2;  // 根据二叉查找的原理，首先计算 mid
            int cnt = 0;
            for (int i = 0; i < n; ++i) {   //  根据 mid 遍历数组，统计小于该 mid 的元素个数
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {   // 如果小于 mid 元素个数，说明重复元素一定在数组右侧，所以左区间需要随之改变
                l = mid + 1;
            } else {            // 如果大于 mid 元素个数，说明重复元素一定在数组左侧，所以右区间需要随之改变
                r = mid - 1;
                ans = mid;      
            }
        }
        return ans;
    }
    // 时间复杂度：O(nlogn)，其中 n 为 nums 数组的长度。二分查找最多需要二分 O(logn) 次，每次判断的时候需要 O(n) 遍历 nums 数组求解小于等于 mid 的数的个数，因此总时间复杂度为 O(nlogn)。
    // 空间复杂度：O(1)。我们只需要常数空间存放若干变量。
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
    int answer = solution.findDuplicate(input);
    cout << "answer: " << answer << endl;

}