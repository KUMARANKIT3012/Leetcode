#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        
        // step1: 
        for(int i = 0; i<k; i++){
            pq.push(arr[i]);
        }
        
        // step2: 
        for(int i = k; i<arr.size(); i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        // ans = pq.top();
        int ans = pq.top();
        return ans;
    }
};
