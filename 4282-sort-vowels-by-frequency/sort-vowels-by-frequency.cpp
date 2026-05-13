class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<char> vow;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vow.push_back(s[i]);
            }
        }
        sort(vow.begin(),vow.end());
        int n1=vow.size();
        map<char,int> mp;
        map<char, int> firstPos;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                mp[s[i]]++;

                if (firstPos.find(s[i]) == firstPos.end()) {
                    firstPos[s[i]] = i;
                }
            }
        }

        int m1=mp.size();
        int count=0;
        vector<pair<int,char>> v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(), v.end(),[&](pair<int, char> a, pair<int, char> b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return firstPos[a.second] < firstPos[b.second];
        });
        int idx=0;
        for(auto x : v){
            for(int i = 0; i < x.first; i++){
                vow[idx]=x.second;
                idx++;
            }
        }
        int low=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                s[i]=vow[low];
                low++;
            }
        }
        return s;
    }
};