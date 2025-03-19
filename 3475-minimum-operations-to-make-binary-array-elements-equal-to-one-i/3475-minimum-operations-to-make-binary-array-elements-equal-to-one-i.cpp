class Solution {
public:
    void flip(vector<int>& nums,int i){
        for(int j=i;j<i+3;j++){
            nums[j]^=1;
        }
    }
    bool check(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        // if(n)
        // int i=0,j=i+3;
        // int count=1;
        // while(j<n){
        //     while(i<n && nums[i]!=0){
        //         i++;

        //     }
        //     if(i>=n) break;
        //     count+=1;
        //     flip(nums,i);
        //     i++;
        //     j=i+3;
        // }
        for(int i=0;i<=n-3;i++){
            if(nums[i]==0){
                flip(nums,i);
                count++;
            }
        }
        for(int num:nums){
            if(num==0) return -1;

        }
        return count;
    }
};