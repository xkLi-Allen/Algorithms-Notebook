# include<iostream>
# include<unordered_set>
using namespace std;
int init_num = -10000000;
// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/submissions/
// Definition for singly-linked list.
struct ListNode{
    int val;    // 当前结点的值
    ListNode *next; // 指向下一个节点的指针
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}   // 初始化当前节点值为x，指针为空
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution{
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            unordered_set<ListNode*> set;
            while(headA){
                set.insert(headA);
                headA = headA -> next;
            }
            while(headB){
                if (set.count(headB) == 1){
                    return headB;
                }
                headB = headB -> next;
            }
            return nullptr;
        }
        // 时间复杂度 : O(m+n)。
        // 空间复杂度 : O(m) 或 O(n)。
};

// 创建两个指针 pA 和 pB，分别初始化为链表 A 和 B 的头结点。然后让它们向后逐结点遍历。
// 当 pA 到达链表的尾部时，将它重定位到链表 B 的头结点 (你没看错，就是链表 B); 类似的，当 pB 到达链表的尾部时，将它重定位到链表 A 的头结点。
// 若在某一时刻 pA 和 pB 相遇，则 pA/pB 为相交结点。
// 想弄清楚为什么这样可行, 可以考虑以下两个链表: A={1,3,5,7,9,11} 和 B={2,4,9,11}，相交于结点 9。 
// 由于 B.length (=4) < A.length (=6)，pB 比 pA 少经过 2 个结点，会先到达尾部。将 pB 重定向到 A 的头结点，pA 重定向到 B 的头结点后，pB 要比 pA 多走 2 个结点。
// 因此，它们会同时到达交点。
// 如果两个链表存在相交，它们末尾的结点必然相同。因此当 pA/pB 到达链表结尾时，记录下链表 A/B 对应的元素。若最后元素不相同，则两个链表不相交。

// 时间复杂度 : O(m+n)。
// 空间复杂度 : O(1)。
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
    ListNode* l2 = inputListNode(); //最后的结果l1指向temp1，这样可以获取temp所接收的全部元素，而temp的指针由于每次都往下移，所以每次都更新
    cout << "create result" << endl;
    PrintListNode(l2);
    cout << endl;
    Solution solution;

    ListNode* answer = solution.getIntersectionNode(l1, l2);
    cout << "answer: " << answer -> val << endl;
}