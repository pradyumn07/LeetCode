class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n<k) return false;
        // if(n==k) return true;
        vector<int> v(26,0);
        for(char &ch:s){
            v[ch-'a']++;
        }
        int oddfreq=0;
        for(int i=0;i<26;i++){
            if(v[i]%2!=0) oddfreq++;
        }
        return oddfreq<=k;
    }
};