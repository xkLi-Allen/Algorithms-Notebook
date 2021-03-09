# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/sort-colors/
int init_num = -10000000;
class Solution{
    public:
    void sortColors(vector<int> &nums){
        int size = nums.size();
        int p0 = 0, p1 = 0;
        for(int i = 0; i < size; i++){
            if (nums[i] == 1){
                swap(nums[p1], nums[i]);
                p1++;
            }
            else if (nums[i] == 0){
                swap(nums[p0], nums[i]);
                if (p0 < p1){
                    swap(nums[i], nums[p1]);
                }
                p0++;
                p1++;
            }
        }
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
    solution.sortColors(input);
    cout << "answer: " << endl;
    for (auto element : input){
        cout << element << " ";
    }

}