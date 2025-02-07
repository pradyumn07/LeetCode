class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=abs(brr[i]-arr[i]);

        }
        sort(begin(arr),end(arr));
        sort(begin(brr),end(brr));
        long long after=k;
        for(int i=0;i<n;i++){
            after+=abs(brr[i]-arr[i]);
        }
        return min(sum,after);
    }
};