class Solution {
public:
    vector<int> nse(vector<int> &arr){       //return the array which stores index of next smaller element
        vector<int> a(arr.size());
        int n=arr.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) a[i]=n;
            else{
                a[i]=st.top();

            }
            st.push(i);
        }
        return a;
    }
    vector<int> psee(vector<int> &arr){
        vector<int> a(arr.size());
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) a[i]=-1;
            else{
                a[i]=st.top();

            }
            st.push(i);
        }
        return a;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // int i=0,j=0;
        // int mod=1e9+7;
        // int n=arr.size();
        // int sum=0;
        // while(i<n){
        //     int mini=arr[i];
        //     j=i;
        //     while(j<n){
        //         mini=min(mini,arr[j]);
        //         sum+=mini;
        //         j++;
        //     }
        //     i++;
        // }
        // return sum%mod;
        int n=arr.size();
        int mod=(int)1e9+7;
        int total=0;
        vector<int> ns=nse(arr);
        vector<int> ps=psee(arr);
        for(int i=0;i<n;i++){
            int left=i-ps[i];
            int right=ns[i]-i;
            total=(total+(right*left*1LL*arr[i])%mod)%mod;
        }
        return total;

    }
};