#include<iostream>
using namespace std;
// Definition for singly-linked list.
// https://blog.csdn.net/zpznba/article/details/83745205
// 1、归并排序（Merge Sort）

// 归并排序的性能不受输入数据的影响，始终都是O(n log n）的时间复杂度。代价是需要额外的内存空间。

// 归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
// 归并排序是一种稳定的排序方法。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。

// 1.1 算法描述

// 把长度为n的输入序列分成两个长度为n/2的子序列；
// 对这两个子序列分别采用归并排序；
// 将两个排序好的子序列合并成一个最终的排序序列。
struct ListNode{
    int val;    // 当前结点的值
    ListNode *next; // 指向下一个节点的指针
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}   // 初始化当前节点值为x，指针为空
    ListNode(int x, ListNode *next) : val(x), next(next){}
};
// 合并两个有序的链表
ListNode* merge(ListNode* head1, ListNode* head2)
{
    ListNode guard_node(0);
    ListNode* mList = &guard_node;
    while (head1 && head2)
    {
        if (head1->val <= head2->val)
        {
            mList->next = head1;
            head1 = head1->next;
        }
        else
        {
            mList->next = head2;
            head2 = head2->next;
        }
        mList = mList->next;
    }
    if (head1)
        mList->next = head1;
    if (head2)
        mList->next = head2;
    return guard_node.next;
}

// 链表实现归并排序
ListNode* sortList(ListNode* head)
{
    if (head == NULL || head->next == NULL) return head;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    slow->next = NULL;
    ListNode* head1 = head;
    head1 = sortList(head);
    head2 = sortList(head2);
    return merge(head1, head2);
}
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
    ListNode* temp1 = new ListNode; //创建新元素，
    ListNode* l1 = temp1;           //最后的结果l1指向temp1，这样可以获取temp所接收的全部元素，而temp的指针由于每次都往下移，所以每次都更新
    cin >> num;
    temp1 ->val = num;
    while ((c = getchar()) != '\n'){   //以空格区分各个结点的值
        if (c != ' '){
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
int main(){
    ListNode* l1 = inputListNode(); //最后的结果l1指向temp1，这样可以获取temp所接收的全部元素，而temp的指针由于每次都往下移，所以每次都更新
    cout << "create result" << endl;
    PrintListNode(l1);
    cout << endl;
}