#include <iostream>
#include <vector>

using namespace std;

// Function to check if there exists a subset with the given sum
bool isSubsetSum(vector<int>& set, int n, int sum) {
    // Create a 2D dp array of size (n+1) x (sum+1)
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // If sum is 0, then there's a subset (empty subset) for any set
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // If set is empty and sum > 0, then there's no subset
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = false;
    }

    // Fill the subset table using the recurrence relation
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The answer will be stored in dp[n][sum]
    return dp[n][sum];
}

int main() {
    vector<int> set = {3, 34, 4, 4, 1, 2}; // Set of non-negative integers
    int sum = 9; // Target sum
    int n = set.size(); // Size of the set

    // Call the function to check if a subset with the given sum exists
    if (isSubsetSum(set, n, sum)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
