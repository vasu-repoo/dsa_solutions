
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr long long MOD = 1'000'000'007;

    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    long long nCr(int n, int r) {
        return fact[n] * invFact[r] % MOD
             * invFact[n - r] % MOD;
    }

    long long dfs(const vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;
        left.reserve(n);
        right.reserve(n);

        int root = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ways = nCr(n - 1, (int)left.size());
        ways = ways * dfs(left) % MOD;
        ways = ways * dfs(right) % MOD;

        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);

        for (int i = n; i >= 1; --i)
            invFact[i - 1] = invFact[i] * i % MOD;

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 1, 3};

    cout << "Number of ways: " << sol.numOfWays(nums) << '\n';

    return 0;
}