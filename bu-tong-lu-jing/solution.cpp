# include<iostream>
# include<vector>
using namespace std;
int init_num = -100000;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));   // f(i,j) 表示从左上角走到 f(i,j) 的路径数量
        for (int i = 0; i < m; ++i) {   // 第一行只有一种走法，因此全部置为1
            f[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {   // 第一列只有一种走法，因此全部置为1
            f[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {   // 某一个点只有可能是从左或从上走过来，如果可以相应加1
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
    // 时间复杂度：O(mn)。
    // 空间复杂度：O(mn)，即为存储所有状态需要的空间。注意到 f(i, j) 仅与第 i 行和第 i-1 行的状态有关，
    // 因此我们可以使用滚动数组代替代码中的二维数组，使空间复杂度降低为 O(n)。
    // 此外，由于我们交换行列的值并不会对答案产生影响，因此我们总可以通过交换 m 和 n 使得 m ≤ n，这样空间复杂度降低至 O(min(m,n))。
};

int main(){
    int m, n;
    cout << "input row numbers" << endl;
    cin >> m;
    cout << "input col numbers" << endl;
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n, init_num));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = 1;
        }
    }
    // for (auto elements : matrix){
    //     for (auto element : elements){
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }
    Solution solution;
    int answer = solution.uniquePaths(m, n);
    cout << "answer: " << answer;


    
}