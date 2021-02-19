#include<map>
#include <iostream>
using namespace std;

int main(){
    map<int, int> mapExample;
    mapExample.insert(pair<int,int>(11,3));
    mapExample.insert(pair<int,int>(12,4));
    mapExample.insert(pair<int,int>(13,5));

    auto position = mapExample.find(13);
    if (position != mapExample.end()){
        cout << "find element position is " << position->second << endl;
        cout << "find element position is " << position->first << endl;
    }
}