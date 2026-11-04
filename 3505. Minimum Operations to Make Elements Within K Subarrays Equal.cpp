#define ll long long
class Solution {
public:
    multiset<int> left, right;
    ll leftSum;
    ll rightSum;

    void insert(int val){
        if(left.size()==0 && right.size()==0){
            leftSum += val;
            left.insert(val);
        }
        else{
            if(left.size()>=right.size()){
                auto it = left.rbegin();
              
                if(*it<=val){
                    rightSum += val;
                    right.insert(val);
                }
                else{
                    int ele = *it;
                    left.erase(prev(left.end()));
                    right.insert(ele);
                    left.insert(val);
                    leftSum -= ele;
                    rightSum += ele;
                    leftSum += val;
                }
            }
            else{
                auto it = right.begin();
                if(val<=*it){
                    left.insert(val);
                    leftSum += val;
                } 
                else{
                    int ele = *it;
                    right.erase(it);
                    left.insert(ele);
                    right.insert(val);
                    rightSum -= ele;
                    leftSum += ele;
                    rightSum += val;
                }
            }
        }
      
    }

    void eras(int val){
        auto it1 = left.find(val);
        auto it2 = right.find(val);
        if(it1!=left.end()){
            if(left.size()>=right.size()){
                leftSum -= *it1;
                left.erase(it1);
                
            }
            else{
                int it3 = *right.begin();
                rightSum -= it3;
                leftSum -= *it1;
                leftSum += it3;
                right.erase(right.begin());
                left.erase(it1);
                left.insert(it3);
                
                
            }
        }
        else{
            if(left.size()<=right.size()){
                rightSum -= *it2;
                right.erase(it2);
            }
            else{
                
                int it3 = *left.rbegin();
                leftSum -= it3;
                rightSum += it3;
                rightSum -= *it2;
                left.erase(prev(left.end()));
                right.insert(it3);
                right.erase(it2);
                
            }
        }
       
    }
    int m;
    ll dp[100005][20];
    ll f(vector<ll>& ans, int x, int k, int i){
        if(k==0) return 0;
        if(m<=i) return LLONG_MAX / 10;
        if(dp[i][k]!=-1) return dp[i][k];
        ll res = LLONG_MAX / 10;

        res = min(res, ans[i] + f(ans, x, k-1, i+x)); 
        res = min(res, f(ans, x, k, i+1)); 

        return dp[i][k] = res;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<ll> ans;
        leftSum = 0;
        rightSum = 0;
        for(int i=0;i<x;i++){
            insert(nums[i]);
        }

        int i = 0;
        int j = x-1;
    
        while(j<n){
            ll a;
            if(left.size()>=right.size()){
                a = *left.rbegin();
                
            }
            else if(left.size()<right.size()){
                a = *right.begin();
                
            }
          
            ll tot = (a*left.size()) - leftSum + rightSum - (a*right.size());
            ans.push_back(tot);
            
            eras(nums[i]);

            i++;
            j++;
            if(j<n){
                insert(nums[j]);
            }

        }

        m = ans.size();
        memset(dp, -1 , sizeof(dp));
        return f(ans, x, k, 0);
        
    }
};
