class Solution {
public:
    string makeFancyString(string s) {
        
        string ans="";
        ans.push_back(s[0]);
        int count=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==ans.back()){
                count++;
                if(count<3){
                    ans.push_back(s[i]);
                }
            } else {
                ans.push_back(s[i]);
                count=1;
            }
        }
        return ans;
    }
};