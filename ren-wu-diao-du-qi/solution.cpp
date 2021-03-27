# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_map>
# include<numeric>
using namespace std;
// https://leetcode-cn.com/problems/task-scheduler/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }

        // 最多的执行次数
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
            return u.second < v.second;
        })->second;
        // 具有最多执行次数的任务数量
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
            return acc + (u.second == maxExec);
        });

        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
    // 时间复杂度：O(∣task∣+∣Σ∣)，其中 ∣Σ∣ 是数组 task 中出现任务的种类，在本题中任务用大写字母表示，因此 ∣Σ∣ 不会超过 26。

    // 空间复杂度：O(∣Σ∣)。
};
int main(){
    vector<char> input;
    char c;
    cout << "input numslist" << endl;
    char temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }

}