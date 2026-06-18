class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int currRow=0;
        bool isDown = false;
        if (numRows == 1 || numRows >= s.size()){
            return s;
        }
        for(char c : s){
            rows[currRow] += c;
            if(currRow == 0 || currRow == numRows-1){
                isDown = !isDown;
            }
            currRow+= isDown? 1 : -1;
        }
        string ans;
        for(string s1: rows){
            ans+=s1;
        }
        return ans;
    }
};