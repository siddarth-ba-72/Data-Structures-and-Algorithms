// * Linear Search

#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int x;
	cout << "x = ";
	cin >> x;

	int index = linear_search(arr, n, x);
	if (index == -1)
	{
		cout << "Element not found" << endl;
	}
	else
	{
		cout << "Element found at position: " << index + 1 << endl;
	}

	return 0;
}

// * Time Complexity: O(n)
