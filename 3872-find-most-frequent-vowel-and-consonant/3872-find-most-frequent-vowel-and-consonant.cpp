class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') mp1[s[i]]++;
            else mp2[s[i]]++;
            
        }
        int maxv=0,maxc=0;
        for(auto m:mp1){
            if(m.second>maxv) maxv=m.second;
        }
        for(auto m:mp2){
            if(m.second>maxc) maxc=m.second;
        }
        return maxv+maxc;
    
    }
};