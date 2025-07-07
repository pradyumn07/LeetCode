class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string t="";
        int i=0;
        while(i<n){
            if (i >= n) break;
            int j=i;
            string rev="";
            while(j<n && s[j]!=' '){
                rev=s[j]+rev;
                j++;
            }
            if (!t.empty()) t+=" ";
            t+=rev;
            i=j+1;
        }
        return t;
    }
};