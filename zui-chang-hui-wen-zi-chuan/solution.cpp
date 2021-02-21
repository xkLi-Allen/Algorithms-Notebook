# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/longest-palindromic-substring/
/*
在状态转移方程中，是从长度较短的字符串向长度较长的字符串进行转移的，因此一定要注意动态规划的循环顺序。
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));  // 根据输入的字符串，创建对应大小的二维vector dp[i][j] 表示字符串从 i 到 j 是否为回文字符串
        string ans;                                 // 最长回文字符串
        for (int l = 0; l < n; ++l) {           // l 定义回文字符串长度
            for (int i = 0; i + l < n; ++i) {   // i 相当于字符串的头部指针、j相当于字符串的尾部指针
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;               // 当输入字符串长度为1时，直接对应就是回文字符串
                } 
                else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);  // 当输入字符串长度为2时，只要两个字母相同就是回文字符串，否则不是
                } 
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {   // 取最长的回文字符串
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
    // 时间复杂度：O(n^2)，其中 n 是字符串的长度。动态规划的状态总数为 O(n^2)，对于每个状态，我们需要转移的时间为 O(1)。
    // 空间复杂度：O(n^2)，即存储动态规划状态需要的空间。
};
int main(){
    string input;
    cout << "input string" << endl;
    cin >> input;
    cout << "input string is : " << input << endl;
    Solution solution;
    string answer = solution.longestPalindrome(input);
    cout << "The longest string of input : " << answer;
}