class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        
        int base = 0;

        map<pair<int,int>,int> mpp;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                base++;
            }
            else{
                int x = nums[i-1];
                int y = nums[i];
                if(x>y){
                    swap(x,y);
                }
                mpp[{x,y}]++;
            }

        }
        int best = 0;
        for(auto &[p,cnt]:mpp){
            best = max(best,cnt);
        }
        return base+best;

    }
};