struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (ListNode* head : lists) {
            while (head != nullptr) {
                pq.push(head);
                head = head->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();

            top->next = nullptr;
            ans->next = top;
            ans = ans->next;
        }

        return dummy->next;

    }
};