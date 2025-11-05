/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* merge(Node* a, Node* b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        
        Node* result;
        
        if(a->data < b->data){
            result = a;
            result->bottom = merge(a->bottom, b);
        }
        else{
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        
        result->next = NULL; // important!
        return result;
    }

    Node *flatten(Node *root) {
        // Base Case
        if(root == NULL || root->next == NULL)
            return root;
        
        // Recursively flatten the next list
        root->next = flatten(root->next);
        
        // Merge current list with the flattened next lists
        root = merge(root, root->next);
        
        return root;
    }
};
