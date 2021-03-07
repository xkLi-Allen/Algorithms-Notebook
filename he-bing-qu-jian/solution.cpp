# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
int init_num = -100000;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());   // 对每一个区间按照左端点升序排序
        vector<vector<int>> merged;     // 创建生成大区间的矩阵
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];   // 当前遍历的左区间和右区间
            if (!merged.size() || merged.back()[1] < L) {   // merged.back() 用于返回区间末尾的元素，使用末尾元素的右区间和当前遍历区间的左区间进行比较
                merged.push_back({L, R});       // 如果当前 merged 为空或者最后一个区间的右区间和当前左区间无交叉，则将当前区间直接加入矩阵中
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);    // 否则进行合并，只需更新右区间为较大值即可，因为本身是排序后的数组，因此左区间不用考虑
            }
        }
        return merged;
    }
    // 时间复杂度：O(nlogn)，其中 n 为区间的数量。除去排序的开销，我们只需要一次线性扫描，所以主要的时间开销是排序的 O(nlogn)。

    // 空间复杂度：O(logn)，其中 n 为区间的数量。这里计算的是存储答案之外，使用的额外空间。O(logn) 即为排序所需要的空间复杂度。
};

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
    matrix = solution.merge(matrix);
    cout << "answer: " << endl;
    for (auto elements : matrix){
        for (auto element : elements){
            cout << element << " ";
        }
        cout << endl;
    }

    
}