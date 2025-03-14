class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(2*n);
        for(int i=0;i<2*n;i++){
            temp[i]=nums[i%n];
        }
        int totalOnes=0;
        for(int i=0;i<n;i++){
            if(temp[i]==1) totalOnes++;
            
        }
        int i=0;
        int j=0;
        int currOnes=0;
        int maxCount=0;
        while(j<2*n){
            if(temp[j]==1) currOnes++;
            if(j-i+1>totalOnes){
                currOnes-=temp[i];
                i++;
            }
            maxCount=max(maxCount,currOnes);
            j++;
        }
        return totalOnes-maxCount;
    }
};