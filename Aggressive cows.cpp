#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

bool ispossible(vector<int>&arr, int N, int C, int minalloweddist){//O(n)
    int cows= 1, laststallpos=arr[0];
    for(int i=1; i<N; i++){
        if(arr[i]-laststallpos>=minalloweddist){
            cows++;
            laststallpos=arr[i];
        }
        if(cows==C){
            return true;
        }
    }
    return false;
}
int getdistance(vector<int>&arr, int N, int C){
    // 1) sort the array
    sort(arr.begin(),arr.end()); // O(n logn)
    // st=1, end=arr(max) - arr(min);

    int st=1, end=N-1-arr[0], ans=-1;

    while(st<=end){// O((log range) * N)
        int mid=st+(end-st)/2;
        if(ispossible(arr, N, C, mid)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int N=5, C=3;
    vector<int>arr = {1,2,8,4,9};

    cout<<getdistance(arr, N, C)<<endl;
    return 0;
}
