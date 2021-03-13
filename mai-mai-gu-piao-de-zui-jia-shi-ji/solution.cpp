# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
int init_num = -10000000;
class Solution{
public: 
int maxProfit(vector<int> &prices){
        int inf = 1e9;
        int minprice = inf;
        int maxprofit = 0;
        for (int price : prices){   // 由于股票的卖出日期一定在买入日期之后，所以需要考虑这一点
            maxprofit = max(maxprofit, price - minprice);       // 只需要先实现 目前最大利润的比较，也就是当前价格 - 当前最低价格 与目前最大利润的比较
            minprice = min(minprice, price);                    // 之后进行遍历，得到新的当前最低价格

        }
        return maxprofit;

    }
    // 时间复杂度：O(n)，只需要遍历一次。
    // 空间复杂度：O(1)，只使用了常数个变量。
};
vector<int> inputclean(vector<int> input){
    int n = 0;
    for(auto element : input){
        if(element != init_num){
            n++;
        }
    }
    vector<int> inputreturn(n, init_num);
    n = 0;
    for(auto element : input){
        if(element != init_num){
            inputreturn[n++] = element;
        }
    }
    return inputreturn;
}
int main(){
    vector<int> input(100, init_num);
    char c;
    int n = 0;
    cout << "input numslist" << endl;
    cin >> input[n++];
    while((c = getchar()) != '\n'){
        cin >> input[n++];
    }
    input = inputclean(input);
    Solution solution;
    int answer = solution.maxProfit(input);
    cout << "answer: " << answer << endl;

}