# include<iostream>
using namespace std;
// https://leetcode-cn.com/problems/hamming-distance/
class Solution {
public:
    int hammingDistance(int x, int y) {
        //异或：找到哪几位不一样
        int temp = x^y;
        int res = 0;
        //统计有多少个不一样的位，也就是有多少个1
        while (temp > 0){
            res += temp % 2;
            temp /= 2;
        }
        return res;
    }
};
int main(){
    cout << "input x value" << endl;
    int x;
    cin >> x;
    cout << "input y value" << endl;
    int y;
    cin >> y;
    Solution solution;
    int distance = solution.hammingDistance(x, y);
    cout << "answer: " << distance;
}