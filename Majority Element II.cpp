class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq1 = 0;
        int freq2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(int i = 0; i<n; i++){
            if(freq1 == 0 && nums[i] != el2){
                freq1 = 1;
                el1 = nums[i];
            }
            else if(freq2 == 0 && nums[i] != el1){
                freq2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i]) freq1++;
            else if(el2 == nums[i]) freq2++;
            else{
                freq1--;
                freq2--;
            }
        }

        vector<int> ans;
        freq1 = 0;
        freq2 = 0;

        for(int i = 0; i<n; i++){
            if(el1 == nums[i]) freq1++;
            else if(el2 == nums[i]) freq2++;
        }

        int mini = (int)(n/3)+1;

        if(freq1 >= mini){
            ans.push_back(el1);
        }
        if(freq2 >= mini){
            ans.push_back(el2);
        }
        return ans;
    }
};
