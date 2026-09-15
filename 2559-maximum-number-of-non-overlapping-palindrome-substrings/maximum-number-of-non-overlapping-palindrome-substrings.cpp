class Solution {
public:
    // bool isPalindrome(string &s1,int low,int high){
    //     while(low<high){
    //         if(s1[low]!=s1[high]){
    //             return false;
    //         }
    //         low++;
    //         high--;
    //     }
    //     return true;
    // }

    int solve(string &s, int k,int i,int j,vector<vector<int>> &dp,vector<vector<bool>> &isPalindrome){
        int n=s.size();
        if(i>=n || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(isPalindrome[i][j]){
            int take = 1+solve(s,k,j+1,j+k,dp,isPalindrome);
            int grow = solve(s,k,i,j+1,dp,isPalindrome);
            int slide = solve(s,k,i+1,j+1,dp,isPalindrome);
            return dp[i][j]=max({take,grow,slide});
        }
        int grow = solve(s,k,i,j+1,dp,isPalindrome);
        int slide = solve(s,k,i+1,j+1,dp,isPalindrome);
        return dp[i][j]=max(grow,slide);

    }


    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1){
            return n;
        }
        vector<vector<bool>> isPalindrome(n,vector<bool>(n,false));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l<=n;i++){
                int j=i+l-1;
                if(i==j){
                    isPalindrome[i][j]=true;
                }
                else if(i+1==j){
                    isPalindrome[i][j]=(s[i]==s[j]);
                }
                else{
                    isPalindrome[i][j] = (s[i]==s[j]) && isPalindrome[i+1][j-1];
                }
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,k,0,k-1,dp,isPalindrome);

    }
};