class Solution {
public:
    int n;
    int dp[366];
    int solve(vector<int>& days,vector<int> &costs,int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int cost_1=costs[0]+solve(days,costs,i+1);
        int j=i;
        int max_day=days[i]+7;
        while(j<n && days[j]<max_day){
            j++;
        }  
        int cost_2=costs[1]+solve(days,costs,j);
        int k=i;
        int max_days=days[i]+30;
        while(k<n &&days[k]<max_days){
            k++;
        }
        int cost_3=costs[2]+solve(days,costs,k);
        return dp[i]=min(cost_1,min(cost_2,cost_3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,0);
    }
};