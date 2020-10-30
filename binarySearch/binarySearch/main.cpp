#include <iostream>

int binarySearch(int* arr, int SIZE, int num)
{
	int start = 0;
	int end = SIZE - 1;

	while (start < end)
	{
		int mid = (start + end) / 2;
		if (num == arr[mid])
			return mid;
		else if (num < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int main()
{
	const int SIZE = 13;
	int arr[SIZE]{ 1, 4, 5, 9, 24, 42, 43, 47, 55, 65, 73, 88, 94};
	std::cout << binarySearch(arr, SIZE, 44) << std::endl;
}