class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(mpp[arr[i]]==1){
                count++;
                if(count==k) return arr[i];
            }
        }
        return "";
    }
};