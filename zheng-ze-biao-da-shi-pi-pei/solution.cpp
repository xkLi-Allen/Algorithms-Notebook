# include<iostream>
# include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {  // 判断两个字符是否匹配的辅助函数
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));   // f[i][j]表示 s 的前 i 个字符与 p 中的前 j 个字符是否能够匹配。在进行状态转移时，我们考虑 p 的第 j 个字符的匹配情况：
        f[0][0] = true;                                     // 两个空字符串是可以匹配的，答案为true
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {                  // 先判断符号
                if (p[j - 1] == '*') {
                    // 不匹配字符，将该组合扔掉，不再进行匹配 OR 匹配 s 末尾的一个字符，将该字符扔掉，而该组合还可以继续进行匹配；
                    f[i][j] |= f[i][j - 2];                 
                    if (matches(i, j - 1)) {                // 此处传入 match 函数中就变成和 p[j-2] 匹配了      
                        f[i][j] |= f[i - 1][j];             
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];         // 如果是 . 或者小写字母的话直接匹配，如果可以匹配则为true
                    }
                }
            }
        }
        return f[m][n];
    }
};

int main(){
    string input_a;
    cout << "input s" << endl;
    cin >> input_a;
    cout << "input is : " << input_a << endl;
    string input_b;
    cout << "input p" << endl;
    cin >> input_b;
    cout << "input is : " << input_b << endl;
    Solution solution;
    bool answer = solution.isMatch(input_a, input_b);
    cout << "Match : " << answer << endl;
}