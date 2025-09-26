class Solution {
public:
    int maxDepth(string s) {
        
        int maxi=0;
        int count=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='('){
                
                count+=1;
                maxi=max(maxi,count);
            } else if(s[i]==')'){
                
                count-=1;
            }
            i++;
        }
        return maxi;
    }
};