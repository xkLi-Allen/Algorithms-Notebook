# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/maximum-product-subarray/
int init_num = -10000000;
class Solution {
public:
    // 动态规划
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));   // 如果当前位置是一个正数的话，我们更希望以它前一个位置结尾的某个段的积也是个正数，并且希望它尽可能地大
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));   // 考虑当前位置如果是一个负数的话，那么我们希望以它前一个位置结尾的某个段的积也是个负数，这样就可以负负得正，并且我们希望这个积尽可能「负得更多」，即尽可能小
            ans = max(maxF, ans);   // ans 存储目前已有的最大乘积
        }
        return ans;
    }
    // 记 nums 元素个数为 nn。
    // 时间复杂度：程序一次循环遍历了 nums，故渐进时间复杂度为 O(n)O(n)。

    // 空间复杂度：优化后只使用常数个临时变量作为辅助空间，与 nn 无关，故渐进空间复杂度为 O(1)O(1)。
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
    // for(auto element : input){
    //     if(element != init_num){
    //         cout << element << " ";
    //     }
    // }

}