class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        int maxlen=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                sum--;
            }
            else{
                sum++;
            }
            if(sum==0){
                maxlen=max(maxlen,i+1);
            }
            if(mpp.count(sum)){
                maxlen=max(maxlen,i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
        return maxlen;
    }
};