class Solution {
public:
    bool isPossible(int mid,vector<int>& nums,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]/mid;
            if(nums[i]%mid!=0) sum+=1;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(mid,nums,threshold)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};