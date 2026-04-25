class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        long long as = 0, ds = 0; 
        int pivot = -1;

        for(int i = 1; i < n-1; i++){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1) return -1;

        for(int i = 0; i <= pivot; i++){
            as += nums[i];
        }

        for(int i = pivot; i < n; i++){
            ds += nums[i];
        }

        if(ds > as) return 1;
        else if(as > ds) return 0;
        else return -1;
    }
};
