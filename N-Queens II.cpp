class Solution{
public:
    int count=0;
    void solve(int r,int n,vector<int>&col,vector<int>&diag,vector<int>&anti){
        if(r==n){count++;return;}
        for(int c=0;c<n;c++){
            if(col[c]||diag[r+c]||anti[r-c+n-1])continue;
            col[c]=diag[r+c]=anti[r-c+n-1]=1;
            solve(r+1,n,col,diag,anti);
            col[c]=diag[r+c]=anti[r-c+n-1]=0;
        }
    }
    int totalNQueens(int n){
        vector<int>col(n),diag(2*n),anti(2*n);
        solve(0,n,col,diag,anti);
        return count;
    }
};
