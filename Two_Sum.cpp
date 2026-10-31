#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store: Key = number value, Value = its index
        unordered_map<int, int> numMap; 
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If the complement exists in our map, we found the pair
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, store the current number and its index
            numMap[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution is found
    }
};

// Main function to run and test in VS Code
int main() {
    Solution solver;
    
    // Example 1
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = solver.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }   
    return 0;
}