class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n+1);
        ugly[1]=1;
        int i2=1,i3=1,i5=1;

        for(int i=2;i<=n;i++){
            int i2Ugly = ugly[i2]*2;
            int i3Ugly = ugly[i3]*3;
            int i5Ugly = ugly[i5]*5;

            int minUgly = min({i2Ugly,i3Ugly,i5Ugly});
            
            ugly[i] = minUgly;

            if(minUgly==i2Ugly){
                i2++;
            }
            if(minUgly==i3Ugly){
                i3++;
            }
            if(minUgly==i5Ugly){
                i5++;
            }
        } 
        return ugly[n];
    }
};