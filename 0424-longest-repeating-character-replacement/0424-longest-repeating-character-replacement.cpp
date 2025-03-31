class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxf=0,maxl=0;
        vector<int> mp(26,0);
        while(r<s.length()){
            mp[s[r]-'A']++;
            maxf=max(maxf,mp[s[r]-'A']);
            if(((r-l+1)-maxf)>k){
                mp[s[l]-'A']--;
                l=l+1;
            }
            if(((r-l+1)-maxf)<=k){
                maxl=max(maxl,r-l+1);
                r++;
            }
           
        }
         return maxl;
    }
};