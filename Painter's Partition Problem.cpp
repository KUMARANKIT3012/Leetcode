#include<iostream>
#include<climits>
#include<vector>
using namespace std;

bool ispossible(vector<int>&arr, int n, int m, int maxallawedtime){ //O(n)
    int painters=1, time=0;
    for(int i=0; i<n; i++){
        if(time + arr[i] <= maxallawedtime){
            time += arr[i];
        }
        else{
            painters++;
            time=arr[i];
        }
    }
    return painters<=m;
}

int mainTimeToPaint(vector<int>&arr, int n, int m){//O(log(sum) * n)
    int sum=0, maxval=INT_MIN;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        maxval=max(maxval,arr[i]);
    }

    int st=maxval, end=sum, ans=-1;

    while(st<=end){ //O(log(sum) * n)
        int mid=st+(end-st)/2;

        if(ispossible(arr, n, m, mid)){ // left
            ans=mid;
            end=mid-1;
        }
        else{ // right
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int>arr={40, 30, 10, 20};
    int n=4, m=2;

    cout<<mainTimeToPaint(arr, n, m)<<endl;
    return 0;
}
