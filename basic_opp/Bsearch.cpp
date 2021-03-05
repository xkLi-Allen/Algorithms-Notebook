# include<iostream>
# include<vector>
using namespace std;
int init_num = -100;
class Solution {
public:
    // 查找已递增排序数组A中 大于等于（或者大于） 给定target的 第一个 元素的下标
    // 当eq_enable为true时  对应 [大于等于] 的情况
    // 当eq_enable为false时 对应 [大于] 的情况
    int Bsearch_GE_or_G(vector <int> input, int target, bool eq_enable){
        int left = 0; int right = input.size() - 1;
        int ans = input.size();
        while(left <= right){
            // int mid = (left + right) /2;    //上面的这种写法可能会造成int求和溢出，因此统一写成下面的这种形式
            int mid = left + (right - left) /2;
            if (target < input[mid]|| (eq_enable && target == input[mid])){
                ans = mid;
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
    // 查找已递增排序数组A中 小于等于（或者小于） 给定target的 最后一个 元素的下标
    // 当eq_enable为true时  对应 [小于等于] 的情况
    // 当eq_enable为false时 对应 [小于] 的情况
    int Bsearch_LE_or_L(vector <int> input, int target, bool eq_enable){
        int left = 0; int right = input.size() - 1;
        int ans = input.size();
        while(left <= right){
            // int mid = (left + right) /2;    //上面的这种写法可能会造成int求和溢出，因此统一写成下面的这种形式
            int mid = left + (right - left) /2;
            if (target > input[mid] || (eq_enable && target == input[mid])){
                ans = mid;
                left = mid + 1;

            }
            else{
                right = mid -1;
            }
        }
        return ans;
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
    int answer1 = solution.Bsearch_GE_or_G(input, target, true);
    int answer2 = solution.Bsearch_LE_or_L(input, target, true);
    cout << "answer1: " << answer1 << endl;
    cout << "answer2: " << answer2 << endl;
}