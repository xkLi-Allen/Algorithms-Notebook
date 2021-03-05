# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
int init_num = -100;
// 考虑 target 开始和结束位置，其实我们要找的就是数组中「第一个等于 target 的位置」（记为 leftIdx）和「第一个大于 target 的位置减一」（记为 rightIdx）。


class Solution { 
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {   // 如果 lower 为 true，则查找第一个大于等于 target 的下标，否则查找第一个大于 target 的下标。
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) { // 根据查找的第一个大于等于 target 元素的下标减一的对应元素还要判断是否相等
            return vector<int>{leftIdx, rightIdx};
        } 
        return vector<int>{-1, -1};
    }
    // 时间复杂度： O(logn) ，其中 n 为数组的长度。二分查找的时间复杂度为 O(logn)，一共会执行两次，因此总时间复杂度为 O(logn)。

    // 空间复杂度：O(1) 。只需要常数空间存放若干变量。

};
vector<int> inputclean(vector<int> input){
    int n = 0;
    for(auto element : input){
        if(element != init_num){
            n++;
        }
    }
    vector<int> inputreturn(n, init_num);
    n = 0;
    for(auto element : input){
        if(element != init_num){
            inputreturn[n++] = element;
        }
    }
    return inputreturn;
}
int main(){
    char c;
    int n = 0;
    vector<int> input(100,init_num);
    cout << "input numlists" << endl;;
    cin >> input[n++];
    while((c=getchar()) != '\n'){
        cin >> input[n++];
    }
    input = inputclean(input);
    // for(auto element : input){
    //     cout << element << " ";
    // }
    Solution solution;
    cout << "input target" << endl;
    int target;
    cin >> target;
    vector<int> answer = solution.searchRange(input, target);
    for(auto element : answer){
        cout << element << " ";
    }
}