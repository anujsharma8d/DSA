class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int ans = 0;
        int lastEnd = 0;

        for(auto &m : meetings) {
            int start = m[0];
            int end = m[1];

            if(start > lastEnd + 1) {
                ans += start - lastEnd - 1;
            }

            lastEnd = max(lastEnd, end);
        }

        if(lastEnd < days) {
            ans += days - lastEnd;
        }

        return ans;
    }
};