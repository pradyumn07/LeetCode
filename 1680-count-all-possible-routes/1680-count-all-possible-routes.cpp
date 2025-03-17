class Solution {
public:
    int n;
    int dp[101][201];
    int mod=1e9+7;
    int solve(int curr,int fuel,int finish,vector<int>& locations){
        if(fuel<0) return 0;
        if(dp[curr][fuel]!=-1) return dp[curr][fuel];
        int ans=0;
        if(curr==finish){
            ans+=1;

        }
        for(int j=0;j<n;j++){
            if(curr!=j){
                int rem=fuel-abs(locations[curr]-locations[j]);
                ans=(ans+solve(j,rem,finish,locations))%mod;

            }
        }
        return dp[curr][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n=locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(start,fuel,finish,locations);
    }
};