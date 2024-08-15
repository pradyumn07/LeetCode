class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0;
        int c10=0;
        
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                c5++;
            }
            else if(bills[i]==10){
                c5--;
                c10++;
            }
            else {
                if(c10>0){
                c10--;
                c5--;
            }
            else{
                c5=c5-3;;
            }
            }
            if(c5<0) return false;
        }
        return true;
    }
};