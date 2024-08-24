// number of zeros at the end
#include <bits/stdc++.h>
using namespace std;
int index_of_first_zero(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			return i;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int pos= index_of_first_zero(arr, n);
	if (pos == -1) {
		cout << "Count of zero is 0" << endl;
	}
	else {
		cout << "count of zero is " << n - pos << endl;
	}
	return 0;
}

