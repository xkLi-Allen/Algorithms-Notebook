        ListNode* addNode = new ListNode;
        cout << "input node value" << endl;
        cin >> addNode->val;
        addNode->next = temp->next;
        temp->next = addNode;
        cout << "addListNode result" << endl;
        PrintListNode(l1);
        cout << endl;
        return l1;