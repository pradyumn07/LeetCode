class Solution {
public:
    typedef pair<int,int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        priority_queue<P,vector<P>,greater<P>> occupied;
        priority_queue<int,vector<int>,greater<int>> free;
        
        int targetFriendArrival=times[targetFriend][0];
        int chairNo=0;
        sort(begin(times),end(times));
         for(int i=0;i<n;i++){
             int arrival=times[i][0];
             int dept=times[i][1];
             
             while(!occupied.empty() && occupied.top().first<=arrival){
                 free.push(occupied.top().second);
                 occupied.pop();
             }
             if(free.empty()){
                 occupied.push({dept,chairNo});
                 if(arrival==targetFriendArrival){
                     return chairNo;
                 }
                 chairNo++;
             } else {
                 int least=free.top();
                 free.pop();
                 if(arrival==targetFriendArrival){
                     return least;
                 }
                 occupied.push({dept,least});
             }
         }
        return -1;
    }
};