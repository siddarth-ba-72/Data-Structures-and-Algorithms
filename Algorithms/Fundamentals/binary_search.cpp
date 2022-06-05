// * Binary Search

#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int x)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == x)
		{
			return mid;
		}
		else if (arr[mid] < x)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
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

	int index = binary_search(arr, n, x);
	if (index == -1)
	{
		cout << "Element not found" << endl;
	}
	else
	{
		cout << "Element found at index: " << index << endl;
	}

	return 0;
}

// * Time Complexity: O(log n)
