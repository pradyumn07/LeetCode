class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        int lucky=-1;
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]==arr[i]){
                lucky=max(lucky,arr[i]);
            } 
        }
        return lucky;
    }
};