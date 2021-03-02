# include<iostream>
# include<vector>
# include<stack>
using namespace std;
int init_num = 10;
// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();             // 所定义的柱状图数组大小
        vector<int> left(n), right(n);      // 定义枚举每一个柱子时 -- 左侧最近的小于其高度的柱子编号，右侧最近的小于其高度的柱子编号
        
        stack<int> mono_stack;              // 定义存放判断依据的单调栈
        for (int i = 0; i < n; ++i) {       // 根据本题的条件，单调栈由下至上长度依次增加，并且存储的是栈的编号，可以理解为矩形的宽度
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {    // 此处循环判断当前的 heights[i] 如果小于栈顶的值则当前的栈顶元素需要出栈
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());                     // 出栈操作完成后，根据当前栈顶的元素，给出左侧最近的小于其高度的柱子编号
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);  // 遍历成立的矩形底部宽度完成比较
        }
        return ans;
    }
    // 时间复杂度：O(N)。

    // 空间复杂度：O(N)。
};

vector<int> input_clean(vector<int> input){
    int num = 0;
    for(auto element:input){
        if (element != init_num){
            num++;
        }
    }
    vector <int> clean_input(num,init_num);
    int n = 0;
    for(auto element:input){
        if(element != init_num){
            clean_input[n++] = element;
        }
    }
    return clean_input;
}
int main(){
    vector<int> input(100, init_num);
    int n =0;
    char c;
    cout << "input numlist" << endl;
    cin >> input[n++];
    while((c=getchar()) != '\n'){
        cin >> input[n++];
    }
    input = input_clean(input);
    for(auto element : input){
        cout << element << " ";
    }


}