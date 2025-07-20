class Solution {
public:
    // int dp[1001][1001];
    // int solve(int i,int j,string& text1,string& text2){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i]==text2[j]) return dp[i][j]=1+solve(i-1,j-1,text1,text2);
    //     return dp[i][j]=max(solve(i-1,j,text1,text2),solve(i,j-1,text1,text2));

    // }
    int longestCommonSubsequence(string text1, string text2) {
        // int m=text1.length();
        // int n=text2.length();
        // memset(dp,-1,sizeof(dp));
        // return solve(m-1,n-1,text1,text2);
        int n=text1.length();
        int m=text2.length();
        vector<int> prev(m+1,0),cur(m+1,0);

        for(int j=0;j<=m;j++) prev[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
};