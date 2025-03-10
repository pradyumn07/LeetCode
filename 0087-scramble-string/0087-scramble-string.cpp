class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string s1,string s2){
        if(s1==s2) return true;
        if(s1.length()!=s2.length()) return false;
        string key=s1+"_"+s2;
        if(mp.find(key)!=mp.end()) return mp[key];
        int n=s1.length();
        for(int i=1;i<n;i++){
            bool swapped=solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i));
            if(swapped==true) return mp[key]=true;
            bool not_swapped=solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i));
            if(not_swapped==true) return mp[key]=true;
        }
        return mp[key]=false;
    }
    bool isScramble(string s1, string s2) {
        
        return solve(s1,s2);
    }
};