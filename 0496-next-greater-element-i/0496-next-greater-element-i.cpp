class Solution {
public:
    vector<int> nge(vector<int> &nums2){
        vector<int> arr(nums2.size());
        int n=nums2.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()) arr[i]=-1;
            else{
                arr[i]=st.top();

            }
            st.push(nums2[i]);
        }
        return arr;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a=nge(nums2);
        vector<int> temp(nums1.size());
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    temp[i]=a[j];
                }
            }
        }
        return temp;
    }
};