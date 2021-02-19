#include <unordered_map>	// 使用 map 得包含 map 类所在的头文件
#include <iostream>
using namespace std;
// key 和 value 可以是任意你需要的类型，包括自定义类型。
unordered_map<int, int> unordered_mapExample;	// map 的构造函数

int main(){
    unordered_mapExample.insert(pair<int,int>(11,3));
    unordered_mapExample.insert(pair<int,int>(12,4));
    unordered_mapExample.insert(pair<int,int>(13,5));
    unordered_mapExample[14] = 6;
    auto position = unordered_mapExample.find(14);
    if (position != unordered_mapExample.end()){
        cout << "find element position is " << position->second << endl;
        cout << "find element position is " << position->first << endl;
    }
}