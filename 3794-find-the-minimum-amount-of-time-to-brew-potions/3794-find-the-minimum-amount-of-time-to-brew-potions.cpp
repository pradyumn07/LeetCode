class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long> ans(n,0);
        for(int j=0;j<m;j++){
            long long end=0;
            for(int i=0;i<n;i++){
                long long start=max(end,ans[i]);
                ans[i]=start+skill[i]*mana[j];
                end=start+skill[i]*mana[j];
            }
            for(int i=n-1;i>=1;i--){
                ans[i-1]=ans[i]-skill[i]*mana[j];
            }
        }
        return ans[n-1];
    }
};