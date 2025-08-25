class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans;
        int curr=0;
        int maxi=0;
        for(int i=0;i<gain.size();i++){
            curr+=gain[i];
            maxi=max(maxi,curr);

        }
        return maxi;
    }
};