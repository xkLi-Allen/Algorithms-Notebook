# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int begin = nums.size() - 1;
        int end = 0;
        int flag = 1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != sorted_nums[i]){
                begin = min(begin, i);
                end = max(end, i);
                flag = 0;
            }
        }
        if (flag){
            return 0;
        }
        return (end - begin) + 1;
    }
    // 时间复杂度：O(nlogn) 。排序消耗 nlogn 的时间。

    // 空间复杂度：O(n) 。我们拷贝了一份原数组来进行排序。
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
    int answer = solution.findUnsortedSubarray(input);
    cout << "answer: " << answer << endl;
}