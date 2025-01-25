class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> sorted=nums;
        sort(begin(sorted),end(sorted));
        int grp=0;
        unordered_map<int, int> numgrp;
        numgrp[sorted[0]]=grp;
        unordered_map<int, vector<int>> grplist;
        grplist[grp].push_back(sorted[0]);
        for (int i=1;i<n;i++) {
            if (abs(sorted[i]-sorted[i-1])>limit) {
                grp+=1;
            }
            numgrp[sorted[i]]=grp;
            grplist[grp].push_back(sorted[i]);
        }
        vector<int> ans(n);
        for (int i = 0;i<n;i++) { 
            int number=nums[i];
            int group=numgrp[number];
            ans[i]=grplist[group].front();
            grplist[group].erase(grplist[group].begin());
        }
        return ans;


    }
};
