class Solution {
public:
    long long find(vector<int> &nums,int g){
        if (g < 0) return 0;
        int i=0,j=0;
        long long sum=0,count=0;
        while(j < nums.size()){
            sum+=nums[j];
            while(sum>g){
                sum=sum-nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n=nums.size();
        return find(nums,goal)-find(nums,goal-1);
    }
};