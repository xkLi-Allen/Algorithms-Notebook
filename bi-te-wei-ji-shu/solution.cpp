# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/counting-bits/
class Solution {
public:
    // 当计算 i 的「一比特数」时，如果存在 0 ≤ j < i，j 的「一比特数」已知，且 i 和 j 相比，i 的二进制表示只多了一个 1，则可以快速得到 i 的「一比特数」。
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);  // dp  bits[i] 表示 i 的「一比特数」，则上述关系可以表示成：bits[i]=bits[j]+1。
        int highBit = 0;
        // 对于正整数 x，如果可以知道最大的正整数 y，使得 y ≤ x 且 y 是 2 的整数次幂，则 y 的二进制表示中只有最高位是 1，其余都是 0，
        // 此时称 y 为 x 的「最高有效位」。令 z = x−y，显然 0 ≤ z < x，则 bits[x] = bits[z] + 1。
        for (int i = 1; i <= num; i++) {
            if ((i & (i - 1)) == 0) {   // 为了判断一个正整数是不是 2 的整数次幂，可以利用按位与运算的性质。如果正整数 y 是 2 的整数次幂，则 y 的二进制表示中只有最高位是 1，其余都是 0，
                                        // 因此 y&(y−1) = 0。由此可见，正整数 y 是 2 的整数次幂，当且仅当 y&(y−1) = 0。
                highBit = i;
            }
            bits[i] = bits[i - highBit] + 1;    // 如果不是 2 的整数次幂，那么根据二进制也只是相差一个 1
        }
        return bits;
    }
    // 时间复杂度：O(num)。对于每个数，只需要 O(1) 的时间计算「一比特数」。

    // 空间复杂度：O(1)。除了返回的数组以外，空间复杂度为常数。
};
int main(){
    vector<int> answer;
    int input;
    cout << "input value" << endl;
    cin >> input;

}