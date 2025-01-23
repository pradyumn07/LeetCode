class Solution {
public:
    int N,M,K;
    int MOD=1e9+7;
    int dp[52][52][102];
    int solve(int idx,int sc,int maximum){
        if(idx==N){
            if(sc==K) return 1;
            return 0;
        }
        if(dp[idx][sc][maximum]!=-1) return dp[idx][sc][maximum];
        int ans=0;
        for(int i=1;i<=M;i++){
            if(i>maximum){
                ans=(ans+solve(idx+1,sc+1,i))%MOD;
            } else {
                ans=(ans+solve(idx+1,sc,maximum))%MOD;
            }

        }
        return dp[idx][sc][maximum]=ans%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};