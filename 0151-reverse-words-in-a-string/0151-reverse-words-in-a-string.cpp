class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n=s.length();
        int i=n-1;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            if(i<0) break;
            int j=i;
            while(j>=0 && s[j]!=' ') j--;
            ans+=s.substr(j+1,i-j)+' ';
            i=j;
        }
        if (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};