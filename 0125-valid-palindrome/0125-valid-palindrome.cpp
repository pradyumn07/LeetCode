class Solution {
public:
    bool isPalindrome(string s) {
        
        int n=s.length()-1;
        string a="";
        for(char c:s){
            if(isalnum(c)){
                a+=tolower(c);
            }
        }
        int i=0,j=a.length()-1;
        while(i<=j){
            if(a[i]==a[j]){
                i++;
                j--;
            } else return false;
        }
        return true;
    }
};