
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return head;

        ListNode* ans = NULL;
        ListNode* tail = head;
        ListNode* pTail = NULL;
        int c = 0;

        while (head != NULL) {
            c++;

            if (c == k) {
                ListNode* nextGroup = head->next;
                head->next = NULL;

                ListNode* newHead = reverse(tail);

                if (ans == NULL) {
                    ans = newHead;
                } else {
                    pTail->next = newHead;
                }

                pTail = tail;
                tail = nextGroup;
                head = nextGroup;
                c = 0;
            } else {
                head = head->next;
            }
        }

        if (tail != NULL) {
            if (pTail != NULL) {
                pTail->next = tail;
            } else {
                return tail;
            }
        }

        return ans;
    }
};
