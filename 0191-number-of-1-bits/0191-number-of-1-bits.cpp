class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        for(int i=0;i<=31;i++){
            if((1<<i)&n) count++;
        }
        return count;
    }
};