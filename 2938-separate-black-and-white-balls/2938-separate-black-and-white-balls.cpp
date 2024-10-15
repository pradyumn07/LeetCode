class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.length();
        long long shift=0;
        int black=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='0') shift+=black;
            else black++;
        }
        return shift;
    }
};