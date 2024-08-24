#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold shop timings
struct Shop {
    int s, e;
};

// Comparator function to sort shops based on their eing time
bool compare(Shop a, Shop b) {
    return a.e < b.e;
}

// Function to find the maximum number of shops that can be visited by K persons
int maxShopsVisited(vector<int>& S, vector<int>& E, int K) {
    int N = S.size();
    vector<Shop> shops(N);

    // Store the s and e times in the Shop structure
    for (int i = 0; i < N; ++i) {
        shops[i] = {S[i], E[i]};
    }

    // Sort the shops based on their e times
    sort(shops.begin(), shops.end(), compare);

    vector<int> persons(K, 0);
    int cnt = 0;

    // Assign shops to persons optimally
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (persons[j] <= shops[i].s) {
                persons[j] = shops[i].e;
                cnt++;
                break;
            }
        }
    }

    return cnt;
}

int main() {
    vector<int> S1 = {1, 8, 3, 3, 3};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum shops visited: " << maxShopsVisited(S1, E1, K1) << endl;

    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum shops visited: " << maxShopsVisited(S2, E2, K2) << endl;

    return 0;
}
