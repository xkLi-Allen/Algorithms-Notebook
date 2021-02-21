#include<iostream>
#include<unordered_set>
using namespace std;
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // !occ.count(s[rk + 1]) 该条件用于判断目前该字符是否已经存在于我的窗口中
                // 不断地移动右指针
                occ.insert(s[rk + 1]);  // 将窗口字符串加入哈希集合
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
    // 时间复杂度：O(N)O(N)，其中 NN 是字符串的长度。左指针和右指针分别会遍历整个字符串一次。

    // 空间复杂度：O(∣Σ∣)，其中 Σ 表示字符集（即字符串中可以出现的字符），∣Σ∣ 表示字符集的大小。
    // 在本题中没有明确说明字符集，因此可以默认为所有 ASCII 码在 [0, 128) 内的字符，即 ∣Σ∣=128。
    // 我们需要用到哈希集合来存储出现过的字符，而字符最多有 ∣Σ∣ 个，因此空间复杂度为 O(∣Σ∣)。
};

int main(){
    string s;
    cout << "input string" << endl;
    cin >> s;
    Solution solution;
    int answer = solution.lengthOfLongestSubstring(s);
    cout << answer << endl;
}