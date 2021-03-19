# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
    // 时间复杂度：O(mn)，其中 m 和 n 是矩阵的行数和列数。需要遍历原始矩阵中的每个元素计算 dp 的值。

    // 空间复杂度：O(mn)，其中 m 和 n 是矩阵的行数和列数。
    // 创建了一个和原始矩阵大小相同的矩阵 dp。
    // 由于状态转移方程中的 dp(i,j) 由其上方、左方和左上方的三个相邻位置的 dp 值决定，因此可以使用两个一维数组进行状态转移，
    // 空间复杂度优化至 O(n)。
};
char init_char = 'a';
int main(){
    int m, n;
    cout << "input row numbers" << endl;
    cin >> m;
    cout << "input col numbers" << endl;
    cin >> n;
    vector<vector<char>> matrix(m, vector<char>(n, init_char));
    cout << "input elements" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    Solution solution;
    int answer = solution.maximalSquare(matrix);
    cout << "answer :" << answer << endl;


    
}