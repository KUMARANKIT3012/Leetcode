class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int st = 0;
        int end = n-1;
        vector<int>ans;
        while(st < end){
            int sum  = numbers[st] + numbers[end];
            if(sum < target){
                st++;
            }
            else if(sum > target){
                end--;
            }
            else{
                ans.push_back(st+1);
                ans.push_back(end+1);
                return ans;
            }
        }
        return {};
    }
};
