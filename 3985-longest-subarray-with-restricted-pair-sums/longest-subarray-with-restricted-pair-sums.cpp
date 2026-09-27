class Solution {
public:
    bool isValid(unordered_map<int,int> &mpp,int target){
        for(auto &[x,count]:mpp){
            int t = target-x;
            if(mpp.find(t)!=mpp.end()){
                if(x!=t){
                    return false;
                }
                    if(count>=2){
                        return false;
                    }
                
            }
        }
        for(auto &[t,count]:mpp){
            int x = t-target;
            if(mpp.find(x)!=mpp.end()){
                if(x!=t){
                    return false;
                }
                if(count>=2){
                    return false;
                }
            }
                

        }
        return true;
    }

    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        unordered_map<int,int> mpp;
        int ans = INT_MIN;
        for(int right=0;right<n;right++){
            int x = nums[right];
            while(!isValid(mpp,x)){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            mpp[x]++;
            ans=max(ans,right-left+1);
        }
        return ans;

    }
};