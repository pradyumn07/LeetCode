class Solution {
public:
    int minimumLength(string s) {
        
        int n=s.length();
        vector<int> f(26,0);
        for(int i=0;i<n;i++){
            f[s[i]-'a']+=1;
            if(f[s[i]-'a']==3) f[s[i]-'a']-=2;
        }
        int sum=0;
        for(int i=0;i<26;i++){ 
            if(f[i]==0) continue;
            sum+=f[i];
        }
        return sum;
    }
};