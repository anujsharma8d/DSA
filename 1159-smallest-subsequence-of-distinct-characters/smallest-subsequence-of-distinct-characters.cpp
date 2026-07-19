class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        unordered_map<char,int> last;
        unordered_map<char,bool> visited;
        for(int i=0;i<n;i++){
            last[s[i]]=i;
        }
        string s1="";
        for(int i=0;i<n;i++){
            char c = s[i];
            if(visited[c]){
                continue;
            }
            while(!s1.empty() && s1.back()>c && last[s1.back()]>i){
                visited.erase(s1.back());
                s1.pop_back();
            }
            s1.push_back(c);
            visited[c]=true;
        }
        return s1;
    }
};