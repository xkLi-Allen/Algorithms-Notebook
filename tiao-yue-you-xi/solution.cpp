# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/jump-game/
int init_num = -10000000;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();    // 获取数组大小
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {   // 贪心算法遍历数组
            if (i <= rightmost) {       // 只有当当前位置可到达时才继续进行贪心求解
                rightmost = max(rightmost, i + nums[i]);    // 实时更新最大可达距离
                if (rightmost >= n - 1) {   // 当可达距离等于数组最后一个元素时则为 true
                    return true;
                }
            }
        }
        return false;
    }
    // 时间复杂度：O(n)，其中 n 为数组的大小。只需要访问 nums 数组一遍，共 n 个位置。
    // 空间复杂度：O(1)，不需要额外的空间开销。
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
    Solution solution;
    bool answer = solution.canJump(input);
    cout << "answer: " << answer << endl;

}