# include<iostream>
# include<string>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/decode-string/
class Solution {
public:
    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector <string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector <string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++])); 
            } else {
                ++ptr;
                vector <string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repTime = stoi(stk.back()); 
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (repTime--) t += o; 
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }
    // 时间复杂度：记解码后得出的字符串长度为 S，除了遍历一次原字符串 s，我们还需要将解码后的字符串中的每个字符都入栈，并最终拼接进答案中
    // 故渐进时间复杂度为 O(S+|s|)，即 O(S)。
    // 空间复杂度：记解码后得出的字符串长度为 S，这里用栈维护 TOKEN，栈的总大小最终与 S 相同，故渐进空间复杂度为 O(S)。
};
int main(){
    cout << "input string" << endl;
    string input;
    cin >> input;
    Solution solution;
    string answer = solution.decodeString(input);
    cout << "answer: " << answer << endl;
}