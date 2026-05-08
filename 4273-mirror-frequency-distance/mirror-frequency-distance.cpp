class Solution {
public:
    int mirrorFrequency(string s) {
        int n=s.size();
        vector<int> freq(128,0);
        for(char x:s){
            freq[x]++;
        }
        int ans=0;
        for(char i='a';i<='m';i++){
            char m='z'-(i-'a');
            ans+=abs(freq[i]-freq[m]);
        }
        for(char i='0';i<='4';i++){
            char m='9'-(i-'0');
            ans+=abs(freq[i]-freq[m]);
        }
        return ans;
    }
};