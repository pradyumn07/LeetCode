class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int num=1;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]!=num){
        //         k--;
        //         if(k==0) return num;
        //         num++;
        //         i--;
        //     } else {
        //         num++;
        //     }
        // }
        // while(k--){
        //     if(k==0) return num;
        //     num++;
        // }
        // return 0;
        int n=arr.size();
        int l=0,r=n-1;
        int mid=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k){
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        return l+k;
    }
};