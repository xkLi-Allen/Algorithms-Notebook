# include<iostream>
# include<unordered_set>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1); // 定义动态规划数组 dp[i] 代表字符串的前 i 个字符是否满足字典中的单词
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {   // 因此只需要判断 dp[i] 和 经过划分的后半部分字串是否满足条件即可
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
    // 时间复杂度：O(n^2)，其中 n 为字符串 s 的长度。我们一共有 O(n) 个状态需要计算，每次计算需要枚举 O(n) 个分割点，哈希表判断一个字符串是否出现在给定的字符串列表需要 O(1) 的时间，因此总时间复杂度为 O(n^2)

    // 空间复杂度：O(n) ，其中 n 为字符串 s 的长度。我们需要 O(n) 的空间存放 dp 值以及哈希表亦需要 O(n) 的空间复杂度，因此总空间复杂度为 O(n)。
};


int main(){
    cout << "input str" << endl;
    string input;
    cin >> input;
    cout << "input wordDict" << endl;
    vector <string> wordDict;
    string temp;
    char c;
    cin >> temp;
    wordDict.push_back(temp);
    while ((c = getchar()) != '\n'){
        cin >> temp;
        wordDict.push_back(temp);
        
    }
    for (auto word : wordDict){
        cout << word << " " ;
    }
    cout << endl;
    Solution solution;
    bool answer = solution.wordBreak(input, wordDict);
    cout << "answer : " << answer;
}