class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores indices of elements
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements out of the window from the front
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            
            // Remove elements from back that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            // Insert current index
            dq.push_back(i);
            
            // Store result once the first window is filled
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        
        return result;
    }
};
