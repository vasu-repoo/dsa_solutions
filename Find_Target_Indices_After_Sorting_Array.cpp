
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;

    vector<int> result = targetIndices(nums, target);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
