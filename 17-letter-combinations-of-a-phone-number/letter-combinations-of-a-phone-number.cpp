class Solution {
public:
    vector<string> ans;
     void solve(string digits, string output, int index, vector<string> &ans, vector<string> &mpp){
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
        int number = digits[index]-'0';
        string value = mpp[number];
        for(int i=0;i<value.size();i++){
            output.push_back(value[i]);
            solve(digits,output,index+1,ans,mpp);
            output.pop_back();
        }
     }

    vector<string> letterCombinations(string digits) {
        vector<string> mpp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string output;
        if(digits.size()==0){
            return ans;
        }
        solve(digits,output,0,ans,mpp);
        return ans;
    }
};