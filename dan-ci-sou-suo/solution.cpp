# include<vector>
# include<iostream>
using namespace std;
// https://leetcode-cn.com/problems/word-search/
char init_char = 'a';
class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {      // 深度优先遍历，如果当初试字符在字符矩阵中没有符合的则肯定找不到对应单词
            return false;
        } 
        else if (k == s.length() - 1) { // 当已经遍历到最后一位时，无需再进行搜索，表明已经匹配完成
            return true;
        }
        visited[i][j] = true;   // 维护一个与 board 同等大小的数组来防止元素被重复访问
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};    // 遍历搜索的四个方向
        bool result = false;    // 如果在匹配过程中，在中间中断由 result 控制返回的结果
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;    // 从当前元素开始可能匹配的四个位置
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {     // 如果当前元素可访问
                    bool flag = check(board, visited, newi, newj, s, k + 1);    // 继续执行深度遍历搜索
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
    // 时间复杂度：一个非常宽松的上界为 O(MN⋅3^L)，其中 M,N 为网格的长度与宽度，L 为字符串 word 的长度。
    // 在每次调用函数 check 时，除了第一次可以进入 4 个分支以外，其余时间我们最多会进入 3 个分支（因为每个位置只能使用一次，所以走过来的分支没法走回去）。
    // 由于单词长为 L，故 check(i, j, 0) 的时间复杂度为 O(3^L)，而我们要执行 O(MN) 次检查。
    // 然而，由于剪枝的存在，我们在遇到不匹配或已访问的字符时会提前退出，终止递归流程。因此，实际的时间复杂度会远远小于 Θ(MN⋅3^L)。

    // 空间复杂度：O(MN)。我们额外开辟了 O(MN) 的 visited 数组，同时栈的深度最大为 O(min(L,MN))。
};
int main(){
    int m, n;
    cout << "input row number" << endl;
    cin >> m;
    cout << "input col number" << endl;
    cin >> n;
    vector<vector<char>> board(m, vector<char>(n, init_char));
    cout << "input elements" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    // for (auto elements : board){
    //     for (auto element : elements){
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }
    cout << "input word" << endl;
    string word;
    cin >> word;
    Solution solution;
    bool answer = solution.exist(board, word);
    cout << "answer: " << answer;
}