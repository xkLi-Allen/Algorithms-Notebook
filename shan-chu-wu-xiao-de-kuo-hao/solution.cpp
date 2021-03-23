# include<iostream>
# include<vector>
# include<set>
using namespace std;
// https://leetcode-cn.com/problems/remove-invalid-parentheses/
class Solution{
    public:
        void dfs(string& s, string& cur, int idx, int lcnt, int rcnt, int lnum, int rnum, set<string>& ans){
            // s 输入的字符串
            // cur 初始为空的字符串
            // lnum 表示在遍历过程中已经遍历到的左括号数量
            // rnum 表示在遍历过程中已经遍历到的右括号数量
            // idx 表示目前遍历到的编号索引
            // lcnt 需要删除的左括号数量
            // rcnt 需要删除的右括号数量
            if(idx == s.size()){
                if(lcnt == 0 && rcnt == 0) ans.insert(cur);     
                return;
            }
            if(lnum < rnum) return; //  已遍历到的右括号数量大于左括号数量 不合法，剪枝
            if(s[idx] == '(' && lcnt > 0){  //删除左括号
                dfs(s, cur, idx+1, lcnt-1, rcnt, lnum, rnum, ans);
            }else if(s[idx] == ')' && rcnt > 0){  //删除右括号
                dfs(s, cur, idx+1, lcnt, rcnt-1, lnum, rnum, ans);
            }
            //保留该字符
            if(s[idx] == '(') lnum++; //更新计数
            else if(s[idx] == ')') rnum++;
            cur.push_back(s[idx]);
            dfs(s, cur, idx+1, lcnt, rcnt, lnum, rnum, ans);
            cur.pop_back();
        }

        vector<string> removeInvalidParentheses(string s) {
            // 也就是各自最少应该删除的数量
            int lcnt = 0, rcnt = 0; // 统计额外多出来的 左括号 -- lcnt 或者 右括号 -- rcnt
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '(') lcnt++;
                else if(s[i] == ')'){
                    if(lcnt == 0) rcnt++;
                    else lcnt--;
                }
            }
            if(lcnt == 0 && rcnt == 0) return {s};  // 如果没有多出来的括号，无需进行删除操作，直接返回

            vector<string> ans;
            set<string> set;
            string str;
            dfs(s, str, 0, lcnt, rcnt, 0, 0, set);
            // string& s, string& cur, int idx, int lcnt, int rcnt, int lnum, int rnum, set<string>& ans
            for(auto itr = set.begin(); itr != set.end(); itr++) 
                ans.push_back(*itr);
            return ans;
        }

};

int main(){
    cout << "input string" << endl;
    string input;
    cin >> input;
    vector<string> answer;
    Solution solution;
    answer = solution.removeInvalidParentheses(input);
    cout << "answer: " << endl;
    for (vector<string> :: iterator cur = answer.begin(); cur != answer.end(); cur++){
        cout << (*cur) << endl;
    }

}