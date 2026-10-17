class Solution {
public:
    int getsum(int n){
        int s=0;
        while(n>0){
            s+=n%10;
            n/=10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> afterSort(nums);
        auto lamda = [&](int num1,int num2){
            int sum1= getsum(num1);
            int sum2= getsum(num2);
            if(sum1!=sum2){
                return sum1<sum2;
            }
            return num1<num2;
        };
        sort(afterSort.begin(),afterSort.end(),lamda);

        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }

        int swapCount=0;

        for(int i=0;i<n;i++){
            int expval = afterSort[i];
            int currval = nums[i];

            if(expval==currval) continue;

            int idx = mpp[expval];
            nums[idx] = currval;
            nums[i] = expval;

            mpp[expval] = i;
            mpp[currval] = idx;
            swapCount++;
        }
        return swapCount;
    }
};