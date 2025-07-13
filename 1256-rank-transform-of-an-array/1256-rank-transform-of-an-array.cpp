class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a;
        a=arr;
        vector<int> ans;
        sort(a.begin(),a.end());
        unordered_map<int,int> mp;
        if(a.size()==0) return ans;
        mp[a[0]]=1;
        int k=2;
        for(int i=1;i<a.size();i++){
            if(a[i-1]==a[i]){
                continue;
            }
            mp[a[i]]=k;
            k++;
        }
        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;

    }
};