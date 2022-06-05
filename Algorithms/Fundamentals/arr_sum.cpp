// * Function to find the sum of array elements

#include <iostream>
using namespace std;

int arrSum(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
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

	cout << "Sum of the array elements is: " << arrSum(arr, n) << endl;

	return 0;
}

// * Time Complexity: O(n)
