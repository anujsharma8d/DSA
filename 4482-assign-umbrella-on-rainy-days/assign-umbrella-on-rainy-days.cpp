class Solution {
public:
    vector<string> assignUmbrella(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        int bob = 0;
        int alice = 0;
        for(int i=0;i<n-1;i++){
            if(alice==bob){
                if(nums[i]==1 && nums[i+1]==1){
                    alice++;
                    ans.push_back("Alice");
                }
                else if(nums[i]==1){
                    bob++;
                    ans.push_back("Bob");
                }
                else if(nums[i]==0){
                    ans.push_back("None");
                }
            }
            else if(bob<alice){
                if(nums[i]==1 && nums[i+1]==1){
                    bob++;
                    ans.push_back("Bob");
                }
                else if(nums[i]==1){
                    bob++;
                    ans.push_back("Bob");
                }
                else if(nums[i]==0){
                    ans.push_back("None");
                }
            }
            else{
                if(nums[i]==1 && nums[i+1]==1){
                    alice++;
                    ans.push_back("Alice");
                }
                else if(nums[i]==1){
                    bob++;
                    ans.push_back("Bob");
                }
                else if(nums[i]==0){
                    ans.push_back("None");
                }
            }

        }
            if(nums[n-1]==1){
                ans.push_back("Bob");
            }
            else{
                ans.push_back("None");
            }
            return ans;
    }
};