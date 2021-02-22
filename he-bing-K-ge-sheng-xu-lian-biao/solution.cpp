# include<iostream>
# include<vector>
using namespace std;
// https://leetcode-cn.com/problems/merge-k-sorted-lists/
// Definition for singly-linked list.
struct ListNode{
    int val;    // 当前结点的值
    ListNode *next; // 指向下一个节点的指针
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}   // 初始化当前节点值为x，指针为空
    ListNode(int x, ListNode *next) : val(x), next(next){}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; 
                aPtr = aPtr->next;
            } 
            else {
                tail->next = bPtr; 
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for (size_t i = 0; i < lists.size(); ++i) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
    // 时间复杂度：假设每个链表的最长长度是 n。在第一次合并后，ans 的长度为 n；第二次合并后，ans 的长度为 2×n，第 i 次合并后，ans 的长度为i×n。
    // 第 i 次合并的时间代价是 O(n+(i−1)×n)=O(i×n)，那么总的时间代价为 O(∑i=1k (i×n))=O( 2(1+k)⋅k×n)=O(k^2n)，故渐进时间复杂度为 O(k^2 n)
    // 空间复杂度：没有用到与 k 和 n 规模相关的辅助空间，故渐进空间复杂度为 O(1)。
};

void PrintListNode(ListNode* head)
{
    if (head == nullptr)  return;
    cout << head->val << " "; //顺序输出
    PrintListNode(head->next);  
    // cout << head->val << " "; //逆序输出
    
}
ListNode* inputListNode(){
    cout << "input elements in ListNode" << endl; 
    char c;
    int num;
    ListNode* temp1 = new ListNode;     // 创建新元素，
    ListNode* l1 = new ListNode;        // 创建链表头为空的单链表
    l1->next = temp1;
    cin >> num;
    temp1 ->val = num;
    while ((c = getchar()) != '\n'){    // 以空格区分各个结点的值
        if (c != ' '){
            ungetc(c, stdin);           // 把不是空格的字符丢回去
            cin >> num;
            ListNode* newnode = new ListNode;
            newnode->val = num;         // 创建新的结点存放键盘中读入的值
            newnode->next = nullptr;
            temp1->next = newnode;      // 并将其赋值给temp2
            temp1 = newnode;            // 此处也可以写成  temp2=temp2->next,使指针指向下一个，以待接收新元素
        }
    }
    return l1;
}
int main(){
    ListNode* l1 = inputListNode(); 
    cout << "create result" << endl;
    PrintListNode(l1->next);
    cout << endl;
    ListNode* l2 = inputListNode(); 
    cout << "create result" << endl;
    PrintListNode(l2->next);
    cout << endl;
    ListNode* l3 = inputListNode(); 
    cout << "create result" << endl;
    PrintListNode(l3->next);
    cout << endl;
    vector<ListNode*> lists = {l1->next, l2->next, l3->next};
    Solution solution;
    ListNode* answer = solution.mergeKLists(lists);
    cout << "answer : " << endl;
    PrintListNode(answer);
}