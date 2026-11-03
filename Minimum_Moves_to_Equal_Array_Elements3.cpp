
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2, 1, 3};

    int maxVal = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        maxVal = max(maxVal, nums[i]);
        sum += nums[i];
    }

    int ans = (maxVal * nums.size()) - sum;

    cout << ans << endl;

    return 0;
}
