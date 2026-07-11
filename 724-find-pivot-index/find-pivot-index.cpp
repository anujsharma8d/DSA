class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefsum(n+1,0);
        vector<int> sufsum(n+1,0);
        for(int i=1;i<n+1;i++){
            prefsum[i]=prefsum[i-1]+nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
            sufsum[i]=sufsum[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(prefsum[i]==sufsum[i+1]){
                return i;
            }
        }
        return -1;
    }
};