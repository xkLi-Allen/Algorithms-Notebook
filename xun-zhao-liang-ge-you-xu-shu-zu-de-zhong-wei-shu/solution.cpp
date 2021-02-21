#include<iostream>
#include<vector>
using namespace std;
// https://leetcode-cn.com/problems/median-of-two-sorted-arrays
int init_num = -10;
class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数也就是 k = k -k/2
         * 直到 k 的值减小到1，比较两个有序数组中的未排除下标范围内的第一个数，其中较小的数即为第 k 个数
         */
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 边界情况，出现边界情况的时候则 k 的值一定在另一数组中，基于此继续查找
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
    // 时间复杂度：O(log(m+n))，其中 m 和 n 分别是数组 nums1 和 nums2 的长度。初始时有 k=(m+n)/2 或 k=(m+n)/2+1，每一轮循环可以将查找范围减少一半，因此时间复杂度是 O(log(m+n))。
    // 空间复杂度：O(1)。


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
vector <int> inputNumlist(){
    vector <int> num(20, init_num);
    int n = 0;
    int temp;
    cout << "input numlist" << endl;
    char c;
    cin >> num[n++];
    while((c = getchar()) != '\n'){
        cin >> temp;
        num[n++] = temp;
    }
    int init_n = 0;
    for (auto element : num){
        if (element != init_num){
            init_n ++ ;
        }
    }
    vector <int> num_return(init_n, init_num);
    int n_return = 0;
    for (auto element: num){
        if (element != init_num){
            num_return[n_return++] = element;
        }
    }
    return num_return;
}
int main(){
    vector <int> num1 = inputNumlist();
    vector <int> num2 = inputNumlist();
    Solution solution;
    double answer = solution.findMedianSortedArrays(num1, num2);
    cout << "Median Num : " << answer << endl;
    return 1;
}
