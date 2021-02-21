# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/container-with-most-water/
class Solution {
public:
    /*双指针代表的是 可以作为容器边界的所有位置的范围。
    在一开始，双指针指向数组的左右边界，表示 数组中所有的位置都可以作为容器的边界，因为我们还没有进行过任何尝试。
    在这之后，我们每次将 对应的数字较小的那个指针 往 另一个指针 的方向移动一个位置，就表示我们认为 这个指针不可能再作为容器的边界了。
    */
    // 时间复杂度：O(N)，双指针总计最多遍历整个数组一次。
    // 空间复杂度：O(1)，只需要额外的常数级别的空间。
    int maxArea(vector<int>& height) {  
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
};
int init_num = -10;
int main(){
    vector<int> input(100,init_num);
    char c;
    int n = 0;
    cout << "input height vector" <<endl;
    cin >> input[n++];
    while((c=getchar())!='\n'){
        cin >> input[n++];
    }
    // for(auto element : input){
    //     if (element != init_num){
    //         cout << element << " ";
    //     }

    // }
    // cout << endl;
    Solution solution;
    int answer = solution.maxArea(input);
    cout << "Answer is : " << answer << endl;
}