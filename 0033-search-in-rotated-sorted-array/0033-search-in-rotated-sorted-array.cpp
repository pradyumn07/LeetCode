class Solution {
public:
    int bs(int l,int r,vector<int> &nums,int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=nums.size()-1;
        int ans=0;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            } else {
                ans=r;
                r=mid;
            }
        }
        int pivot = l; 
        if(target >= nums[pivot] && target <= nums[n - 1]){
            return bs(pivot, n - 1, nums, target);
        } else {
            return bs(0, pivot - 1, nums, target);
        }
        
    }
};