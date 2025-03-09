
class Solution {
public:
    void insertcopyinbetween(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* nextelement = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = nextelement;
            temp->next = copy;
            temp = nextelement;
        }
    }

    void connectrandompointers(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copynode = temp->next;
            if(temp->random){
                copynode->random = temp->random->next;
            }
            else{
                copynode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }

    Node* getdeepcopylist(Node* head){
        Node* temp = head;
        Node* dummynode = new Node(-1);
        Node* res = dummynode;

        while(temp != NULL){
            // creating a new list
            res->next = temp->next;
            res = res->next;

            //disconnecting and going back to initial stage of ll
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummynode->next;
    }
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        insertcopyinbetween(head);
        connectrandompointers(head);
        return getdeepcopylist(head);
    }
};
