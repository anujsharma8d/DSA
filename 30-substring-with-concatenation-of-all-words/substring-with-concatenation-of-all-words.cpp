class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(); 
        int m = words.size();
        unordered_map<string,int> mpp;
        for(string s:words){
            mpp[s]++;
        }
        vector<int> ans;
        int wordSize=words[0].size();
        for(int start=0;start<wordSize;start++){
            int left=start;
            int count=0;

            unordered_map<string, int> window;

            for(int right=start;right+wordSize<=n;right+=wordSize){

                string word = s.substr(right,wordSize);

                if(mpp.find(word)==mpp.end()){
                    window.clear();
                    count=0;
                    left=right+wordSize;
                    continue;
                }

                window[word]++;
                count++;

                while(window[word]>mpp[word]){
                    string leftWord = s.substr(left,wordSize);
                    window[leftWord]--;
                    left+=wordSize;
                    count--;
                }

                if(count==m){
                    ans.push_back(left);

                    string leftWord = s.substr(left,wordSize);

                    window[leftWord]--;

                    left+=wordSize;

                    count--;
                }
            }
            
        }
        return ans;
    }
};