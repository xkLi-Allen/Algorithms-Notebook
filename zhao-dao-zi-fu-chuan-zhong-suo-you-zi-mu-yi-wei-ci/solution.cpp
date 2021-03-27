# include<iostream>
# include<string>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26);
        for (auto element: p){
            hash[element - 'a']++;
        }

        vector<int> hash2(26);
        vector<int> ans;
        int left = -1;
        for (int i = 0; i < s.size(); i++){
            while(i - left > p.size()){
                left++;
                hash2[s[left] - 'a']--;
            }
            hash2[s[i] - 'a']++;
            if (hash == hash2){
                ans.push_back(left + 1);
            }
        }
        return ans;
    }
};
int main(){
    string s, p;
    cout << "input s value" << endl;
    cin >> s;
    cout << "input p value" << endl;
    cin >> p;
    Solution solution;
    vector<int> answer = solution.findAnagrams(s, p);
    cout << "answer: " << endl;
    for (vector<int> :: iterator cur = answer.begin(); cur != answer.end(); cur ++){
        cout << (*cur) << " ";
    }

}