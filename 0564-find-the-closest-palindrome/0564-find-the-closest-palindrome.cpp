class Solution {
public:
    long func(int firstHalf,bool isEven){
        long sum=firstHalf;
        if(isEven==false){
            firstHalf/=10;
            
        }
        while(firstHalf>0){
            int digit=firstHalf%10;
            sum=(sum*10)+digit;
            firstHalf/=10;
        }
        return sum;
    }
    string nearestPalindromic(string n) {
        int l=n.length();
        int mid=l/2;
        int firstHalfL=(l%2==0)?mid:mid+1;
        long firstHalf=stol(n.substr(0,firstHalfL));
        vector<long> results;
        results.push_back(func(firstHalf,l%2==0));
        results.push_back(func(firstHalf+1,l%2==0));
        
        results.push_back(func(firstHalf-1,l%2==0));
        results.push_back((long)pow(10,l-1)-1);
        results.push_back((long)pow(10,l)+1);
        
        long diff=INT_MAX;
        long result=INT_MAX;
        long original=stol(n);
        
        for(long num:results){
            if(num==original) continue;
            if(abs(num-original)<diff){
                diff=abs(num-original);
                result=num;
            }
            else if(abs(num-original)==diff){
                result=min(result,num);
            }
        }
        return to_string(result);
    }
};