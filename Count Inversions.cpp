class Solution {
  public:
    // Merge function to count inversions while merging
    long long merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        long long inv = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
                inv += (mid - left + 1); // Count inversions
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        // Copy back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return inv;
    }

    // Recursive Merge Sort to count inversions
    long long mergeSort(vector<int>& arr, int low, int high) {
        long long inv = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            inv += mergeSort(arr, low, mid);       // Left part
            inv += mergeSort(arr, mid + 1, high);  // Right part
            inv += merge(arr, low, mid, high);     // Merge step
        }
        return inv;
    }

    // Wrapper function
    int inversionCount(vector<int> &arr) {
        return (int)mergeSort(arr, 0, arr.size() - 1);
    }
};
