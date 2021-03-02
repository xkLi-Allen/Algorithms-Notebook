# include<iostream>
using namespace std;
// https://leetcode-cn.com/problems/edit-distance/

// 我们可以对任意一个单词进行三种操作：
// 插入一个字符；
// 删除一个字符；
// 替换一个字符。

// 对于两个字符串来说，每个字符串一步对应三种操作，一共有六种操作形式
// 但是在这六种形式中存在几种等价的情况
// 1. A删除一个字符和B插入一个字符
// 2. 同理B删除一个字符和A插入一个字符
// 3. A替换一个字符和B替换一个字符

// 基于此我们可以简化六种操作为三种：
// 1. 在A中插入一个字符     编辑距离就基于上一次的编辑情况a     <=a+1
// 2. 在B中插入一个字符     编辑距离就基于上一次的编辑情况b     <=b+1
// 3. 修改A中的一个字符     编辑距离就基于上一次的编辑情况c     <=c+1

// 因此最后的编辑距离应该为 min(a+1, b+1, c+1)
// 继续用上面的方法拆分这个问题，对于这个问题拆分出来的所有子问题，我们也可以继续拆分，直到：

// 字符串 A 为空，如从 转换到 ro，显然编辑距离为字符串 B 的长度，这里是 2；

// 字符串 B 为空，如从 horse 转换到 ，显然编辑距离为字符串 A 的长度，这里是 5。

// 因此，我们就可以使用动态规划来解决这个问题了。我们用 D[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离。




class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        int D[n + 1][m + 1];

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;   // A和B的最后一个字母不同，此时需要经过修改操作，因此编辑距离+1
                D[i][j] = min(left, min(down, left_down));

            }
        }
        return D[n][m];
    }
    // 时间复杂度 ：O(mn)，其中 m 为 word1 的长度，n 为 word2 的长度。

    // 空间复杂度 ：O(mn)，我们需要大小为 O(mn) 的 D 数组来记录状态值。
};
int main(){
    string s1, s2;
    cout << "input str1" << endl;
    cin >> s1;
    cout << "input str2" << endl;
    cin >> s2;
    Solution solution;
    int answer = solution.minDistance(s1, s2);
    cout << "answer: " << answer << endl;

}