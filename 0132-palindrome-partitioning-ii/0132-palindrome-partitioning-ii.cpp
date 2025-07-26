class Solution {
public:
    // int dp[2001];
    bool isPalindrome(string str){
        int i=0,j=str.length()-1;
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    // int solve(int i,int n,string &s){
    //     if(i==n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int mini=INT_MAX;
    //     string temp="";
    //     for(int j=i;j<n;j++){
    //         temp+=s[j];
    //         if(isPalindrome(temp)){
    //             int cost=1+solve(j+1,n,s);
    //             mini=min(mini,cost);
    //         }
    //     }
    //     return dp[i]=mini;
    // }
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>>isPal(n,vector<bool>(n,false));
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&& (j-i<2||isPal[i+1][j-1]))
                 isPal[i][j]=true;
            }
            }
        for(int i=n-1;i>=0;i--){
            int mini=1e9;
         for(int j=i;j<n;j++){
            if(isPal[i][j]){
              mini=min( mini,dp[j+1]+1);
            }
             }
            dp[i]=mini;
            }
        
       return dp[0]-1;
    }
};