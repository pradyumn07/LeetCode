class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        vector<int> answer(n,0);
        int cumValue=0;
        int cumsum=0;
        for(int i=0;i<n;i++){
            answer[i]+=cumsum;
            cumValue+=boxes[i]=='0'?0:1;
            cumsum+=cumValue;
        }
        cumValue=0;
        cumsum=0;
        for(int i=n-1;i>=0;i--){
            answer[i]+=cumsum;
            cumValue+=boxes[i]=='0'?0:1;
            cumsum+=cumValue;
        }
        return answer;
    }
};