class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        ListNode* newHead = NULL;
        ListNode* cur = NULL;

        if(list1->val <= list2->val){
            cur = list1;
            list1 = list1->next;
        }else{
            cur = list2;
            list2 = list2->next;
        }

        newHead = cur; 

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;

            } else {

                cur->next = list2; 
                list2 = list2->next;
            }
           cur = cur->next;
        }

        if(list1 != NULL) cur->next = list1;
        if(list2 != NULL) cur->next = list2;
        
        return newHead;
    }
};