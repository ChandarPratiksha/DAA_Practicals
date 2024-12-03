#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void findSubsets(vector<int>& arr) {
    // Sort the array to handle duplicates
    sort(arr.begin(), arr.end());
    int n = arr.size();
    set<vector<int>> subsets; // Use a set to store unique subsets

    // Total number of subsets is 2^n
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // Check if the ith bit is set
                subset.push_back(arr[i]);
            }
        }
        subsets.insert(subset); // Add the subset to the set
    }

    // Print all unique subsets
    cout << "{ ";
    for (const auto& subset : subsets) {
        cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "} ";
    }
    cout << "}" << endl;
}

int main() {
    vector<int> arr = {1, 2, 2};
    cout << "Input: {1, 2, 2}\nOutput: ";
    findSubsets(arr);

    arr = {1, 2};
    cout << "Input: {1, 2}\nOutput: ";
    findSubsets(arr);

    return 0;
}
