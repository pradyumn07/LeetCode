class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int n=s.size();
        int m=t.size();
        int l=0,r=0,minlen=INT_MAX,sind=-1,cnt=0;
        for(int i=0;i<m;i++) mp[t[i]]++;
        while(r<n){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sind=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;

        }
        return sind==-1?"":s.substr(sind,minlen);
    }
};