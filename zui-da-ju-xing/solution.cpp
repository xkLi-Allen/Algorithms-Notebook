# include<iostream>
# include<vector>
# include<stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();      // 输入矩阵的行
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();   // 输入矩阵的列
        vector<vector<int>> left(m, vector<int>(n, 0));     // 记录矩阵中对应行列元素左侧为1元素个数

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;  // 当列数为0的时候左边连续1的数量肯定为0，并且当前元素为1的话那么连续1的数量就说左侧一列同行元素左侧连续1数量+1
                }
            }
        }

        int ret = 0;
        // left[i][j]为矩阵第 i 行第 j 列元素的左边连续1的数量
        for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {  // 此处的入栈规则是从下到上依次增大
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top(); // vector类型变量 up 存储的是当前元素下方距离最近小于当前元素左侧1元素个数的序号
                stk.push(i);        // 此处压入栈的数据是行的标号
            }
            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();  // vector类型变量 up 存储的是当前元素上方距离最近小于当前元素左侧1元素个数的序号
                stk.push(i);        // // 此处压入栈的数据是行的标号
            }

            for (int i = 0; i < m; i++) {   // 固定列号遍历每一行的元素
                int height = down[i] - up[i] - 1;   // 根据当前元素上方的距离最近的小于左侧元素个数的元素标号和下方的距离最近的小于左侧元素个数的标号得到矩形的高
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
    // 时间复杂度：O(mn)，其中 mm 和 nn 分别是矩阵的行数和列数。计算 left 矩阵需要 O(mn) 的时间；对每一列应用柱状图算法需要 O(m) 的时间，一共需要 O(mn) 的时间。

    // 空间复杂度：O(mn)，其中 mm 和 nn 分别是矩阵的行数和列数。我们分配了一个与给定矩阵等大的数组，用于存储每个元素的左边连续 1 的数量。
};
int main() {
	int m, n;
	cout << "input row number" << endl;
	cin >> m;
	cout << "input columns number" << endl;
	cin >> n;
	cout << "input elements" << endl;
	vector<vector<char>> matrix(m,vector<char>(n,'a'));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << matrix[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
    Solution solution;
    int answer = solution.maximalRectangle(matrix);
    cout << "answer: " << answer << endl;
    


}