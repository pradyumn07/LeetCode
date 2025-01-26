class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=1;

        }
        for(int j=2;j<=n;j++){
            for(int i=0;i<n-j+1;i++){
                int k=i+j-1;
                if(s[i]==s[k]){
                    dp[i][k]=2+dp[i+1][k-1];
                } else {
                    dp[i][k]=max(dp[i][k-1],dp[i+1][k]);
                }

            }
        }
        return dp[0][n-1];
    }
};