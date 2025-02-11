class Solution {
public:
    int dp[100001];
    const int mod=1e9+7;
    int solve(int l,int h,int z,int o,int i){
        if(i>h) return 0;
        if(dp[i]!=-1) return dp[i];
        int count=(i>=l && i<=h)?1:0;
        count+=solve(l,h,z,o,i+z);
        count+=solve(l,h,z,o,i+o);
        return dp[i]=count%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        
        return solve(low,high,zero,one,0);
    }
};