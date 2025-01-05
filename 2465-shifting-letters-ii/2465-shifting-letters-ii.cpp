class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> diff(n,0);
        for(auto &i:shifts){
            int l=i[0];
            int r=i[1];
            int dir=i[2];
            int x;
            if(dir==0) x=-1;
            if(dir==1) x=+1;
            diff[l]+=x;
            if(r+1<n) diff[r+1]-=x;
        }
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];

        }
        for(int i=0;i<n;i++){
            int shift=diff[i]%26;
            if(shift<0) shift+=26;
            s[i]=(((s[i]-'a')+shift)%26)+'a';
        }
        return s;

    }
};