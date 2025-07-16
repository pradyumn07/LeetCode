class Solution {
public:
    void solve(int ind,int k,int n,vector<vector<int>> &ans,vector<int>& ds){
        if(k==0){
            if(n==0) ans.push_back(ds);
            return;
        }
        for(int i=ind;i<=9;i++){
            if(i!=ind && i==i-1) continue;

            ds.push_back(i);
            solve(i+1,k-1,n-i,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,ans,ds);
        return ans;
    }
};