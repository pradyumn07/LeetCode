class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto comp=[&](auto &vec1,auto &vec2){
            return vec1[1]>vec2[1];
        };
        sort(begin(boxTypes),end(boxTypes),comp);
        int sum=0;
        for(int i=0;i<boxTypes.size();i++){
            // if(boxTypes[i][0]<=truckSize){
            //     sum+=boxTypes[i][0]*boxTypes[i][1];
            //     trucksize-=boxTypes[i][0];
            // }
            int n=boxTypes[i][0];
            while(n>0 && truckSize>0){
                sum+=boxTypes[i][1];
                truckSize--;
                n--;
            }
        }
        return sum;
    }
};