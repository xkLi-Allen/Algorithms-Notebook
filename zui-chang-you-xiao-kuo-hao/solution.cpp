# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/longest-valid-parentheses/
class Solution {
public:
    // dp[i] 表示以下标 i 字符结尾的最长有效括号的长度。
    // dp 数组全部初始化为 0 。显然有效的子串一定以 ')' 结尾，因此我们可以知道以 '(' 结尾的子串对应的 dp 值必定为 0 
    // 我们只需要求解 ')' 在 dp 数组中对应位置的值。
    // s[i]=')' and s[i-1]='(' string = "...()" -> dp[i] = dp[i-2] + 2 // 结束部分的 "()" 是一个有效子字符串，并且将之前有效子字符串的长度增加了 2 。
    // s[i]=')' and s[i-1]=')' string = "...))" -> dp[i] = dp[i-1] + dp[i-dp[i-1]-2]] + 2
    // 如果倒数第二个 ')' 是一个有效子字符串的一部分(记作 sub_s)
    // 对于最后一个 ')' ，如果它是一个更长子字符串的一部分，那么它一定有一个对应的 '(' ，且它的位置在倒数第二个 ')' 所在的有效子字符串的前面(也就是 sub_s的前面)。
    // 因此，如果子字符串 sub_s的前面恰好是 '(' ，那么我们就用 2 加上 sub_s 的长度(dp[i−1])去更新 dp[i]。
    // 同时，我们也会把有效子串 "(sub_s)" 之前的有效子串的长度也加上，也就是再加上 dp[i−dp[i−1]−2]。

    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } 
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
    // 时间复杂度： O(n)，其中 n 为字符串的长度。我们只需遍历整个字符串一次，即可将 dp 数组求出来。
    // 空间复杂度： O(n)。我们需要一个大小为 n 的 dp 数组。

};
int main(){
    string input;
    cout << "input string" << endl;
    cin >> input;
    Solution solution;
    int answer = solution.longestValidParentheses(input);
    cout << "answer: " << answer << endl;
}