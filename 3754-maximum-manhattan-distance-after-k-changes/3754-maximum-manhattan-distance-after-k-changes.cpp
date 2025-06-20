class Solution {
public:
    int maxDistance(string s, int k) {
        
        int maxi=0;
        int north=0,south=0,east=0,west=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='N') north++;
            else if(s[i]=='S') south++;
            else if(s[i]=='E') east++;
            else if(s[i]=='W') west++;
            int current=abs(east-west)+abs(north-south);
            int steps=i+1;
            int wasted=steps-current;
            int extra=0;
            if(wasted!=0){
                extra=min(2*k,wasted);
            }
            maxi=max(maxi,current+extra);

        }
        return maxi;

    }
};