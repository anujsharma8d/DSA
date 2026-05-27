class Solution {
public:
    int passwordStrength(string password) {
        int sum=0;
        int n=password.size();
        map<char,int> mpp;
        for(char x:password){
            mpp[x]++;
        }
        for(auto x:mpp){
            if(x.first>='a' && x.first<='z'){
                sum+=1;
            }
            else if(x.first>='A' && x.first<='Z'){
                sum+=2;
            }
            else if(x.first>='0' && x.first<='9'){
                sum+=3;
            }
            else if(x.first=='!' || x.first=='@' || x.first=='#' || x.first=='$'){
                sum+=5;
            }
        }
        return sum;
    }
};