class Solution {
public:
     int firstDigit(long long num) {
        while (num >= 10) {
            num /= 10;
        }
        return num;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
        long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if((firstDigit(sum))== x && (sum%10)==x ){
                    count++;
                }
            }
        }
        return count;
    }
};