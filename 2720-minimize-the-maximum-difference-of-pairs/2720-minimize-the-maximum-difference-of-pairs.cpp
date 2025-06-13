class Solution {
public:
    bool possible(vector<int> &nums,int p,int mid){
        int count=0;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=mid){
                count++;
                i+=2;
            } else{
                i+=1;
            }
        }
        return count>=p;
        
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums),end(nums));
        int low=0;
        int high=*max_element(begin(nums),end(nums));
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,p,mid)){
                ans=mid;
                high=mid-1;

            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};