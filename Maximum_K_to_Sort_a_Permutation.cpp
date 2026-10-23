
#include <iostream>
#include <vector>
using namespace std;

int sortPermutation(vector<int>& nums) {
    int n = nums.size();
    int k = -1;

    for (int i = 0; i < n; i++) {
        if (nums[i] != i) {
            k &= nums[i];
        }
    }

    return (k == -1) ? 0 : k;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << sortPermutation(nums) << endl;

    return 0;
}
