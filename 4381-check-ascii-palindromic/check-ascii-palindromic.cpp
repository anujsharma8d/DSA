class Solution {
public:
    string toBinary(int n){
        string s="";
        while(n!=0){
            s+=to_string(n%2);
            n/=2;
        }
        while(s.size()<8){
            s+="0";
        }
        reverse(s.begin(), s.end());
        return s;
    }
    bool isPalindromic(string s) {
        string binstr="";
        for(char c:s){
            int n=c;
            binstr+=toBinary(n);
        }
        int st=0;
        int end=binstr.size()-1;
        while(st<end){
            if(binstr[st]!=binstr[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};