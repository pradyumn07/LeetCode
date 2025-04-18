class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1,0),cur(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=amount;T++){
                int notTake=0+prev[T];
                int take=INT_MAX;
                if(coins[ind]<=T) take=1+cur[T-coins[ind]];
                cur[T]=min(take,notTake);
            }
            prev=cur;
        }
        int ans=prev[amount];
        if(ans==1e9) return -1;
        return ans;
    }
};