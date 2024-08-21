class Solution {
public:
    vector<vector<int>> dp;
    
    int help(int l,int r,string& s){
        if(l==r) return 1;
        if(l>r) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        int i=l+1;
        while(i<=r && s[i]==s[l])
            i++;
        if(i==r+1) return 1;
        
        int ans1=1+help(i,r,s);
        
        int ans2=INT_MAX;
        for(int j=i;j<=r;j++){
            if(s[j]==s[l]){
                int sum=help(i,j-1,s)+help(j,r,s);
                ans2=min(ans2,sum);
            }
        }
        return dp[l][r]=min(ans1,ans2);
        
    }
    
    int strangePrinter(string s) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return help(0,n-1,s);
    }
};