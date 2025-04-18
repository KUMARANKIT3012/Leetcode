class Solution {
  public:
  int countsub(string str){
    //   creation of map:
    unordered_map<char, int> last;
    int n = str.length();
    int dp[n+1];
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        dp[i] = 2* dp[i-1];
        if(last.find(str[i-1]) != last.end()){
            dp[i] = dp[i] - dp[last[str[i-1]]];
        }
        last[str[i-1]] = (i-1);
    }
    return dp[n];
  }
    string betterString(string str1, string str2) {
        // code here
        int a = countsub(str1);
        int b = countsub(str2);
        if(a<b){
            return str2;
        }
        else{
            return str1;
        }
    }
};
