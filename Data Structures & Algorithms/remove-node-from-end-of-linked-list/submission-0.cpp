class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;

        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rHead = reverse(head);

        ListNode* curr = rHead;
        ListNode* prev = NULL;
        // 4 3 2 1
        for (int index = 1; index < n; index++) {
            prev = curr; 
            curr = curr->next; 
        }

        if (prev == NULL) {
            rHead = curr->next;
        } else {
            prev->next = curr->next;
        }

        return reverse(rHead);
    }
};