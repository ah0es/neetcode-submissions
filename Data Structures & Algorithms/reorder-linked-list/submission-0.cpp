class Solution {
public:
    ListNode* headPtr = NULL;
    bool done = false;

    void traversalFunc(ListNode* lastNode){
        if(lastNode == NULL) return;
        traversalFunc(lastNode->next);
        if(headPtr == lastNode){
            headPtr->next = NULL;
            done = true;
            return;
        }
        if(headPtr->next == lastNode){
           // currently the headPtr = 4 
           // and his next is 6
           headPtr = headPtr->next;
           headPtr->next = NULL;
           done = true;
           return;
        }
        
        if(!done){
            ListNode* temp = headPtr->next;//1
            headPtr->next = lastNode; // 0->6
            headPtr = headPtr->next;// headPtr currently at 6
            headPtr->next = temp;// headPtr his next will be 1 so now 0->6->1
            headPtr = headPtr->next;// now headPtr pointing on 1
        }
    }

    void reorderList(ListNode* head) {
           
        headPtr = head;
        traversalFunc(head);

    }
};
