class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        string ans="";
        char temp;
        for(auto a:mpp){
            if(a.second%2!=0){
                temp=a.first;
            }
            int count = a.second/2;
            while(count!=0){
                ans+=a.first;
                count--;
            }
        }
        string s1 = ans;
        reverse(s1.begin(),s1.end());
        if(s.size()%2!=0){
            ans+=temp;
        }
        ans+=s1;
        return ans;
    }
};