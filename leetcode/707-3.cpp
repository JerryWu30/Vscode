class MyLinkedList {
    public:
        struct ListNode{

            int val;
            ListNode *next;
            ListNode(int x):val(x),next(nullptr){}
        };
    public:
        ListNode *head;
        int size;
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 ||index >= size)
            return -1;
        ListNode *temp = head;
        while(index!=0)
        {
           temp = temp->next;
           index--;
        }
        return temp->val;
}
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *temp = new ListNode(val);
        temp->next = head;
        head->next = temp;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *tail = new ListNode(val);
        ListNode *temp = head;
        int i = size;
        while(i!=0)
        {
            temp = temp->next;
            --i;
        }
        temp->next = tail;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size)
            return;
        if(index<=0)
            addAtHead(val);
        ListNode *add = new ListNode(val);
        ListNode *temp = head;
        while(index!=0)
        {
            temp = temp->next;
            --index;
        }
        add->next = temp;
        temp = add;
        ++size;


    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0||index>=size)
            return;
        if(index == 0){
            head = head->next;
            size--;
            return;
        }
        int i = 0;
        ListNode *temp = head;
        while (i<index - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        size--;
    }
        

    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */