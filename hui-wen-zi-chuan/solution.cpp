# include<iostream>
# include<string>
using namespace std;
// https://leetcode-cn.com/problems/palindromic-substrings/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)。
};

int main(){
    cout << "input s value" << endl;
    string s;
    cin >> s;
    Solution solution;
    int answer = solution.countSubstrings(s);
    cout << "answer: " << answer << endl;
}