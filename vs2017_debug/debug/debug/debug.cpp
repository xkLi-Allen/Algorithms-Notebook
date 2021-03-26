# include<iostream>
# include<vector>
# include<map>
using namespace std;
// https://leetcode-cn.com/problems/top-k-frequent-elements/
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> tempMap;
		for (int i = 0; i < nums.size(); i++) {
			if (tempMap.find(nums[i]) != tempMap.end()) {
				tempMap.insert(pair<int, int>(nums[i], 1));
			}
			else {
				tempMap[nums[i]] = tempMap[nums[i]] + 1;
			}
		}
		for (auto element : tempMap) {
			cout << element.first << ": " << element.second << endl;
		}
		vector<int> answer;
		return answer;
	}
};
int main() {
	vector<int> input;
	char c;
	int n = 0;
	cout << "input numslist" << endl;
	int temp;
	cin >> temp;
	input.push_back(temp);
	while ((c = getchar()) != '\n') {
		cin >> temp;
		input.push_back(temp);
	}
	cout << "input K value" << endl;
	int k;
	cin >> k;
	Solution solution;
	vector<int> answer = solution.topKFrequent(input, k);
}