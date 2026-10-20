class Solution {
public:
    int sortableIntegers(vector<int>& nums) {

        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        long long ans = 0;

        for (int k = 1; k <= n; k++) {

            if (n % k != 0)
                continue;

            bool possible = true;

            for (int l = 0; l < n; l += k) {

                int r = l + k;

                int descent = -1;
                int count = 0;

                for (int i = l; i < r - 1; i++) {
                    if (nums[i] > nums[i + 1]) {
                        descent = i;
                        count++;

                        if (count > 1) {
                            possible = false;
                            break;
                        }
                    }
                }

                if (!possible)
                    break;

                int start = (descent == -1) ? l : descent + 1;

                for (int j = 0; j < k; j++) {
                    int idx = l + ((start - l + j) % k);

                    if (nums[idx] != sorted[l + j]) {
                        possible = false;
                        break;
                    }
                }

                if (!possible)
                    break;
            }

            if (possible)
                ans += k;
        }

        return ans;
    }
};