class Solution {
public:
    int count(vector<int>&nums,int split){
        int count=1;
        int splitsum=0;
        for(int i=0;i<nums.size();i++){
            if(splitsum+nums[i]<=split){
                splitsum+=nums[i];
            }
            else{
                count+=1;
                splitsum=nums[i];
            }

        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int sum=count(nums,mid);
            if(sum>k){
                low=mid+1;

            }
            else{
                high=mid-1;
            }

        }
        return low;
    }
};