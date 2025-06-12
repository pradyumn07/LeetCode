class Solution {
public:
    int findDays(vector<int> &weights,int mid){
        int count=0,d=0;
        for(int i=0;i<weights.size();i++){
            count+=weights[i];
            if(count>mid){
                count=0;
                d++;
                i--;
            }
        }
        return d+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       int low=*max_element(begin(weights),end(weights));
       int total=0;
       for(int i=0;i<weights.size();i++){
        total+=weights[i];
       } 
       int high=total;
       int ans;
       while(low<=high){
        int mid=low+(high-low)/2;
        int day=findDays(weights,mid);
        if(day<=days){
            ans=mid;
            high=mid-1;
        } else{
            low=mid+1;
        }
       }
       return ans;
    }
};