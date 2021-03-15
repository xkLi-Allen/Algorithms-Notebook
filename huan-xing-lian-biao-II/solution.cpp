# include<iostream>
# include<vector>
# include<unordered_set>
using namespace std;
// https://leetcode-cn.com/problems/linked-list-cycle-ii/
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
class Solution{
    public:
        ListNode *detectCycle(ListNode *head){
            unordered_set<ListNode*> hashSet;
            while(head){
                if (hashSet.find(head) != hashSet.end()){
                    return head;
                }
                hashSet.insert(head);
                head = head -> next;
            }
            return nullptr;
        }
        
        // 时间复杂度：O(N)，其中 N 为链表中节点的数目。我们恰好需要访问链表中的每一个节点。

        // 空间复杂度：O(N)，其中 N 为链表中节点的数目。我们需要将链表中的每个节点都保存在哈希表当中。
};
ListNode *creatListNode(ListNode *l1, int x){
    ListNode *head = l1;
    ListNode *temp = new ListNode(x);
    if (head == nullptr){
        head = temp;
        return head;
    }
    while (head -> next != nullptr){
        head = head -> next;
    }
    head -> next = temp;
    return l1;


}

void printList(ListNode *head){
    while(head){
        cout << head -> val << " ";
        head = head -> next;
    }
}
int main(){
    char c;
    vector<int> input;
    int n = 0;
    cout << "input numlist" << endl;
    int temp;
    cin >> temp;
    ListNode *l1 = new ListNode(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }

    cout << "creating..." << endl;
    for (auto element : input){
        l1 = creatListNode(l1, element);
    }
    cout << "create result" << endl;
    printList(l1);

}