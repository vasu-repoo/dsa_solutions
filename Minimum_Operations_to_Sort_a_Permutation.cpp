
#include <bits/stdc++.h>
using namespace std;
// leetcode problem soln
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;

                if (nums[prev] > nums[curr])
                    return false;
            }
            return true;
        };

        int ans = INT_MAX;

        if (check(1)) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if (check(-1)) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 2, 1};

    cout << sol.minOperations(nums) << endl;

    return 0;
}
/*
Time: O(n) — the array is scanned a constant number of times.
Space: O(1) — only a few variables are used.
*/