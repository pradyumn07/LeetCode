class Solution {
public:
    int dp[501];
    int solve(int i,int n,vector<int>& arr,int k){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=INT_MIN,sum=0,len=0,maxSum=0;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            sum=(len*maxi)+solve(j+1,n,arr,k);
            maxSum=max(maxSum,sum);
        }
        return dp[i]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,arr,k);
    }
};