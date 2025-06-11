class Solution {
public:
    double calculate(vector<int> &dist,int mid){
        double total=0;
        int n=dist.size();
        for(int i=0;i<n-1;i++){
            total+=ceil((double)dist[i]/mid);
        }
        total+=(double)dist[n-1]/mid;
        return total;

    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e7;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            double total=calculate(dist,mid);
            if(total<=hour){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};