class Solution {
  public:
  
    // Heapify function for max-heap
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Step 1: Merge both arrays
        vector<int> merged = a;
        merged.insert(merged.end(), b.begin(), b.end());

        // Step 2: Build Max Heap using heapify (bottom-up)
        int size = merged.size();
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(merged, size, i);
        }

        return merged;
    }
};
