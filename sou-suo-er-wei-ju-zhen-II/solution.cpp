# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
int init_num = -100000;
// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
// 每行的元素从左到右升序排列。
// 每列的元素从上到下升序排列。
class Solution {
public:
	bool BSearch(vector<vector<int>> matrix, int target, int start, bool vertical) {
		int low = start;
		int high = vertical ? matrix.size() - 1 : matrix[1].size() - 1;
		while (high >= low) {
			int mid = (low + high) / 2;
			if (vertical) {
				if (matrix[start][mid] < target) {
					low = mid + 1;
				}
				else if (matrix[start][mid] > target) {
					high = mid - 1;
				}
				else {
					return true;
				}
			}

			else {
				if (matrix[mid][start] > target) {
					high = mid - 1;
				}
				else if (matrix[mid][start] < target) {
					low = mid + 1;
				}
				else {
					return true;
				}
			}
		}
		return false;
	}
	bool BSearchMatrix(vector<vector<int>> matrix, int target) {
		if (matrix.size() == 0 || matrix[1].size() == 0) {
			return false;
		}

		int shorterDim = min(matrix.size(), matrix[1].size());
		for (int i = 0; i < shorterDim; i++) {
			bool verticalFound = BSearch(matrix, target, i, true);
			bool horizontalFound = BSearch(matrix, target, i, false);
			if (verticalFound || horizontalFound) {
				return true;
			}
		}
		return false;
	}
    // 时间复杂度：O(lg(n!))。
    // 空间复杂度：O(1)，因为我们的二分搜索实现并没有真正地切掉矩阵中的行和列的副本，我们可以避免分配大于常量内存。
};
int main() {
	int m, n;
	cout << "input row numbers" << endl;
	cin >> m;
	cout << "input col numbers" << endl;
	cin >> n;
	vector<vector<int>> matrix(m, vector<int>(n, init_num));
	cout << "input elements" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	// for (auto elements : matrix){
	//     for (auto element : elements){
	//         cout << element << " ";
	//     }
	//     cout << endl;
	// }
	// cout << matrix.size() << " " << matrix[1].size() << endl;
	cout << "input target value" << endl;
	int target;
	cin >> target;
	Solution solution;
	bool answer = solution.BSearchMatrix(matrix, target);
	cout << "answer: " << answer << endl;


}