# include<iostream>
# include<vector>
# include<unordered_map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *creatListNode(ListNode *l1, int x) {
	ListNode *head = l1;
	ListNode *temp = new ListNode(x);
	if (head == nullptr) {
		head = temp;
		return head;
	}
	while (head->next != nullptr) {
		head = head->next;
	}
	head->next = temp;
	return l1;


}

void printList(ListNode *head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
}
int main() {
	char c;
	vector<int> input;
	int n = 0;
	cout << "input numlist" << endl;
	int temp;
	cin >> temp;
	ListNode *l1 = new ListNode(temp);
	while ((c = getchar()) != '\n') {
		cin >> temp;
		input.push_back(temp);
	}

	cout << "creating..." << endl;
	for (auto element : input) {
		l1 = creatListNode(l1, element);
	}
	cout << "create result" << endl;
	printList(l1);

}