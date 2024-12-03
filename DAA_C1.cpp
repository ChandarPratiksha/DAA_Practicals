#include <iostream>
#include <vector>

using namespace std;

// Function to find the number of ways to make change
int countWaysToMakeChange(int coins[], int numCoins, int sum) {
    // Create a dp array to store the number of ways for each value
    vector<int> dp(sum + 1, 0);

    // Base case: There is 1 way to make change for 0 sum (no coins)
    dp[0] = 1;

    // Loop through each coin
    for (int i = 0; i < numCoins; i++) {
        // For each coin, update the dp array for all sums from the coin's value to the target sum
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    // The result is stored in dp[sum]
    return dp[sum];
}

int main() {
    int coins[] = {1, 2, 3}; // Array of coin denominations
    int sum = 4; // Target sum
    int numCoins = sizeof(coins) / sizeof(coins[0]); // Number of coin denominations

    // Call the function to find the number of ways to make change
    int ways = countWaysToMakeChange(coins, numCoins, sum);

    // Output the result
    cout << "Number of ways to make change for " << sum << " is: " << ways << endl;

    return 0;
}
