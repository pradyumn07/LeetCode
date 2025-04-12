class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        long long ans=0;
        int d=(n+1)/2;
        int start=pow(10,d-1);
        int end=pow(10,d)-1;
        for(int i=start;i<=end;i++){
            string left=to_string(i);
            string full="";
            if(n%2==0){
                string right=left;
                reverse(right.begin(),right.end());
                full=left+right;

            } else {
                string right=left.substr(0,d-1);
                reverse(right.begin(),right.end());
                full=left+right;
            }
            long long no=stoll(full);
            if(no%k!=0) continue;
            sort(full.begin(),full.end());
            st.insert(full);

        }
        vector<long long> factorial(11,1);
        for(int i=1;i<11;i++){
            factorial[i]=factorial[i-1]*i;
        }
        for(const string &s:st){
            vector<int> ct(10,0);
            for(const char &ch:s){
                ct[ch-'0']++;
            }
            int total=s.length();
            int zero=ct[0];
            int non=total-zero;
            long long p=(non*factorial[total-1]);
            for(int i=0;i<10;i++){
                p/=factorial[ct[i]];
            }
            ans+=p;

        }
        return ans;
    }
};