class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> oldToCopy;

        Node* cur = head;
        while (cur) {
            oldToCopy[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            Node* copy = oldToCopy[cur];
            copy->next = oldToCopy[cur->next];
            copy->random = oldToCopy[cur->random];
            cur = cur->next;
        }

        return oldToCopy[head];
    }
};
