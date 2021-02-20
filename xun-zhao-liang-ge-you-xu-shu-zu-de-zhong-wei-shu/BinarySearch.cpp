# include<iostream>
# include<vector>
using namespace std;

//template <class, T>
int Binary_search( vector<int> num , int value)//采用泛型的方式
{
    int low = 0;            // 获取数组下限
    int high = num.size();  // 获取数组上限
    for (auto element : num){
        cout << element << " ";
    }
    cout << endl;
    int middle;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (num[middle] > value)
        {
            high = middle - 1;
        }
        if (num[middle] < value)
        {
            low = middle + 1;
        }
        if (num[middle] == value)
        {
            return middle;
        }
    }
}
int main()
{
    vector<int> a = { 1, 2, 5, 8, 13, 19, 25, 38, 40, 47, 69, 48, 90 };
    cout << "numlist size : " << a.size() << endl;
    cout << "serial number : " << Binary_search(a, 5)<<endl;
    return 0;
}