class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt++;
            else{
                ans[i-cnt]=nums[i];
            }
        }
        if(cnt>0){
        while(cnt==0){
            ans.push_back(0);
            cnt--;
        }
        }
        nums=ans;
    }
};