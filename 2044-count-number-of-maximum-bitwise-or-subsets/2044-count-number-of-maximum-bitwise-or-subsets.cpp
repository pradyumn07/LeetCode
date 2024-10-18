class Solution {
public:
    int countSubsets(int i,int currOr,vector<int>& nums,int maxOr){
        
        if(i==nums.size()){
            if(currOr==maxOr) return 1;
            return 0;
        }
        
        //Take
        int takeCount=countSubsets(i+1,currOr | nums[i],nums,maxOr);
        //NotTake
        int notTakeCount=countSubsets(i+1,currOr,nums,maxOr);
        return takeCount+notTakeCount;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(int i=0;i<nums.size();i++){
            maxOr |=nums[i];
        }
        int currOr=0;
        return countSubsets(0,currOr,nums,maxOr);
    }
};