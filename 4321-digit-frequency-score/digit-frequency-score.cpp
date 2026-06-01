class Solution {
public:
    int digitFrequencyScore(int n) {
        string s = to_string(n);
        int n1=s.size();
        map<char,int> mpp;
        for(int i=0;i<n1;i++){
            mpp[s[i]]++;
        }
        int sum=0;
        for(auto x:mpp){
            sum+=(x.first-'0')*x.second;
        }
        return sum;
    }
};