class Solution {
public:
    // bool isPalindrome(string &s,int i,int j){
    //     while(i<j){
    //         if(s[i]!=s[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        vector<vector<int>> isPalindrome(n,vector<int>(n,0));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=l+i-1;

                if(i==j){
                    isPalindrome[i][j]=1;
                }
                else if(i+1==j){
                    isPalindrome[i][j]=s[i]==s[j];
                }
                else{
                    isPalindrome[i][j]=s[i]==s[j] && isPalindrome[i+1][j-1];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};