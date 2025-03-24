class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        int start=0,end=0;
        int ans=0;
        sort(meetings.begin(), meetings.end());
        for(int i=0;i<n;i++){
            if(meetings[i][0]>end){
                ans+=meetings[i][0]-end-1;

            }
            end=max(end,meetings[i][1]);
            
        }
        if(days>end) ans+=days-end;
        return ans;
    }
};