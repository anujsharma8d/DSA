class Solution {
public:
    int solve(vector<int>& nums, int limit){
        deque<int> maxi;
        deque<int> mini;

        int n = nums.size();
        int left = 0;
        int ans = 0;

        for(int right=0;right<n;right++){
            while(!maxi.empty() && nums[right]>=nums[maxi.back()]){
                maxi.pop_back();
            }
            maxi.push_back(right);

            while(!mini.empty() && nums[right]<=nums[mini.back()]){
                mini.pop_back();
            }
            mini.push_back(right);

            while(nums[maxi.front()]-nums[mini.front()]>limit){
                if(maxi.front()==left){
                    maxi.pop_front();
                }
                if(mini.front()==left){
                    mini.pop_front();
                }
                left++;
            }
            ans=max(ans,right-left+1);
            
        }
        return ans;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        return solve(nums,limit);
    }
};