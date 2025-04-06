class Solution {
public:
    bool isSorted(vector<int> &ar){
        for(int i=0;i<ar.size()-1;i++){
            if(ar[i]>ar[i+1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(!isSorted(nums)){
            int mini=INT_MAX;
            int idx;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<mini){
                    mini=nums[i]+nums[i+1];
                    idx=i;
                }
            }
            vector<int> arr;
            for(int i=0;i<nums.size();i++){
                if(i==idx){ arr.push_back(nums[i]+nums[i+1]);
                i++;
                }
                else arr.push_back(nums[i]);
            }
            nums=arr;
            count++;

        }
        return count;

    }
};