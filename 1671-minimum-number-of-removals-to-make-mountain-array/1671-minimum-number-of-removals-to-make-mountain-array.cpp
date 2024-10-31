class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> Lis(n,1);
        vector<int> Lds(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    Lis[i]=max(Lis[i],Lis[j]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    Lds[i]=max(Lds[i],Lds[j]+1);
                }
            }
        }
        int minRemovals=n;
        for(int i=0;i<n;i++){
            if(Lis[i]>1 && Lds[i]>1 ){
            minRemovals=min(minRemovals,n-Lis[i]-Lds[i]+1);
            }
        }
        return minRemovals;
    }
};