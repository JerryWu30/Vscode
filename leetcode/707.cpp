class MyLinkedList {
public:
    /** Initialize your data structure here. */
        struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

        int size;
        LinkedNode * head;
    
    MyLinkedList() {  
        head = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if(index < 0||head == nullptr||index>=size)
            return -1;

        LinkedNode *temp = head;

      for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

        return temp->val;
      

    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

        LinkedNode *temp =new LinkedNode(val);
        temp->next = head;
        head = temp;
        size++;

    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {

        LinkedNode *temp = head;
        while(temp->next)
            temp = temp->next;

        temp->next = new LinkedNode(val);
        size++;

    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
          if(index > size)
            return;
        if (index <= 0) 
        {
            addAtHead(val); 
            return;
        }
        LinkedNode* p = head;
        int i = 0;
        while(i < index-1) 
        {
            p = p->next;
            i++;
        }
        LinkedNode* q = new LinkedNode(val);
        // Node* q; 
        // q->next = p->next;
        // p->next = q;
        // q->val = val;
        p->next = q;
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
        LinkedNode *temp = head;
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