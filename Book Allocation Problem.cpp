#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<int>&arr, int n, int m, int maxAllowedpages){ //O(n)
    int students=1, pages=0;

    for(int i=0 ;i<n; i++){
        if(arr[i]>maxAllowedpages){
            return false;
        }
        if(pages+arr[i]<=maxAllowedpages){
            pages+=arr[i];
        }
        else{
            students++;
            pages=arr[i];
        }
    }
    return students>m? false:true;
}

int allocatedbooks(vector<int>&arr, int n, int m){ //O(logN * n)
    if(m>n){
        return -1;
    }

    int sum=0;
    for(int i=0;i<n;i++){ //O(n)
        sum+=arr[i];
    }

    int st=0, end=sum; //range of possible answers
    int ans=-1;
    while(st<=end){ //O(logN * n)
        int mid=st+(end-st)/2;

        if(isvalid(arr, n, m, mid)){ // left
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
    vector<int>arr={2,1,3,4};
    int n=4, m=2;

    cout<<allocatedbooks(arr, n, m)<<endl;
    return 0;
}
