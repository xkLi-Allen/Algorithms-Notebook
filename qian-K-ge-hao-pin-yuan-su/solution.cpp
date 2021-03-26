# include<iostream>
# include<vector>
# include<algorithm>
# include<unordered_map>
using namespace std;
// https://leetcode-cn.com/problems/top-k-frequent-elements/
class Solution{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k){
            unordered_map<int, int> tempMap;
            for (int i = 0; i < nums.size(); i++){
                if (tempMap.find(nums[i]) == tempMap.end()){
                    tempMap.insert(pair<int ,int>(nums[i], 1));
                }
                else{
                    tempMap[nums[i]] = tempMap[nums[i]] + 1;
                }
            }
            vector<pair<int, int>> answer_temp;
            for (auto element : tempMap){
                cout << element.first << ": " << element.second << endl;
                answer_temp.push_back(pair<int, int>(element.first, element.second));
                
            }
            sort(answer_temp.begin(), answer_temp.end(), [=] (pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; });
            cout << "sort: " << endl;
            for (auto element : answer_temp){
                cout << element.first << ": " << element.second << endl;
            }
            vector<int> answer;
            for (int i = 0; i < k; i++){
                // cout << answer_temp[i].first << "--";
                answer.push_back(answer_temp[i].first);
            }
            return answer;
        }
// class Solution {
    /*
    利用小顶堆的思想完成任务
    建立一个小顶堆，然后遍历「出现次数数组」：

    如果堆的元素个数小于 k，就可以直接插入堆中。
    如果堆的元素个数等于 k，则检查堆顶与当前出现次数的大小。如果堆顶更大，说明至少有 k 个数字的出现次数比当前值大，故舍弃当前值；否则，就弹出堆顶，并将当前值插入堆中。
    */
//     public:
//         static bool cmp(pair<int, int>& m, pair<int, int>& n) {  // 根据 value 值进行元素大小的比较
//             return m.second > n.second;
//         }

//         vector<int> topKFrequent(vector<int>& nums, int k) {
//             unordered_map<int, int> occurrences;
//             for (auto& v : nums) {
//                 occurrences[v]++;
//             }

//             // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
//             priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
//             for (auto& [num, count] : occurrences) {
//                 if (q.size() == k) {
//                     if (q.top().second < count) {
//                         q.pop();
//                         q.emplace(num, count);
//                     }
//                 } else {
//                     q.emplace(num, count);
//                 }
//             }
//             vector<int> ret;
//             while (!q.empty()) {
//                 ret.emplace_back(q.top().first);
//                 q.pop();
//             }
//             return ret;
//         }
        // 时间复杂度：O(Nlogk)，其中 N 为数组的长度。我们首先遍历原数组，并使用哈希表记录出现次数，每个元素需要 O(1) 的时间，共需 O(N) 的时间。
        // 随后，我们遍历「出现次数数组」，由于堆的大小至多为 k，因此每次堆操作需要 O(logk) 的时间，共需 O(Nlogk) 的时间。二者之和为 O(Nlogk)。
        // 空间复杂度：O(N)。哈希表的大小为 O(N)，而堆的大小为 O(k)，共计为 O(N)。

// };
};
int main(){
    vector<int> input;
    char c;
    int n = 0;
    cout << "input numslist" << endl;
    int temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    cout << "input K value" << endl;
    int k;
    cin >> k;
    Solution solution;
    vector<int> answer = solution.topKFrequent(input, k);
    cout << "answer: " << endl;
    for (vector<int> :: iterator cur = answer.begin(); cur != answer.end(); cur ++){
        cout << (*cur) << endl;
    }
}