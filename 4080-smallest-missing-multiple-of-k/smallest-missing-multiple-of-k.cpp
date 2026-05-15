class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=k;
        vector<int> multi;
        for(int i=0;i<n;i++){
            if(nums[i]%k==0){
                multi.push_back(nums[i]);
            }
        }
        if(multi.size() !=0){
                if(multi[0]!=k){
                    ans=k;
                }
                else{
                    for(int i=0;i<multi.size();i++){
                        if(multi[i]==ans){
                            ans+=k;
                        }
                    }

                }
            
        }
        return ans;
    }
};