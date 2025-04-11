class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            int l=s.length();
            int num=i;
            if(l%2!=0){
                continue;
            }
            int h=l/2;
            int s1=0,s2=0;
            for(int j=0;j<h;j++) s1+=s[j]-'0';
            for(int k=h;k<l;k++) s2+=s[k]-'0';
            if(s1==s2) count++;
        }
        return count;
    }
};