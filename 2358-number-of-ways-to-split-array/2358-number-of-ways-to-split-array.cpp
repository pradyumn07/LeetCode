class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int &num:nums){
            sum+=num;

        }
        long long left=0;
        long long right=0;
        int split=0;
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right=sum-left;
            if(left>=right) split++;
        }
        return split;
    }
};