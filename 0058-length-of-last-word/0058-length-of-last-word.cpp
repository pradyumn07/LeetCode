class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        int c=0;
        while(s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            c++;
            i--;
        }
        return c;
    }
};