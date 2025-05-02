class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.length();
        string ans(n,' ');
        vector<int> left(n);    //right push
        vector<int> right(n);   //left push
        for(int i=0;i<n;i++){
            if(dominoes[i]=='L') left[i]=-1;
            else if(dominoes[i]=='R') left[i]=i;
            else{
                left[i]=i>0?left[i-1]:-1;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='R') right[i]=-1;
            else if(dominoes[i]=='L') right[i]=i;
            else{
                right[i]=i<n-1?right[i+1]:-1;
            }
        }
        for(int i=0;i<n;i++){
            int dright=abs(i-right[i]);
            int dleft=abs(i-left[i]);
            if(right[i]==left[i]) ans[i]='.';
            else if(left[i]==-1) ans[i]='L';
            else if(right[i]==-1) ans[i]='R';
            else if(dright==dleft) ans[i]='.';
            else{
                ans[i]=dleft<dright?'R':'L';
            }
        }
        return ans;
    }
};