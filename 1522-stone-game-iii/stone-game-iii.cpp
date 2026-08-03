class Solution {
public:
    // int fun(int i,vector<int>& stoneValue, vector<int> &dp){
    //     int n = stoneValue.size();
    //     if(i>=n){
    //         return 0;
    //     }
    //     if(dp[i]!=INT_MIN){
    //         return dp[i];
    //     }
    //     int takeone = stoneValue[i]-fun(i+1,stoneValue,dp);
    //     int taketwo = INT_MIN;
    //     if(i<n-1){
    //         taketwo = stoneValue[i]+stoneValue[i+1]-fun(i+2,stoneValue,dp);
    //     }
    //     int takethree = INT_MIN;
    //     if(i<n-2){
    //         takethree = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-fun(i+3,stoneValue,dp);
    //     }
    //     return dp[i]=max({takeone,taketwo,takethree});
    // }

    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n + 3, 0);
        for(int i=n-1;i>=0;i--){
            int takeone = stoneValue[i]-dp[i+1];
            int taketwo = INT_MIN;
            if(i<n-1){
                taketwo = stoneValue[i]+stoneValue[i+1]-dp[i+2];
            }
            int takethree = INT_MIN;
            if(i<n-2){
                takethree = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3];
            }
            dp[i]=max({takeone,taketwo,takethree});
        }
        int ans = dp[0];
        if(ans==0){
            return "Tie";
        }
        else if(ans>0){
            return "Alice";
        }
        else{
            return "Bob";
        }
    }
};