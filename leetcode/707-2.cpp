

class MyLinkedList {
   
   public:

        struct ListNode
        {
            int val;
            ListNode *next;
            ListNode(): val(0),next(nullptr){}
        };

        /** Initialize your data structure here. */
        MyLinkedList() {
            m_size = 0;
            head = new ListNode();

        }
        
        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        int get(int index) {
                if(index>m_size-1||index<0)
                    return -1;
                ListNode *temp = head;
                while(index != 0)
                {
                    temp = temp->next;
                    index--;
                }
                return temp->val;
        }
        
        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val) {
            ListNode *temp = new ListNode();
            temp->val = val;
            temp->next = head->next;
            head->next = temp;
            ++m_size;
        }
        
        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val) {
            ListNode *temp_lastnd = new ListNode();
            temp_lastnd->val = val;
            ListNode *temp = head;
            int len = m_size;
            while(len!= 0)
            {
                temp = temp->next;
                --len;
            }
            temp->next = temp_lastnd;
            temp_lastnd->next = nullptr;
            --m_size;
        }
        
        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val) {
            if (index > m_size) return;
		if (index == m_size)
		{
			addAtTail(val);
			return;
		}
		if (index < 0)
		{
			addAtHead(val);
			return;
		}
		ListNode* newNode = new ListNode();
		ListNode* p = head;
		while (index != 0)
		{
			p = p->next;
			--index;
		}
		newNode->next = p->next;
		p->next = newNode;
		newNode->val = val;
		m_size += 1;

        }
        
        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index) {
        if (index > m_size - 1 || index < 0) return;
		ListNode* p = head;
		while (index != 0)
		{
			p = p->next;
			--index;
		}
		ListNode* delNode = p->next;;
		p->next = p->next->next;
		--m_size;
		delete delNode;


    }

    public:
        int m_size;
        ListNode *head;
        ListNode *tail;
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
