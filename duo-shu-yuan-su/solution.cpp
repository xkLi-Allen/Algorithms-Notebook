# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
int init_num = -10000000;
// https://leetcode-cn.com/problems/majority-element
class Solution {
    int count_in_range(vector<int>& nums, int target, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; ++i)
            if (nums[i] == target)
                ++count;
        return count;
    }
    int majority_element_rec(vector<int>& nums, int lo, int hi) {
        // 长度为 1 的子数组中唯一的数显然是众数，直接返回即可
        if (lo == hi)
            return nums[lo];    
        // 如果回溯后某区间的长度大于 1，我们必须将左右子区间的值合并。如果它们的众数相同，那么显然这一段区间的众数是它们相同的值。
        // 否则，我们需要比较两个众数在整个区间内出现的次数来决定该区间的众数。
        int mid = (lo + hi) / 2;    // 第一次执行将数组分为两部分
        int left_majority = majority_element_rec(nums, lo, mid);        // 左部分不断迭代，直到变为一个数，该数为此时的左部分众数 
        int right_majority = majority_element_rec(nums, mid + 1, hi);   // 右部分不断迭代，直到变为一个数，该数为此时的右部分众数 
        if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2)    // 比较此时左部分众数的出现次数，进行众数的合并
            return left_majority;
        if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2)   // 比较此时有部分的出现次数，进行众数的合并
            return right_majority;
        return -1;
        // 时间复杂度：O(nlogn)
        // 空间复杂度：O(logn)。尽管分治算法没有直接分配额外的数组空间，但在递归的过程中使用了额外的栈空间。
        // 算法每次将数组从中间分成两部分，所以数组长度变为 1 之前需要进行 O(logn) 次递归，即空间复杂度为 O(logn)。
    }
public:
    int majorityElement(vector<int>& nums) {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
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
    vector<int> input(100, init_num);
    char c;
    int n = 0;
    cout << "input numslist" << endl;
    cin >> input[n++];
    while((c = getchar()) != '\n'){
        cin >> input[n++];
    }
    input = inputclean(input);
    Solution solution;
    int answer = solution.majorityElement(input);
    cout << "answer: " << answer << endl;


}