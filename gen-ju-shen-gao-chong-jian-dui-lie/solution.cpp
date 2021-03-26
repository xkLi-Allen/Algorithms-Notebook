# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/queue-reconstruction-by-height/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        cout << "sort: " << endl;
        for (auto elements : people){
            for (auto element : elements){
                cout << element << " ";
            }
            cout << endl;
        }
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const vector<int>& person: people) {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
    // 时间复杂度：O(n^2)，其中 n 是数组 people 的长度。
    // 需要 O(nlogn) 的时间进行排序，随后需要 O(n^2)的时间遍历每一个人并将他们放入队列中。
    // 由于前者在渐近意义下小于后者，因此总时间复杂度为 O(n^2)。

    // 空间复杂度：O(logn)，即为排序需要使用的栈空间。
        return ans;
    }
};
int init_num = -100000;
int main(){
    int m, n;
    cout << "input row numbers" << endl;
    cin >> m;
    cout << "input col numbers" << endl;
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n, init_num));
    cout << "input elements" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    Solution solution;
    vector<vector<int>> answer = solution.reconstructQueue(matrix);
    cout << "answer: " << endl;
    for (auto elements : answer){
        for (auto element : elements){
            cout << element << " ";
        }
        cout << endl;
    }


    
}