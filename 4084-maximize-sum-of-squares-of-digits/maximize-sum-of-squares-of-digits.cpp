class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = ""; 
        for(int i=0;i<num;i++){
            if(num*9<sum){
                return "";
            }
            if(sum>=9){
                sum-=9;
                ans+='9';
            }
            else{
                char c=(sum+'0');
                sum=0;
                ans+=c;
            }
        }
        return ans;
    }
};