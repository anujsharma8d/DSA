class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left=0;
        long long sum=0;
        int count=0;
        for(int right=0;right<arr.size();right++){
            sum+=arr[right];
            if(right-left+1==k){
                if(sum/(float)k>=threshold){
                    count++;
                }
                sum-=arr[left];
                left++;
            }
        }
        return count;
    }
};