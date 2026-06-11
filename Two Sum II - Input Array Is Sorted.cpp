class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int n = numbers.size();
        int st = 0;
        int end = n-1;
        for(int i = 0; i<n; i++){
            int sum = numbers[st] + numbers[end];
            if(sum < target){
               st++; 
            }
            else if(sum > target){
                end--;
            }
            else{
                result.push_back(st+1);
                result.push_back(end+1);
                break;
            }
        }
        return result;
    }
};
