class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n+1);
        int i2=1;
        int i3=1;
        int i5=1;
        ans[1]=1;
        for(int i=2;i<=n;i++){
            int uglyi2=ans[i2]*2;
            int uglyi3=ans[i3]*3;
            int uglyi5=ans[i5]*5;
            int mini=min({uglyi2,uglyi3,uglyi5});
            ans[i]=mini;
            if(mini==uglyi2) i2++;
            if(mini==uglyi3) i3++;
            if(mini==uglyi5) i5++;
        }
        return ans[n];
    }
};