# include<iostream>
# include<vector>
# include<algorithm>
# include<stack>
using namespace std;
// https://leetcode-cn.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> temp;
        vector<int> answer(T.size(), 0);
        for (int i = 0; i < T.size(); i++){
            if (temp.empty()){
                temp.push(pair<int, int>(T[i], i));
            }
            while (!temp.empty() && T[i] > temp.top().first){
                answer[temp.top().second] = i - temp.top().second;
                temp.pop();
            }
            temp.push(pair<int, int>(T[i], i));

        }
        return answer;
    }
    // 时间复杂度：O(n)，其中 n 是温度列表的长度。正向遍历温度列表一遍，对于温度列表中的每个下标，最多有一次进栈和出栈的操作。

    // 空间复杂度：O(n)，其中 n 是温度列表的长度。需要维护一个单调栈存储温度列表中的下标。

};
int main(){
    vector<int> input;
    char c;
    cout << "input numslist" << endl;
    int temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    Solution solution;
    vector<int> answer = solution.dailyTemperatures(input);
    for (vector<int> :: iterator cur = answer.begin(); cur != answer.end(); cur++){
        cout << (*cur) << " ";
    }

}