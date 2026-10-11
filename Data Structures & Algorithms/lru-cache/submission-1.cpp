struct Node {
    int val;
    int key;
    Node* next;
    Node* prev;

    Node(int key, int value) {
        val = value;
        this->key = key;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    int capacity;
    int curIndex = 0;
    Node* lru = nullptr;
    Node* cur = nullptr;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = cache.find(key);

        if (it == cache.end()) {
            return -1;
        }

        Node* updatedNode = it->second;
        int value = updatedNode->val;

        if (updatedNode == cur) {
            return value;
        }

        Node* prev = updatedNode->prev;
        Node* next = updatedNode->next;

        if (prev != nullptr) {
            prev->next = next;
        } else {
            lru = next;
        }

        if (next != nullptr) {
            next->prev = prev;
        }

        updatedNode->prev = cur;
        updatedNode->next = nullptr;
        cur->next = updatedNode;
        cur = updatedNode;

        return value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            Node* updatedNode = it->second;
            updatedNode->val = value;

            if (updatedNode == cur) {
                return;
            }

            Node* prev = updatedNode->prev;
            Node* next = updatedNode->next;

            if (prev != nullptr) {
                prev->next = next;
            } else {
                lru = next;
            }

            if (next != nullptr) {
                next->prev = prev;
            }

            updatedNode->prev = cur;
            updatedNode->next = nullptr;
            cur->next = updatedNode;
            cur = updatedNode;

            return;
        }

        if (capacity == 0) {
            return;
        }

        if (curIndex == 0) {
            Node* newVal = new Node(key, value);
            cache[key] = newVal;
            cur = newVal;
            lru = newVal;
            curIndex++;
            return;
        }

        if (curIndex < capacity) {
            Node* newVal = new Node(key, value);
            newVal->prev = cur;
            cur->next = newVal;
            cur = newVal;
            cache[key] = newVal;
            curIndex++;
            return;
        }

        if (curIndex >= capacity) {
            Node* temp = lru;
            lru = lru->next;

            if (lru != nullptr) {
                lru->prev = nullptr;
            } else {
                cur = nullptr;
            }

            cache.erase(temp->key);
            delete temp;
            curIndex--;

            Node* newVal = new Node(key, value);

            if (cur == nullptr) {
                lru = newVal;
                cur = newVal;
            } else {
                newVal->prev = cur;
                cur->next = newVal;
                cur = newVal;
            }

            cache[key] = newVal;
            curIndex++;
        }
    }

    // ~LRUCache() {
    //     Node* temp = lru;

    //     while (temp != nullptr) {
    //         Node* next = temp->next;
    //         delete temp;
    //         temp = next;
    //     }
    // }
};
