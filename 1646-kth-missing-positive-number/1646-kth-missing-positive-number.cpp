class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=num){
                k--;
                if(k==0) return num;
                num++;
                i--;
            } else {
                num++;
            }
        }
        while(k--){
            if(k==0) return num;
            num++;
        }
        return 0;
    }
};