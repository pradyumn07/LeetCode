class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i+=3){
            vector<int> grp={nums[i],nums[i+1],nums[i+2]};
            if(grp[2]-grp[0]>k){
                return {};
            }
            ans.push_back(grp);
        }
        return ans;
    }
};