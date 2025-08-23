class Solution {
public:
    int candy(vector<int>& ratings) {
        int i=1;
        int n=ratings.size();
        int sum=1;
        while(i<n){
            if( ratings[i]==ratings[i-1]){
                sum=sum+1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak+=1;
                sum+=peak;
                i++;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]){
                down++;
                sum+=down;
                
                i++;
            }
            if (down > 0 && peak <= down) {
                sum += (down - peak + 1);
            }
        }
        return sum;
    }
};