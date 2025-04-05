class Solution {
public:
    bool isPalindrome(string s){
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<=s.length();j++){
                for(int k=0;k<t.length();k++){
                    for(int l=k;l<=t.length();l++){
                        if(isPalindrome(s.substr(i,j-i)+t.substr(k,l-k)))
                        maxlen=max(maxlen,j+l-i-k);
                    }
                }
            }
        }
        return maxlen;

    }
};