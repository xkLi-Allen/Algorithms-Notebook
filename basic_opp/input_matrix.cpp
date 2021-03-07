# include<iostream>
# include<vector>
using namespace std;
int init_num = -100000;
int main(){
    int m, n;
    cout << "input row numbers" << endl;
    cin >> m;
    cout << "input col numbers" << endl;
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n, init_num));
    cout << "input elements" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    for (auto elements : matrix){
        for (auto element : elements){
            cout << element << " ";
        }
        cout << endl;
    }


    
}