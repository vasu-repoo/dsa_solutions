
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        // Make the first row free
        for (int j = 0; j < n; j++) {
            grid[0][j] = '.';
        }

        // Make the last column free
        for (int i = 1; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    Solution sol;
    vector<string> result = sol.createGrid(m, n);

    cout << "[";
    for (int i = 0; i < m; i++) {
        cout << "\"" << result[i] << "\"";
        if (i < m - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
