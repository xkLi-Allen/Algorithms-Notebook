# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
class Solution{
    public:
        void moveZeroes(vector<int>& nums){
            vector<int> temp(nums.size(), 0);
            int n = 0;
            for (auto element: nums){
                if (element != 0){
                    temp[n++] = element;
                }
            }
            nums = temp;
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
    Solution solution;
    solution.moveZeroes(input);
    cout << "answer: " << endl;
    for(vector<int> :: iterator cur = input.begin(); cur != input.end(); cur ++){
        cout << (*cur) << " ";
    }

}