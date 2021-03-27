// # include<iostream>
// # include<vector>
// # include<algorithm>
// using namespace std;
// int init_num = -10000000;
// vector<int> inputclean(vector<int> input){
//     int n = 0;
//     for(auto element : input){
//         if(element != init_num){
//             n++;
//         }
//     }
//     vector<int> inputreturn(n, init_num);
//     n = 0;
//     for(auto element : input){
//         if(element != init_num){
//             inputreturn[n++] = element;
//         }
//     }
//     return inputreturn;
// }
// int main(){
//     vector<int> input(100, init_num);
//     char c;
//     int n = 0;
//     cout << "input numslist" << endl;
//     cin >> input[n++];
//     while((c = getchar()) != '\n'){
//         cin >> input[n++];
//     }
//     input = inputclean(input);
//     for(auto element : input){
//         if(element != init_num){
//             cout << element << " ";
//         }
//     }

// }

# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
int main(){
    vector<int> input;
    char c;
    cout << "input numslist" << endl;
    int temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    for (vector<int> :: iterator cur = input.begin(); cur != input.end(); cur++){
        cout << (*cur) << " " ;
    }
    cout << endl;
    for (int i = 0; i < input.size(); i++){
        cout << input[i] << " ";
    }
    cout << endl;
    for (auto element : input){
        cout << element << " ";
    }

}