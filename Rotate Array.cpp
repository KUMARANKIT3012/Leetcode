
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        while(start<end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>&nums, int k){
        int n = nums.size();
        // int start = 0;
        // int end = nums.size()-1;
        k=k % n; 
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums,k,n-1);
        // return nums;
    }
};
