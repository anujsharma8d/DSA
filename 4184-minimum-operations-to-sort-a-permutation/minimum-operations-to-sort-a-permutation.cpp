class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = nums[0];
        int ans = INT_MAX;

        // Case 1: rotation of [0, 1, ..., n-1]
        bool asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) { asc = false; break; }
        }
        if (asc) {
            int leftOnly = (n - k) % n;               // rotate left only
            int revRotRev = (k == 0) ? 0 : k + 2;     // reverse, rotate, reverse
            ans = min(ans, min(leftOnly, revRotRev));
        }

        // Case 2: rotation of [n-1, ..., 1, 0]
        bool desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != ((k - i) % n + n) % n) { desc = false; break; }
        }
        if (desc) {
            int s = (k + 1) % n;
            // rotate left s times then reverse, or reverse then rotate left (n-s)%n times
            ans = min(ans, min(1 + s, 1 + (n - s) % n));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};