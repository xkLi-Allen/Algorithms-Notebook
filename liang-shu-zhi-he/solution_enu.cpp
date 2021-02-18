
#include <vector> 
#include <iostream>
#include <list>
using namespace std;
int init_num = -10;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
    cin >> input[num++];
    while((c = getchar()) != '\n'){
        cin >> temp;
        input[num++] = temp;
    }
    cin >> target;
    for(int i = 0; i < input.size(); ++i) {
        if (input[i] != init_num)
            cout << input[i] << " ";
    }
    cout << std::endl;
    Solution solution;
    vector<int> answer = solution.twoSum(input,target);
    solution.Print(answer);
    cout << "hello world" << endl;
    return 1;

}
