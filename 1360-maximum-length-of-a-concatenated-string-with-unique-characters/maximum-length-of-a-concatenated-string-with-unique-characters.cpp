class Solution {
public:
    bool duplicate(string s1,string s2){
        vector<int> freq(26,0);
        for(char c:s1){
            freq[c-'a']++;
            if(freq[c-'a'] > 1) {
                return true;
            }
        }
        for(char c:s2){
            if(freq[c-'a']>0){
                return true;
            }
        }
        return false;
    }

    int solve(vector<string>& arr,int i,string temp,unordered_map<string,int> &mpp){
        int n = arr.size();
        if(i>=n){
            return temp.size();
        }
        if(mpp.find(temp)!=mpp.end()){
            return mpp[temp];
        }
        int include = 0;
        int exclude = 0;

        if(duplicate(arr[i],temp)){
            exclude = solve(arr,i+1,temp,mpp);
        }
        else{
            include = solve(arr,i+1,temp+arr[i],mpp);
            exclude = solve(arr,i+1,temp,mpp);
        }

        return mpp[temp]=max(include,exclude);

    }

    int maxLength(vector<string>& arr) {
        string temp="";
        unordered_map<string,int> mpp;
        return solve(arr,0,temp,mpp);
    }
};