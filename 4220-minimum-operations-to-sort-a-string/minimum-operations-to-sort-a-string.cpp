class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        bool sorted = true;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }
        if(n==1){
            return 0;
        }
        if(n==2){
            if(s[0]>s[1]){
                return -1;
            }
        }

        char mini = *min_element(s.begin(), s.end());
        char maxi = *max_element(s.begin(), s.end());

        if (sorted)
            return 0;

        if(mini == s[0] || maxi == s[n-1]){
            return 1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mini || s[i] == maxi) {
                return 2;
            }
        }
        return 3;
        
    }
};