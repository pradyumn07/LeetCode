class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int i=0,j=0;
        int score=0;
        int maxi=INT_MIN;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>1){
                while(mp[nums[j]]>1){
                    mp[nums[i]]--;
                    score-=nums[i];
                    i++;
                }
            }
            score+=nums[j];
            maxi=max(maxi,score);
            j++;
        }
        return maxi;
    }
};