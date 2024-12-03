// cpp program to check if a string can
// be converted to another string by
// performing operations
#include <bits/stdc++.h>
using namespace std;

// function to check if a string can be
// converted to another string by
// performing following operations
bool check(string s1, string s2)
{
	// calculates length
	int n = s1.length();
	int m = s2.length();

	bool DP_store[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			DP_store[i][j] = false;
		}
	}
	// mark 1st position as true
	DP_store[0][0] = true;

	// traverse for all DP_storei, j
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j <= s2.length(); j++) {

			// if possible for to convert i 
			// characters of s1 to j characters
			// of s2
			if (DP_store[i][j]) {

				// if upper_case(s1[i])==s2[j]
				// is same
				if (j < s2.length() && 
					(toupper(s1[i]) == s2[j]))
					DP_store[i + 1][j + 1] = true;

				// if not upper then deletion is 
				// possible
				if (!isupper(s1[i]))
					DP_store[i + 1][j] = true;
			}
		}
	}

	return (DP_store[n][m]);
}

// driver code
int main()
{
	string s1 = "daBcd";
	string s2 = "ABC";

	if (check(s1, s2))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
