#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode{
    int val;    // 当前结点的值
    ListNode *next; // 指向下一个节点的指针
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}   // 初始化当前节点值为x，指针为空
    ListNode(int x, ListNode *next) : val(x), next(next){}
};
void PrintListNode(ListNode* head)
{
    if (head == nullptr)  return;
    cout << head->val << " "; //顺序输出
    PrintListNode(head->next);  
    // cout << head->val << " "; //逆序输出
    
}
ListNode* addListNode(ListNode* l1){
    cout << "execute add ListNode..." << endl;
    ListNode* temp = l1;
    int position;
    cout << "input position num" << endl;
    cin >> position;
    if (position <= 0){
        cout << "illegal!" << endl;
        return nullptr;
    }
    for (int i=0 ;i<position-1 ;i++){
        if(nullptr == temp)  break;
        temp = temp->next;
    }
    if (temp == nullptr){
        return nullptr;
    }
    else{
        ListNode* addNode = new ListNode;
        cout << "input node value" << endl;
        cin >> addNode->val;
        addNode->next = temp->next;
        temp->next = addNode;
        cout << "addListNode result" << endl;
        PrintListNode(l1);
        cout << endl;
        return l1;
    }



}
ListNode* deleteListNode(ListNode* l1){
    cout << "execute delete ListNode..." << endl;
    ListNode* temp = l1;
    ListNode* tempdelete = new ListNode;    // 对于链表删除操作需要设置一个单独的节点记录所删除元素的前一个元素
    int position;
    cout << "input position num" << endl;
    cin >> position;
    if (position <= 0){                     // 初步判断位置信息是否非法
        cout << "illegal position num!" << endl;
        return nullptr;
    }
    for (int i=0 ;i<position-1 ;i++){
        if(nullptr == temp){                // 判断位置信息是否非法
            cout << "illegal position num!" <<endl;
            break;
        }
        tempdelete = temp;
        temp = temp->next;
    }
    if (temp == nullptr){
        return nullptr;
    }
    else{
        if (temp == l1){
            l1 = l1->next;
        }
        else{
            ListNode* deleteNode = temp;
            tempdelete->next = temp->next;
            cout << "delete node value : " << deleteNode->val << endl; 
            delete deleteNode;
        }
        cout << "deleteListNode result" << endl;
        PrintListNode(l1);
        cout << endl;
        return l1;
    }
}
ListNode* modifyListNode(ListNode* l1){
    cout << "execute modify ListNode..." << endl;
    ListNode* temp = l1;
    int position;
    cout << "input position num" << endl;
    cin >> position;
    if (position <= 0){
        cout << "illegal!" << endl;
        return nullptr;
    }
    for (int i=0 ;i<position-1 ;i++){
        if(temp == nullptr){
            cout << "illegal position num!" <<endl;
            break;
        }
        temp = temp->next;
    }
    if (temp == nullptr){
        return nullptr;
    }
    else{
        int modifyValue;
        cout << "input modify value" <<endl;
        cin >> modifyValue;
        cout << "original modify node value : " << temp->val << endl;
        temp->val = modifyValue;
        cout << "modifyListNode result" << endl;
        PrintListNode(l1);
        cout << endl;

    }

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
    // l1 = addListNode(l1);
    // l1 = deleteListNode(l1);
    l1 = modifyListNode(l1);
}