# include<iostream>
# include<vector>
# include <algorithm>
using namespace std;
// https://leetcode-cn.com/problems/next-permutation/
int init_num = -100;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {  // 从后往前查找第一个顺序对 (i,i+1)，满足 a[i] < a[i+1] 则 a[i] 即为较小数
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {  // 从后往前查找第一个满足 a[j] > a[i] 的数 a[j] 即为较大数
                j--;
            }
            swap(nums[i], nums[j]);                 // 交换
        }
        reverse(nums.begin() + i + 1, nums.end());  // 反转
    }
    // 时间复杂度：O(N)，其中 N 为给定序列的长度。我们至多只需要扫描两次序列，以及进行一次反转操作。

    // 空间复杂度：O(1)，只需要常数的空间存放若干变量。
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
    vector<int> answer = input;
    solution.nextPermutation(answer);
    for(auto element : answer){
        cout << element << " ";
    }
}