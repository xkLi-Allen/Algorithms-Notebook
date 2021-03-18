# include<iostream>
# include<vector>
#include <algorithm>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
	int val;    // 当前结点的值
	ListNode *next; // 指向下一个节点的指针
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}   // 初始化当前节点值为x，指针为空
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* reverseListNode(ListNode *head) {
		ListNode *answer = new ListNode();
		ListNode *readVal = head;
		vector<int> tempStore;
		while (readVal) {
			tempStore.push_back(readVal->val);
			readVal = readVal->next;
		}
		reverse(tempStore.begin(), tempStore.end());
		ListNode *current = answer;
		for (vector<int> ::iterator cur = tempStore.begin(); cur != tempStore.end(); cur++) {
			ListNode *temp = new ListNode(*cur);
			current -> next = temp;
			current = temp;
		}
		return answer->next;
	}
};
void PrintListNode(ListNode* head)
{
	if (head == nullptr)  return;
	cout << head->val << " "; //顺序输出
	PrintListNode(head->next);
	// cout << head->val << " "; //逆序输出

}
ListNode* inputListNode() {
	cout << "input elements in ListNode" << endl;
	char c;
	int num;
	ListNode* temp1 = new ListNode; //创建新元素，
	ListNode* l1 = temp1;           //最后的结果l1指向temp1，这样可以获取temp所接收的全部元素，而temp的指针由于每次都往下移，所以每次都更新
	cin >> num;
	temp1->val = num;
	while ((c = getchar()) != '\n') {   //以空格区分各个结点的值
		if (c != ' ') {
			ungetc(c, stdin);       //把不是空格的字符丢回去
			cin >> num;
			ListNode* newnode = new ListNode;
			newnode->val = num;     //创建新的结点存放键盘中读入的值
			newnode->next = nullptr;
			temp1->next = newnode;  //并将其赋值给temp2
			temp1 = newnode;        //此处也可以写成  temp2=temp2->next,使指针指向下一个，以待接收新元素
		}
	}
	return l1;
}
int main() {
	ListNode* l1 = inputListNode(); //最后的结果l1指向temp1，这样可以获取temp所接收的全部元素，而temp的指针由于每次都往下移，所以每次都更新
	cout << "create result" << endl;
	PrintListNode(l1);
	cout << endl;
	Solution solution;
	ListNode *answer = solution.reverseListNode(l1);
	PrintListNode(answer);
}