class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();
        int n=nums.size();
        vector<int> diff(n,0);
        for(int i=0;i<m;i++){
            int s=queries[i][0];
            int e=queries[i][1];
            int x=1;
            diff[s]+=x;
            if(e+1<n) diff[e+1]-=x;
        }
        vector<int> ans(n,0);
        int cumSum=0;
        for(int i=0;i<n;i++){
            cumSum+=diff[i];
            ans[i]=cumSum;
        }
        for(int i=0;i<n;i++){
            if(ans[i]<nums[i]) return false;
        }
        return true;
    }
};