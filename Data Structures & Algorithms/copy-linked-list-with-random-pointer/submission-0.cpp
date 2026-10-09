class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> clonedList;

        Node* cur = head;

        while (cur != NULL) {

            if (clonedList.find(cur) == clonedList.end()) {
                clonedList[cur] = new Node(cur->val);
            }

            if (cur->next != NULL) {
                if (clonedList.find(cur->next) == clonedList.end()) {
                    clonedList[cur->next] = new Node(cur->next->val);
                }

                clonedList[cur]->next = clonedList[cur->next];
            }

            if (cur->random != NULL) {
                if (clonedList.find(cur->random) == clonedList.end()) {
                    clonedList[cur->random] =
                        new Node(cur->random->val);
                }

                clonedList[cur]->random = clonedList[cur->random];
            }

            cur = cur->next;
        }

        return clonedList[head];
    }
};