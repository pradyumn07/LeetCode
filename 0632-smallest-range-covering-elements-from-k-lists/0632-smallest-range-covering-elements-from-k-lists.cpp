class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int maxEl=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({nums[i][0],i,0});
            maxEl=max(maxEl,nums[i][0]);
        }
        vector<int> resultRange={-1000000,1000000};
        while(!pq.empty()){
            vector<int> curr=pq.top();
            pq.pop();
            int minEl=curr[0];
            int listInd=curr[1];
            int ind=curr[2];
            if(maxEl-minEl<resultRange[1]-resultRange[0]){
                resultRange[1]=maxEl;
                resultRange[0]=minEl;
                
            }
            if(ind+1 <nums[listInd].size()){
                int nextEl=nums[listInd][ind+1];
                pq.push({nextEl,listInd,ind+1});
                maxEl=max(maxEl,nextEl);
            }
            else{
                break;
            }
        }
        return resultRange;
    }
};