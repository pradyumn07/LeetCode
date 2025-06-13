class Solution {
public:
    bool possible(int mid,vector<int> &bloomDay,int m,int k){
        int count=0,consecutive=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                consecutive++;
                if(consecutive==k){
                    count++;
                    consecutive=0;
                } 
            } else {
                consecutive=0;
            }
        }
        return count>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;
        int low=1;
        int high=*max_element(begin(bloomDay),end(bloomDay));
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,bloomDay,m,k)){
                ans=mid;
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};