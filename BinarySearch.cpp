                                                                  // with recursion:
class Solution {
public:
    // helper function:
    int binsearch(vector<int>& arr, int tar, int st, int end){
        if(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid] == tar)return mid;
            else if(arr[mid] <= tar){
                return binsearch(arr, tar, mid+1, end); // 2nd half searching
            }
            else{
                return binsearch(arr, tar, st, mid-1); // 1st half searching
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int tar) {
        return binsearch(arr, tar, 0, arr.size()-1);
    }
};





                                                               // with looping: 

#include <vector>
#include <iostream>
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
    }    
};
