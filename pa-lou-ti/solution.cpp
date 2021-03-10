# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/climbing-stairs/
int init_num = -1000;
class solution{
    public:
    int climbStairs(int n){
        // vector<int> f(n, init_num);
        // f[0] = 1;
        // f[1] = 1;
        // if (n == 0){
        //     return f[0];
        // }
        // else if (n == 1){
        //     return f[1];
        // }
        // for (int i = 2; i <= n; i++){
        //     f[i] = f[i-1] + f[i-2];
        // }
        // return f[n];
        int step0 = 1;
        int step1 = 1;
        int step2;
        if (n == 0){
            return step0;
        }
        else if (n == 1){
            return step1;
        }
        for (int i = 2; i <= n; i++){
            step2 = step0 + step1;
            step0 = step1;
            step1 = step2;
        }
        return step2;
    }

};
int main(){
    cout << "input number" << endl;
    int n;
    cin >> n;
    solution solution;
    int answer = solution.climbStairs(n);
    cout << "answer :" << answer << endl;
}