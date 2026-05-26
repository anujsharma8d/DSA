class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> v;
        int n=nums.size();
        int count=1;
        int prev;
        for(int x:nums){
            if(x==prev){
                count++;
            }
            else{
                prev=x;
                count=1;
            }
            if(count<=k){
                v.push_back(x);
            }

        }
        return v;
    }
};