# include<iostream>
# include<unordered_set>
# include<vector>
using namespace std;
int main(){ 
    unordered_set <string> example{"aaa", "ccc"};
    for (auto element : example){
        cout << element << " " << endl;
    }   // 桶排序输出

    // 插入元素 （由于整个数据结构基于哈希构建，无法插入相同元素）
    cout << "--------------- insert element ---------------" << endl;
    example.insert("ddd");
    for (auto element : example){
        cout << element << " " << endl;
    }
    cout << " --- --- ---" << endl;
    vector <string> inserList{"www", "eee"};
    example.insert(inserList.begin(), inserList.end());
    for (auto element : example){
        cout << element << " " << endl;
    }

    // 查找元素 .find() .count() 
    // find可以理解为查找具体元素，返回元素的位置结果
    // count可以理解为查找具体元素是否在数据结构中，返回的结果为0/1
    cout << "--------------- find element ---------------" << endl;
    if((example.find("www")) != example.end()){
        cout << "www in unordered_set exampe" << endl;; 
    }
    else{
        cout << "www not in unordered_set example" << endl;
    }

    cout << " --- --- ---" << endl;
    if((example.count("www")) != 0){
        cout << "www in unordered_set exampe" << endl;; 
    }
    else{
        cout << "www not in unordered_set example" << endl;
    }
    
    // unordered_set 的常用信息
    // .size() .max_size() .empty()
    cout << "--------------- basic information ---------------" << endl;
    cout << "example size: " << example.size() << endl;
    cout << "example max_size: " << example.max_size() << endl;
    cout << "example empty or not: " << example.empty() << endl;


    // 删除 unordered_set 中的元素 .clear() .erase()
    // .clear() 全部清除
    // .erase() 清楚指定元素
    cout << "--------------- delete element ---------------" << endl;
    example.erase("www");
    for (auto element : example){
        cout << element << " " << endl;
    }
    unordered_set<string> delete_example = example;
    delete_example.clear();
    cout << "delete_example is empty: " << delete_example.empty() << endl;

}