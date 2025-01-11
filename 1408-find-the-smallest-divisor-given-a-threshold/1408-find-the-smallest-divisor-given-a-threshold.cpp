class Solution {
public:
    int findMax(vector<int> &nums){
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
        }
        return maxi;
    }
    int calculate(vector<int> &nums,int hours){
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=ceil((double)nums[i]/(double)hours);
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=findMax(nums);
        while(low<=high){
            int mid=(low+high)/2;
            if(calculate(nums,mid)<=threshold){
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};