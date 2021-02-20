
#include <vector> 
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
// https://leetcode-cn.com/problems/two-sum
int init_num = -10;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 暴力破解
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
    vector<int> twoSum_hash(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i}; // 如果查找到返回map中的value对应于nums中的序号
            }
            // key -> 对应于nums元素 value -> 对应于序号
            hashtable[nums[i]] = i;
        }
        return {};
    }
    void Print(vector<int>& nums){
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] != init_num)
                cout << nums[i] << " ";
        }
        cout << endl;
    }
};
// 
int main(){

    vector<int> input(100,init_num);
    int num = 0;
    int temp;
    char c;
    int target;
    cout << "input nums" << endl;
    cin >> input[num++];
    while((c = getchar()) != '\n'){
        cin >> temp;
        input[num++] = temp;
    }
    cout << "target nums" << endl;
    cin >> target;
    for(int i = 0; i < input.size(); ++i) {
        if (input[i] != init_num)
            cout << input[i] << " ";
    }
    cout << std::endl;
    Solution solution;
    vector<int> answer = solution.twoSum(input,target);
    solution.Print(answer);
    vector<int> answer_hash = solution.twoSum_hash(input,target);
    solution.Print(answer_hash);
    cout << "hello world" << endl;
    return 1;
}
