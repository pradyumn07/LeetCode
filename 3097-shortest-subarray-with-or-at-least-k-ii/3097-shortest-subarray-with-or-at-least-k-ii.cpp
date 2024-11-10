class Solution {
public:
    void add(int number,vector<int>& vec){
        for(int i=0;i<32;i++){
            if((number>>i)&1){
                vec[i]++;
            }
        }
    }
    void remove(int number,vector<int>& vec){
        for(int i=0;i<32;i++){
            if((number>>i)&1){
                vec[i]--;
            }
        }
    }
    int getDecimal(vector<int>& vec){
        int num=0;
        for(int i=0;i<32;i++){
            if(vec[i]>0){
                num |=(1<<i);
            }
        }
        return num;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        int i=0,j=0;
        vector<int> vec(32,0);
        while(j<n){
            add(nums[j],vec);
            while(i<=j && getDecimal(vec)>=k){
                ans=min(ans,j-i+1);
                remove(nums[i],vec);
                i++;
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
        
    }
};