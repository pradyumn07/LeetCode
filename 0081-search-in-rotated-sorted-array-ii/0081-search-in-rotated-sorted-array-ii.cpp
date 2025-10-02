class Solution {
public:
    int n;
    int pivot(vector<int> &nums){
        int l=0,r=n-1;
        while(l<r){
            while(l<r && nums[l]==nums[l+1]) l++;
            while(l<r && nums[r]==nums[r-1]) r--;
            int mid=l+(r-l)/2;
            if(nums[mid]<nums[r]){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return r;
    }
    int bs(vector<int>& nums, int target,int l,int r){
        
        
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        n=nums.size();
        int l=0,r=n-1;
        int p=pivot(nums);
        if(bs(nums,target,0,p-1)!=false) return bs(nums,target,0,p-1);
        if(bs(nums,target,p,n-1)!=false) return bs(nums,target,p,n-1);
        return false;
    }
};