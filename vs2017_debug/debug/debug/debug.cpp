# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/trapping-rain-water/
int init_num = -10;
int trap(vector<int>& height)
{
	if (height[0] == init_num)
		return 0;
	int ans = 0;
	int size = height.size();
	vector<int> left_max(size), right_max(size);
	left_max[0] = height[0];
	for (int i = 1; i < size; i++) {
		left_max[i] = max(height[i], left_max[i - 1]);
	}
	right_max[size - 1] = height[size - 1];
	for (int i = size - 2; i >= 0; i--) {
		right_max[i] = max(height[i], right_max[i + 1]);
	}
	for (int i = 1; i < size - 1; i++) {
		ans += min(left_max[i], right_max[i]) - height[i];
	}
	return ans;
	// 时间复杂度：O(n)。存储最大高度数组，需要两次遍历，每次 O(n) 。最终使用存储的数据更新ans ，O(n)。
	// 空间复杂度：O(n) 额外空间。
}
vector<int> inputclean(vector<int> input) {
	int n = 0;
	for (auto element : input) {
		if (element != init_num) {
			n++;
		}
	}
	vector<int> inputreturn(n, init_num);
	n = 0;
	for (auto element : input) {
		if (element != init_num) {
			inputreturn[n++] = element;
		}
	}
	return inputreturn;
}
int main() {
	vector<int> input(100, init_num);
	char c;
	int n = 0;
	cout << "input numslist" << endl;
	cin >> input[n++];
	while ((c = getchar()) != '\n') {
		cin >> input[n++];
	}
	input = inputclean(input);
	int answer = trap(input);
	cout << "answer: " << answer << endl;

}