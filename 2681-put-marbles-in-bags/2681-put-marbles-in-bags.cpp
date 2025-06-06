class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        long long ans=0;
        vector<int> w(n-1,0);
        for(int i=0;i<n-1;i++){
            w[i]+=weights[i]+weights[i+1];
        }
        sort(begin(w),end(w));
        for(int i=0;i<k-1;i++){
            ans+=w[n-2-i]-w[i];
        }
        return ans;
    }
};