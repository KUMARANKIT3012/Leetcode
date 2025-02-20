                                          // for only positive numbers

#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left = 0, right = 0;
    long long sum = a[0];
    int maxlen = 0;
    int n = a.size();
    while(right<n){
        while(left<=right && sum > k){
            sum -=a [left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen, right - left+1);
        }
        right++;
        if(right<n){
            sum += a[right];
        }
    }
    return maxlen;
    }



                                            // for negative number:
map<long long, int>presumMap;
    long long sum = 0;
    int maxlen = 0;
    for(int i=0; i<a.size(); i++){
            sum+=a[i];
            if(sum == k){
                maxlen = max(maxlen, i+1);
            }
            // bring the reverse maths:
            long long rem = sum - k;
            if(presumMap.find(rem) != presumMap.end()){
                int len = i- presumMap[rem];
                maxlen = max(maxlen, len);
            }
            if(presumMap.find(sum) == presumMap.end())
            {
                presumMap[sum]=i;
            }
        }
    return maxlen;
