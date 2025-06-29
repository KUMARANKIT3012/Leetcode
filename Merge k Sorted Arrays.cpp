class node {
public:
    int data;
    int i; // array index
    int j; // element index within that array

    node(int val, int row, int col) {
        data = val;
        i = row;
        j = col;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data; // min-heap
    }
};

class Solution {
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<node*, vector<node*>, compare> minHeap;
        vector<int> result;

        // Step 1: saare array ka pehla element push karde 
        for (int i = 0; i < K; i++) {
            if (!arr[i].empty()) {
                node* temp = new node(arr[i][0], i, 0);
                minHeap.push(temp);
            }
        }

        // Step 2: Extract min and push next element from same array
        while (!minHeap.empty()) {
            node* topNode = minHeap.top();
            minHeap.pop();

            result.push_back(topNode->data);

            int i = topNode->i;
            int j = topNode->j;

            if (j + 1 < arr[i].size()) {
                node* next = new node(arr[i][j + 1], i, j + 1);
                minHeap.push(next);
            }
        }

        return result;
    }
};
