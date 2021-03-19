# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_map>
using namespace std;
// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
class Solution{
    public:
        int findKthLargest(vector<int>& nums, int k){
            // sort(nums.rbegin(), nums.rend());
            sort(nums.begin(),  nums.end());
            reverse(nums.begin(), nums.end());
            unordered_map<int, int> temp;
            int n = 1;
            for (int i = 0; i < nums.size(); i++){
                temp.insert(pair<int, int>(n, nums[i]));
                n++;
            }
            return temp.find(k) -> second;
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
    cout << "input K value" << endl;
    int K;
    cin >> K;
    Solution solution;
    int answer = solution.findKthLargest(input, K);
    cout << "answer: " << answer;
}