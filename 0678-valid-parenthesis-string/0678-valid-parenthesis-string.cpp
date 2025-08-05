class Solution {
public:
    int n;
    int dp[101][101];
    bool solve(int ind,string& s,int cnt){
        if(cnt==-1) return false;
        if(ind==n) return cnt==0;
        if(dp[ind][cnt]!=-1) return dp[ind][cnt];
        if(s[ind]=='(') return solve(ind+1,s,cnt+1);
        if(s[ind]==')') return solve(ind+1,s,cnt-1);
        return dp[ind][cnt]=solve(ind+1,s,cnt)||solve(ind+1,s,cnt+1) || solve(ind+1,s,cnt-1);
    }
    bool checkValidString(string s) {
        n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,s,0);

    }
};