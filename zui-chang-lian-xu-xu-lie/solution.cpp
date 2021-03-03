# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_set>
using namespace std;
// https://leetcode-cn.com/problems/longest-consecutive-sequence/
int init_num = -10000000;
class Solution {
public:
    // 为了减少时间复杂度，对于枚举的元素进行限制，要确定该枚举的元素 x 一定不存在前驱 x-1 
    // 因为如果存在前驱就一定不是最优的 == 依靠检查哈希中 x-1 是否存在来判断是否跳过
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {  // 如果元素 x-1 没有出现在哈希中
                int currentNum = num;       // 保存现有进行枚举的元素 x
                int currentStreak = 1;      // 作为枚举列表中的第一个元素

                while (num_set.count(currentNum + 1)) {     // 判断元素 x 递增的元素是否存在
                    currentNum += 1;                        // 如果存在保存递增的元素
                    currentStreak += 1;                     // 增加列表的长度
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
    // 时间复杂度：O(n)，其中 n 为数组的长度。具体分析已在上面正文中给出。

    // 空间复杂度：O(n)。哈希表存储数组中所有的数需要 O(n) 的空间。
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
    int answer = solution.longestConsecutive(input);
    cout << "answer: " << answer << endl;

}