class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+2;
            int sum=nums[i]+nums[j];
            int mid=nums[i+1];
            if(sum==(mid/2.0)) count++;
        }
        
        return count;
    }
};