class Solution {
public:
    int fact(int k) {
        if (k == 0) {
            return 1;
        } else {
            return k * fact(k - 1);
        }
    }

    bool isDigitorialPermutation(int n) {
        string s = to_string(n);
        int n1 = s.size();
        int sum = 0;

        for (int i = 0; i < n1; i++) { 
            int k = s[i] - '0';
            sum += fact(k);
        }
        sort(s.begin(),s.end());
        string s1=to_string(sum);
        sort(s1.begin(),s1.end());
        return s == s1;
    }
};