class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        long double sum1=0;
        long double product1=1;
        vector<long double> sum;
        vector<long double> product;
        int idx=-1;
        for(int i=0;i<=n-1;i++){
            sum.push_back(sum1);
            sum1+=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            product.push_back(product1);
            product1*=nums[i];
        }
        reverse(product.begin(),product.end());
        for(int i=n-1;i>=0;i--){
            if(sum[i]==product[i]){
                idx=i;
            }
        }
        return idx;
    }
};