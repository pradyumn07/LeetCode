class Solution {
public:
    // int n;
    // int dp[501][501];
    // int solve(string &s,int i,int j){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==s[j]) return solve(s,i+1,j-1);
    //     return dp[i][j]=1+min(solve(s,i+1,j),solve(s,i,j-1));
    // }

    int longestCommonSubsequence(string text1, string text2) {
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
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
    int minInsertions(string s) {
        // int n=s.length();
        // memset(dp,-1,sizeof(dp));
        // return solve(s,0,n-1);
        int len=longestPalindromeSubseq(s);
        return s.length()-len;
    }
};