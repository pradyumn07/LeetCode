class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length();
        int m=t.length();
        string s1="",t1="";
        int k=0,c=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='#') k++;
            else if(k>0){
                k--;
                continue;
            } 
            else if(k==0) s1=s[i]+s1;
        }
        for(int i=m-1;i>=0;i--){
            if(t[i]=='#') c++;
            else if(c>0){
                c--;
                continue;
            }
            else if(c==0) t1=t[i]+t1;
        }
        if(t1==s1) return true;
        return false;
    }
};