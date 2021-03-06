# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/rotate-image/
int init_num = -1000;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        // 这里也是值拷贝
        matrix = matrix_new;
    }
    // 时间复杂度：O(N^2))，其中 N 是 matrix 的边长。
    // 空间复杂度：O(N^2)。我们需要使用一个和 matrix 大小相同的辅助数组。
};
int main(){
    int m,n;
    cout << "input row number" << endl;
    cin >> m;
    cout << "input col number" << endl;
    cin >> n;
    cout << "input matrix elements" << endl;
    vector<vector<int>> matrix(m, vector<int>(n, init_num));
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    Solution solution;
    solution.rotate(matrix);
    cout << "rotate answer :" << endl;
    for (auto elements : matrix){
        for(auto element : elements){
            cout << element << " ";
        }
        cout << endl;
    }
}