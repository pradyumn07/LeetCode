class Solution {
public:
    int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n=s.length();
        vector<int> mp(26,0);
        for(char &i:s){
            mp[i-'a']++;
        }
        for(int tr=1;tr<=t;tr++){
            vector<int> temp(26,0);
            for(int i=0;i<26;i++){
                char ch=i+'a';
                int f=mp[i];
                if(ch!='z'){
                    temp[(ch+1)-'a']=(temp[(ch+1)-'a']+f)%mod;
                } else {
                    temp[0]=(temp[0]+f)%mod;
                    temp[1]=(temp[1]+f)%mod;
                }
            }
            mp=move(temp);
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+mp[i])%mod;
        }
        return ans;
    }
};