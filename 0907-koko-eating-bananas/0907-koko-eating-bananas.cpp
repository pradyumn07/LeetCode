class Solution {
public:
    int findMax(vector<int> &piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(piles[i],maxi);
        }
        return maxi;
    }
    long long calculate(vector<int> &piles,int hours){
        long long total=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            total+=ceil((double)piles[i]/(double)hours);
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long long total=calculate(piles,mid);
            if(total<=h){
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        return low;
    }
};