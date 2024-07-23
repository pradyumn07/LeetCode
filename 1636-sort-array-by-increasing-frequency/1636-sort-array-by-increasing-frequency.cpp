class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]<b[0]) return true;
        if(a[0]==b[0]) return a[1]>b[1];
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<vector<int>> v;
        for(auto i:nums){
            mpp[i]++;
        }
        for(auto i:mpp){
            v.push_back({i.second,i.first}); 
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(auto i:v){
            int x=i[0];
            while(x--){
                ans.push_back(i[1]);
            }
            
        }
        return ans;
    }
};