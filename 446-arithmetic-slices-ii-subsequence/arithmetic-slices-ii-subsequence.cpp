class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();

        int result=0;
        vector<unordered_map<long long,int>> arr(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff = (long long) nums[i]-nums[j];
                auto it = arr[j].find(diff);
                int count_at_j = (it==end(arr[j]))? 0:it->second;

                arr[i][diff]+=count_at_j+1;

                result+=count_at_j;
            }
        }
        return result;
    }
};