class Solution {
public:
    int scoreOfString(string s) {
        char ch1,ch2;
        int sum=0;
        for(int i=1;i<s.length();i++){
            sum=sum+abs(int(s[i])-int(s[i-1]));
        }
        return sum;
    }
};