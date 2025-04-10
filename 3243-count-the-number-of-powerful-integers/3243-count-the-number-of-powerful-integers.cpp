class Solution {
public:
    long long solve(string &str,string &inputSuffix,int limit){
        if(str.length()<inputSuffix.length()) return 0;
        long long count=0;
        string trail=str.substr(str.length()-inputSuffix.length());
        int rem=str.length()-inputSuffix.length();
        for(int i=0;i<rem;i++){
            int digit=str[i]-'0';
            if(digit<=limit) count+=digit*pow(limit+1,rem-i-1);
            else {
                count+=pow(limit+1,rem-i);
                return count;
            }

        }
        if(trail>=inputSuffix) count+=1;
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string  sstr=to_string(start-1);
        string fstr=to_string(finish);
        return solve(fstr,s,limit)-solve(sstr,s,limit);
    }
};