class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int count=0;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()){
            int j=i;
            while(j+1<nums.size() && (nums[j+1]-nums[i])<=k){
                j++;
            }
            count++;
            i=j+1;
        }
        return count;
    }
};