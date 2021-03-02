# include<iostream>
# include<vector>
using namespace std;
//class Solution {
//public:
//	int maximalRectangle(vector<vector<char>>& matrix) {
//		int m = matrix.size();
//		if (m == 0) {
//			return 0;
//		}
//		int n = matrix[0].size();
//		vector<vector<int>> left(m, vector<int>(n, 0));
//
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (matrix[i][j] == '1') {
//					left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
//				}
//			}
//		}
//
//		int ret = 0;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (matrix[i][j] == '0') {
//					continue;
//				}
//				int width = left[i][j];
//				int area = width;
//				for (int k = i - 1; k >= 0; k--) {
//					width = min(width, left[k][j]);
//					area = max(area, (i - k + 1) * width);
//				}
//				ret = max(ret, area);
//			}
//		}
//		return ret;
//	}
//};
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
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}