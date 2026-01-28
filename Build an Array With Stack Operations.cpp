class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int current = 1; // Current number in the stream
        
        for(int i = 0; i < target.size(); i++){
            // For each number we skip, Push and Pop karde uske baad 
            while(current < target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                current++;
            }
            
            // Now push the number we need
            ans.push_back("Push");
            current++;
        }
        
        return ans;
    }
};

/*
Explanation:

Keep track of current number from the stream (starts at 1)
For each target number:

While current < target[i], we need to skip numbers (Push + Pop)
When current == target[i], just Push it
Increment current after each operation



Example: target = [1, 3], n = 3

current = 1, target[0] = 1 → Push (we need 1)
current = 2, target[1] = 3 → current < 3, so Push, Pop (skip 2)
current = 3, target[1] = 3 → Push (we need 3)
Result: ["Push", "Push", "Pop", "Push"]

*/
