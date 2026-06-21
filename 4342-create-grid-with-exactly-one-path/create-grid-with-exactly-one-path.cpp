class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s1="";
        for(int i=0;i<n;i++){
            s1+=".";
        }
        ans.push_back(s1);
        for(int i=1;i<m;i++){
        string s2="";
            for(int j=0;j<n-1;j++){
                s2+="#";
            }
            s2+=".";
            ans.push_back(s2);
        }
        return ans;
    }
};