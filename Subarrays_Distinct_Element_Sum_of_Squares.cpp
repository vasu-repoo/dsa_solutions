
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(nums[j]);

                int distinct = st.size();
                ans += distinct * distinct;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 1};

    cout << "Output: " << sol.sumCounts(nums) << endl;

    return 0;
}