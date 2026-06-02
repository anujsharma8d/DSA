class Solution {
public:
    string countAndSay(int n) {
        string s1 = "1";
        for (int i=1; i<n;i++) {
            string temp = "";
            int n1 = s1.size();
            for (int j=0; j<n1; ) {
                char ch=s1[j];
                int cnt=0;
                while (j<n1 && s1[j]==ch) {
                    cnt++;
                    j++;
                }
                temp +=to_string(cnt);
                temp +=ch;
            }
            s1=temp;
        }
        return s1;
    }
};