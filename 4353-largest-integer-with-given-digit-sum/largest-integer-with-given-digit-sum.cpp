class Solution {
public:
    int largestInteger(int n, int s) {
        if(9*n<s){
            return -1;
        }
        string ans="";
        int size=n;
        while(n>0){
            int rem = s;
            if(s>9){
                s-=9;
                ans+='9';
            }
            else{
                s-=rem;
                ans+=char(rem + '0');
            }
            n--;
        }
        return stoi(ans);
    }
};