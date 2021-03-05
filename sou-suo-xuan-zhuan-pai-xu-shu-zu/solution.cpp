# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
int init_num = -100;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {                               // 当输入的数组为空的特殊情况时
            return -1;
        }
        if (n == 1) {                           // 当输入的数组仅有一个数字的时候，无需查找直接判断即可
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;                   // 定义数组的左右边界
        while (l <= r) {                        // 二分查找循环
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {         // 根据旋转规则，则旋转后的数组是分块有序的，需要先进行判断看哪一部份是有序的
                if (nums[0] <= target && target < nums[mid]) {      // 二分查找
                    r = mid - 1;    
                } else {
                    l = mid + 1;
                }
            } 
            else {
                if (nums[mid] < target && target <= nums[n - 1]) {  // 二分查找
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
    // 时间复杂度： O(logn)，其中 n 为 nums 数组的大小。整个算法时间复杂度即为二分查找的时间复杂度 O(logn)。

    // 空间复杂度： O(1) 。我们只需要常数级别的空间存放变量。
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
    cout << "input target" << endl;
    int target;
    cin >> target;
    Solution solution;
    int answer = solution.search(input, target);
    cout << "answer: " << answer;
}