#include <iostream>
#include <algorithm>
const int SIZE = 9;

void bubbleSort(int arr[])
{
	for (int i = 0; i < SIZE - 1; ++i)
	{
		int checkNoChanges = true;
		for (int j = 0; j < SIZE - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				checkNoChanges = false;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				//std::swap(arr[j], arr[j + 1]);
			}
		}
		if (checkNoChanges)
		{
			std::cout << "Early termination on iteration: " << i + 1 << std::endl;
			break;
		}
	}
}

int main()
{
	int arr[SIZE]{ 7, 5, 6, 4, 9, 8, 2, 1, 3 };

	for (int i = 0; i < SIZE; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	bubbleSort(arr);

	for (int i = 0; i < SIZE; ++i)
		std::cout << arr[i] << " ";

	system("pause");
}