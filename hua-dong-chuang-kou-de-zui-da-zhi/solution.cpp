# include<iostream>
# include<vector>
# include<algorithm>
#include <queue>
using namespace std;
// https://leetcode-cn.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;   // pair的比较，先比较第一个元素，第一个相等比较第二个
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        // cout << "priority_queue<pair<int, int>> q;" << endl;
        // auto temp = q;
        // while (!temp.empty()) {
        // cout << temp.top().first << ' ' << temp.top().second << '\n';
        // temp.pop();
        // }
        vector<int> ans = {q.top().first};  // 将初始窗口中的最大值加入到 ans vector<int> 中
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {   // 如果最大值元素在窗口的左侧，窗口向右滑动，不可能继续取到该值
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
    // 时间复杂度：O(nlogn)，其中 n 是数组 nums 的长度。在最坏情况下，数组 nums 中的元素单调递增，那么最终优先队列中包含了所有元素，没有元素被移除。
    // 由于将一个元素放入优先队列的时间复杂度为 O(logn)，因此总时间复杂度为 O(nlogn)。

    // 空间复杂度：O(n)，即为优先队列需要使用的空间。这里所有的空间复杂度分析都不考虑返回的答案需要的 O(n) 空间，只计算额外的空间使用。

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
    cout << "input wideWindow value" << endl;
    int k;
    cin >> k;
    Solution solution;
    vector<int> answer = solution.maxSlidingWindow(input, k);
    for (vector<int> :: iterator cur = answer.begin(); cur != answer.end(); cur ++){
        cout << (*cur) << " ";
    }

}