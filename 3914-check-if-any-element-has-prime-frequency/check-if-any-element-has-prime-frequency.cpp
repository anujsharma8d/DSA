class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<bool> isPrime(100,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i<101;i++){
            if(isPrime[i]){
                for(int j=i*i;j<101;j+=i){
                    isPrime[j]=false;
                }
            }
        } 
        unordered_map<int,int> mpp;
        for(int i:nums){
            mpp[i]++;
        }
        for(auto i:mpp){
            if(isPrime[i.second]){
                return true;
            }
        }
        return false;

    }
};