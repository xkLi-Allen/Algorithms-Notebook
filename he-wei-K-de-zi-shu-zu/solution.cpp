# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_map>
using namespace std;
// https://leetcode-cn.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> temp_map;
        int presum = 0;
        int answer = 0;
        temp_map[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            presum += nums[i];
            
            if (temp_map.find(presum - k) != temp_map.end()){
                answer += temp_map[presum - k];
            }
            temp_map[presum]++;
        }
        return answer;
    }
};
int main(){
    vector<int> input;
    char c;
    int n = 0;
    cout << "input numslist" << endl;
    int temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    cout << "input k value" << endl;
    int k;
    cin >> k;
    Solution solution;
    int answer = solution.subarraySum(input, k);
    cout << "answer: " << answer << endl;

}