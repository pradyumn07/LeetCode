class Solution {
public:
    int mod = 1e9 + 7;

    long long find(long long a,long long b)
    {
        if(b==0) return 1;
        long long half=(find(a,b/2))%mod;
        long long result=(half*half)%mod;
        if(b%2==1) result=(result*a)%mod;
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        return (find(5, evenPos) * find(4, oddPos)) % mod;
    }
};