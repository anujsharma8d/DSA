class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int s = 1e5+1;
        vector<int> diff(s);
        for(int i=0;i<n;i++){
            int d = (abs(nums1[i]-nums2[i]));
            diff[d]++;
        }
        int k=k1+k2;
        for(int i=diff.size()-1;i>0 && k>0;i--){
                int countop = min(diff[i],k);
                diff[i]=diff[i]-countop;
                diff[i-1]+=countop;
                k-=countop;
            
        }
        long long sum = 0;
        for(long long i=0;i<diff.size();i++){
            sum+=diff[i]*i*i;
        }
        return sum;
    }
};