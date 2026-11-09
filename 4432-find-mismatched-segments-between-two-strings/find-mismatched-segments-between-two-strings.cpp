class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();
        int i = 0;
        vector<vector<string>> ans;
        while(i<n){
            string str1 = "";
            string str2 = "";
            bool take = false;
            while(s1[i]!=s2[i]){
                str1+=s1[i];
                str2+=s2[i];
                i++;
                take = true;
            }
            if(take){
                ans.push_back({str1,str2});
            }
            else{
                i++;
            }
        }
        return ans;
    }
};