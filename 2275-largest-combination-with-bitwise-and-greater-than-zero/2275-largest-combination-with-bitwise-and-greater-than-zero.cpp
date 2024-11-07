class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(32,0);
        int ans=0;
        for(int i=0;i<32;i++){
            for(int &nums:candidates){
                if((nums & (1<<i))!=0){
                    count[i]++;
                }
            }
            ans=max(ans,count[i]);
        }
        return ans;
    }
};