/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // If list is empty
        if (head == nullptr) return nullptr;

        Node* temp = head;

        // If deleting the head node
        if (x == 1) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            return head;
        }

        // Move to the x-th node
        for (int i = 1; temp != nullptr && i < x; i++) {
            temp = temp->next;
        }

        // If position is invalid
        if (temp == nullptr) return head;

        // Unlink the node
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        delete temp;
        return head;
    }
};
