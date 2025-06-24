class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int> ind;
        for(int i=0;i<nums.size();i++){
            if(key==nums[i]){
                for(int j=0;j<nums.size();j++){
                    if(abs(i-j)<=k) ind.insert(j);
                }
            }
        }
        vector<int> ans(ind.begin(), ind.end());
        sort(ans.begin(),ans.end());
        return ans;
        // for(int i=0;i<ind.size();i++){
        //     for(int j=0;j<nums.size();j++){
        //         if(abs())
        //     }
        // }
    }
};