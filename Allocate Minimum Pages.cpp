class Solution {
  public:
    // Helper function to check if we can allocate books with max pages ≤ mid
    bool canAllocate(vector<int> &arr, int k, int mid) {
        int students = 1;   // first student
        int pages = 0;      // pages allocated to current student
        
        for (int i = 0; i < arr.size(); i++) {
            // If single book has more pages than mid → impossible
            if (arr[i] > mid) return false;
            
            if (pages + arr[i] > mid) {
                // Need to assign to next student
                students++;
                pages = arr[i];
                if (students > k) return false; // exceeded student limit
            } 
            else {
                pages += arr[i]; // assign book to current student
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // not enough books
        
        int low = *max_element(arr.begin(), arr.end());  // largest single book
        int high = accumulate(arr.begin(), arr.end(), 0); // sum of all books
        int ans = -1;
        
        // Binary Search on answer
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canAllocate(arr, k, mid)) {
                ans = mid;       // possible answer
                high = mid - 1;  // try smaller max
            } 
            else {
                low = mid + 1;   // increase limit
            }
        }
        return ans;
    }
};
