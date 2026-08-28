class Solution {
public:
    string result="";

    string makePalindrome(string &half, char middle, int n) {
        string rev = half;
        reverse(rev.begin(), rev.end());

        if (n % 2)
            return half + middle + rev;
        else
            return half + rev;
    }

    bool solve(string &half,vector<int> &halfCount,string &tarHalf,int i,string &target,char middle,int n,bool greater){
        if(i==tarHalf.size()){
            string candidate = makePalindrome(half,middle,n);
            if(candidate>target){
                result=candidate;
                return true;
            }
            return false;
        }

        for(char ch='a';ch<='z';ch++){
            if(halfCount[ch-'a']==0){
                continue;
            }
            if(greater==false && ch<tarHalf[i]){
                continue;
            }
            half.push_back(ch);
            halfCount[ch-'a']--;
            bool isGreater = greater || ch>tarHalf[i];
            if(solve(half,halfCount,tarHalf,i+1,target,middle,n,isGreater)){
                return true;
            }
            half.pop_back();
            halfCount[ch-'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> count(26,0);
        for(char ch:s){
            count[ch-'a']++;
        }

        int odd = 0;
        char middle = 0;

        for (int i=0;i<26;i++) {
            if (count[i]%2==1) {
                odd++;
                middle ='a'+i;
            }
        }
        if(odd>1){
            return "";
        }

        vector<int> halfCount(26);
        for(int i=0;i<26;i++){
            halfCount[i]=count[i]/2;
        }
        int halfLen = s.size()/2;
        string tarHalf = target.substr(0,halfLen);

        string half;
        if(!solve(half,halfCount,tarHalf,0,target,middle,target.size(),false)){
            return "";
        }
        
        return result;
    }
};