# include<iostream>
# include<vector>
using namespace std;
string init_str = "abc";
vector<string> _inputClean(vector<string> input) {
	int n = 0;
	for (auto element : input) {
		if (element.compare(init_str) != 0) {
			n++;
		}
	}
	vector<string> return_vector(n, init_str);
	n = 0;
	for (auto element : input) {
		if (element.compare(init_str) != 0) {
			return_vector[n++] = element;
		}
	}
}
int main() {
	cout << "input str" << endl;
	vector <string> input(100, init_str);
	int n = 0;
	string temp;
	cin >> temp;
	input[n++] = temp;
	char c;
	while ((c = getchar()) != '\n') {
		cin >> input[n++];
	}
	input = _inputClean(input);
	for (auto element : input) {
		cout << element << " ";
	}
}