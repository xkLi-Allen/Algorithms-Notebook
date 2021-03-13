# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_map>
using namespace std;
// https://leetcode-cn.com/problems/single-number/
int init_num = -10000000;
class Solution{
    public:
        int singleNumber(vector<int> &nums){
            unordered_map<int, int> map;
            for (int i = 0; i < nums.size(); i++){
                if (map[nums[i]] == 1){
                    map[nums[i]] += 1;
                }
                else{
                    map[nums[i]] = 1;
                }
            }
            for (unordered_map<int, int> :: iterator iter = map.begin(); iter != map.end(); iter++){
                if (iter -> second == 1){
                    return iter -> first;
                }
            }
            return -1;
        }
        int singleNumber_n(vector<int>& nums) {
            int ret = 0;
            for (auto e: nums) ret ^= e;
            return ret;
            // 时间复杂度：O(n)，其中 n 是数组长度。只需要对数组遍历一次。

            // 空间复杂度：O(1)。
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
    int answer = solution.singleNumber(input);
    cout << "answer : " << answer << endl;
    int answer_n = solution.singleNumber_n(input);
    cout << "answer : " << answer_n << endl;

}