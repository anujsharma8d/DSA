class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        if(nums.size()==0){
            return 0;
        }
        for(int i:nums){
            s.insert(i);
        }
        int maxi=1;
        for(int i:s){
            if(s.find(i-1) == s.end()) {
                int count=1;
                int curr=i;
                while(s.find(curr+1) != s.end()){
                    count++;
                    curr++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
        
    }
};