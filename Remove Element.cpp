class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        for(int j = 0; j<n; j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};


/*
🔹 Remove Element – Key Notes
Problem idea
→ Remove all occurrences of a value in-place and return new length
Two-pointer pattern
→ i = position to place valid elements
→ j = iterate through array

Core condition

if(nums[j] != val)

→ Only keep elements not equal to val

Overwrite technique
→ Place valid elements at front:

nums[i] = nums[j];
i++;
No extra space
→ In-place operation → O(1) space
Loop traversal
→ j runs from 0 → n-1
Final answer
→ i gives count of remaining elements
→ Return i (not i+1 ❗)
Order is preserved
→ This approach keeps relative order of elements
*/
