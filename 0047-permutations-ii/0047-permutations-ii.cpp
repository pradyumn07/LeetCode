class Solution {
public:
    
    vector<vector<int>> ans;
    void find(unordered_map<int,int>&mp,vector<int>& temp,int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(auto& [num,count]:mp){
            if(count==0) continue;
            temp.push_back(num);  //DO
            mp[num]--;
            find(mp,temp,n);  //EXPLORE
            temp.pop_back();      //UNDO
            mp[num]++;
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int &num:nums){
            mp[num]++;
            
        }
        
        vector<int> temp;
        find(mp,temp,n);
        return ans;
    }
};