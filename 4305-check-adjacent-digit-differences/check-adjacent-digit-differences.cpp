class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(abs((s[i]-'0')-(s[i+1]-'0'))>2){
                return false;
                break;
            }
        }
        return true;
    }
};