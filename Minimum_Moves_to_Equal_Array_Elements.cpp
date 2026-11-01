
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMoves(vector<int>& nums) {
    int minVal = *min_element(nums.begin(), nums.end());

    int moves = 0;

    for (int num : nums) {
        moves += num - minVal;
    }

    return moves;
}

int main() {
    vector<int> nums = {1, 2, 3};

    cout << minMoves(nums) << endl;

    return 0;
}
