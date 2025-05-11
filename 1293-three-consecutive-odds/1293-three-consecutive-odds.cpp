class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            count=arr[i]%2==0?0:count+1;
            if(count==3) return true;

        }
        return false;
    }
};