# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/minimum-path-sum/
int init_num = -100000;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();       // 获取行、列的值
        auto dp = vector < vector <int> > (rows, vector <int> (columns));   // dp(i,j) 表示从左上角到 (i,j) 的路径长度
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {    // 第一行方向的动态转移方程
            dp[i][0] = dp[i - 1][0] + grid[i][0];   
        }
        for (int j = 1; j < columns; j++) { // 第一列方向的动态转移方程
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < rows; i++) {    // 除去第一行和第一列的动态转移方程
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }
    // 时间复杂度：O(mn)，其中 m 和 n 分别是网格的行数和列数。需要对整个网格遍历一次，计算 dp 的每个元素的值。

    // 空间复杂度：O(mn)，其中 m 和 n 分别是网格的行数和列数。创建一个二维数组 dp，和网格大小相同。
    // 空间复杂度可以优化，例如每次只存储上一行的 \textit{dp}dp 值，则可以将空间复杂度优化到 O(n)O(n)。
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
    // for (auto elements : matrix){
    //     for (auto element : elements){
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }
    Solution solution;
    int answer = solution.minPathSum(matrix);
    cout << "answer:" << answer << endl;


    
}