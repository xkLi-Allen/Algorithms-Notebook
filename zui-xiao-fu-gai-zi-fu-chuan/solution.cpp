# include<iostream>
# include<unordered_map>
using namespace std;
// https://leetcode-cn.com/problems/minimum-window-substring/
class Solution {
public:
    // ori用来存储要匹配的字符串哈希
    unordered_map <char, int> ori, cnt;
    // 如何判断当前的窗口包含所有 t 所需的字符呢？
    // 我们可以用一个哈希表表示 t 中所有的字符以及它们的个数，用一个哈希表动态维护窗口中所有的字符以及它们的个数.
    // 如果这个动态表中包含 t 的哈希表中的所有字符，并且对应的个数都不小于 t 的哈希表中各个字符的个数，那么当前的窗口是「可行」的。

    bool check() {
        for (const auto &p: ori) {              // 判断哈希中 每一个需要匹配的字符的数量 只有当所有字符数大于或者等于的时候则可以判断全部包含，否则返回false
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        // 将要匹配的字符串存入ori  对应结构为 字符 - 出现的次数
        for (const auto &c: t) {
            ++ori[c];       
            // for (auto &element:ori){
            //     cout << element.first << element.second << " " ;
            // }
            // cout << endl;
            // cout << ori[c] << endl;
        }

        int l = 0, r = -1;  // 定义滑动窗口的双指针位置

        int len = 1000000, ansL = -1, ansR = -1;
        // 被匹配的字符串 s
        // 将被匹配的字符串存入 cnt 哈希 对应结构为 字符 - 出现的次数
        // 要匹配的字符串 t
        // 将要匹配的字符串存入 ori 哈希 对应结构为 字符 - 出现的次数
        // s为需要匹配的字符串
        
        while (r < int(s.size())) {                 // 根据题意，不一定需要符合顺序
            if (ori.find(s[++r]) != ori.end()) {    // 滑动有窗口指针，判断目前判断的字符是否是需要匹配的字符
                ++cnt[s[r]];                        
            }
            while (check() && l <= r) {             // 用来判断当前的窗口是否包含所有 t 中字符
                if (r - l + 1 < len) {
                    len = r - l + 1;                // 更新窗口长度
                    ansL = l;                       // ansL 代表窗口目前的左指针
                }
                if (ori.find(s[l]) != ori.end()) {  // 此时判断的字符是要匹配的字符，则在左指针右移的时候相应的哈希需要减少
                    --cnt[s[l]];                   
                }
                ++l;    // 如果当前的字符不是需要匹配的字符，则对窗口的大小进行优化，也就是左指针右移
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len); // 进行字符串的截取，得到最终答案
    }
    // 时间复杂度：最坏情况下左右指针对 s 的每个元素各遍历一遍，哈希表中对 s 中的每个元素各插入、删除一次，对 t 中的元素各插入一次。每次检查是否可行会遍历整个 t 的哈希表，哈希表的大小与字符集的大小有关，设字符集大小为 C，则渐进时间复杂度为 O(C⋅∣s∣+∣t∣)。
    // 空间复杂度：这里用了两张哈希表作为辅助空间，每张哈希表最多不会存放超过字符集大小的键值对，我们设字符集大小为 C ，则渐进空间复杂度为 O(C)。
};
int main(){
    string test = "test";
    for(int i=0 ; i < int(test.size()) ; i++){
        cout << "test : "<< i <<" ："<< test[i] << endl;
    }
    string str1, str2;
    cout << "input str1" << endl;
    cin >> str1;
    cout << "input str2" << endl;
    cin >> str2;
    Solution solution;
    string answer = solution.minWindow(str1, str2);
    cout << "answer: " << answer << endl;

}