class Solution {
public:
    void solve(vector<int> &ans,vector<int> &digits,int current,int count,vector<bool> &vis){
        if(count==0){
            if(current%2==0) ans.push_back(current);
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(vis[i]) continue;
            if(count==3 && digits[i]==0) continue;
            vis[i]=true;
            solve(ans,digits,current*10+digits[i],count-1,vis);
            vis[i]=false;
        }
        
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int count=3;
        int n=digits.size();
        
        vector<int> ans;
        vector<bool> vis(n,false);
        solve(ans,digits,0,count,vis);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};