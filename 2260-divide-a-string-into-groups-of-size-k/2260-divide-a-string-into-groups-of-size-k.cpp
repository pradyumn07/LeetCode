class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n=s.length();
        for(int i=0;i<s.length();i+=k){
            string grp="";
            for(int j=0;j<k;j++){
                
                if((i+j)<n) grp+=s[i+j];
                else grp+=fill;
            }
            ans.push_back(grp);
        }
        return ans;
    }
};