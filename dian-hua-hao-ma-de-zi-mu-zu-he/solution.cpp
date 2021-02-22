# include<iostream>
# include<vector>
# include<unordered_map>
using namespace std;
// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
class Solution {
    // 回溯算法
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;    // 存储全部可能的序列
        if (digits.empty()) {
            return combinations;
        }
        // 创建对应哈希表
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination; // 存储其中一种可能的字母序列
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
        if (index == digits.length()) {
            combinations.push_back(combination);        // 只有当全部数字遍历一遍的时候才压入combinations
        } else {
            char digit = digits[index];
            const string& letters = phoneMap.at(digit); // letters存储可能的多个字符
            for (const char& letter: letters) {
                combination.push_back(letter);
                // cout << "combination : " << combination << endl;
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();                 // 实现前一个字符确定后，后一个字符的多种可能性
                // cout << "combination : " << combination << endl;
            }
        }
    }
    // 时间复杂度：O(3^m x 4^n)，其中 m 是输入中对应 3 个字母的数字个数（包括数字 2、3、4、5、6、8），n 是输入中对应 4 个字母的数字个数（包括数字 7、9），m+n 是输入数字的总个数。
    // 当输入包含 m 个对应 3 个字母的数字和 n 个对应 4 个字母的数字时，不同的字母组合一共有 3^m x 4^n种，需要遍历每一种字母组合。
    // 空间复杂度：O(m+n)，其中 mm 是输入中对应 3 个字母的数字个数，n 是输入中对应 4 个字母的数字个数，m+n 是输入数字的总个数。
    // 除了返回值以外，空间复杂度主要取决于哈希表以及回溯过程中的递归调用层数，哈希表的大小与输入无关，可以看成常数，递归调用层数最大为 m+n。
};
int main(){
    string input;
    cout << "input string" << endl;
    cin >> input;
    Solution solution;
    vector<string> answer = solution.letterCombinations(input);
    for (auto element : answer){
        cout << element << " ";
    }
}