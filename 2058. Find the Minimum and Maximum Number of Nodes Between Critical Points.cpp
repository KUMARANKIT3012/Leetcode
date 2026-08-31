class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // if(head->next == NULL || head->next->next == NULL){
        //     return {-1,-1};
        // }
        vector<int>ans;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1;
        while(curr->next != NULL){
            if(prev->val < curr->val && curr->val > curr->next->val){
                ans.push_back(pos);
            }
            else if(prev->val > curr->val && curr->val < curr->next->val){
                ans.push_back(pos);
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }
        sort(ans.begin(), ans.end());
        int n = ans.size();

        if(n < 2){
            return{-1,-1};
        }
        int mini = INT_MAX;
        for(int i = 1; i<n; i++){
            mini = min(mini, ans[i] - ans[i-1]);
        }

        int maxi = ans[n-1] - ans[0];
        return {mini, maxi};
    }
};
