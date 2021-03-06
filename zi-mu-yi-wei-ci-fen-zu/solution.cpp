# include<iostream>
# include<vector>
# include<unordered_map>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/group-anagrams/
string init_str = "abc";
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {    // 由于字母异位词的两个字符串包含的字母相同，因此对两个字符串分别进行排序之后得到的字符串一定是相同
        unordered_map<string, vector<string>> mp;   // 基于此创建哈希，以排序后的结果作为哈希的键
        for (string& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }   // 基于该循环就得到了一个哈希，其中键对应于排序后的字符串，value对应原始 vector 中的输入
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }   // 将对应的每个键的 value 取出 (这里的value可能对应多个string)
        return ans;
    }
    // 时间复杂度：O(nklogk)，其中 n 是 strs 中的字符串的数量，k 是 strs 中的字符串的的最大长度。
    // 需要遍历 n 个字符串，对于每个字符串，需要 O(klogk) 的时间进行排序以及 O(1) 的时间更新哈希表，因此总时间复杂度是 O(nklogk)。

    // 空间复杂度：O(nk)，其中 n 是 strs 中的字符串的数量，k 是 strs 中的字符串的的最大长度。需要用哈希表存储全部字符串。
};
vector<string> _inputClean(vector<string> input){
    int n = 0;
    for(auto element : input){
        if(element.compare(init_str) != 0){
            n++;
        }
    }
    vector<string> return_vector(n, init_str);
    n = 0;
    for(auto element : input){
        if (element.compare(init_str) != 0){
            return_vector[n++] = element;
        }
    }
    return return_vector;
}
int main(){
    cout << "input str" << endl;
    vector <string> input(100, init_str);
    int n = 0;
    cin >> input[n++];
    char c;
    while((c = getchar()) != '\n'){
        cin >> input[n++];
    }
    input = _inputClean(input);
    Solution solution;
    vector<vector<string>> answer = solution.groupAnagrams(input);
    for(auto elements : answer){
        for(auto element : elements){
            cout << element << " ";
        }
        cout << endl;
    }
}