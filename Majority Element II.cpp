class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq1 = 0;
        int freq2 = 0;
        int ans1 = INT_MIN, ans2 = INT_MIN;
        for(int i = 0; i<n; i++){
            if(freq1 == 0 && nums[i] != ans2){
                freq1 = 1;
                ans1 = nums[i];
            }
            else if(freq2 == 0 && nums[i] != ans1){
                freq2 = 1;
                ans2 = nums[i];
            }
            else if(ans1 == nums[i]) freq1++;
            else if(ans2 == nums[i]) freq2++;
            else{
                freq1--;
                freq2--;
            }
        }
        vector<int> ls;
        freq1 = 0 , freq2 = 0;
        for(int i = 0; i<n; i++){
            if(ans1 == nums[i]) freq1++;
            if(ans2 == nums[i]) freq2++;
        }
        int mini = (int)(n/3)+1;
        if(freq1 >= mini) ls.push_back(ans1);
        if(freq2 >= mini) ls.push_back(ans2);
        sort(ls.begin(), ls.end());
        return ls;
    }
};
