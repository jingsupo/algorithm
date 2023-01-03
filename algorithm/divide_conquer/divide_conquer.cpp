#include "divide_conquer.h"

divide_conquer::divide_conquer(std::vector<int> vec)
{
	this->vec = vec;
}

int divide_conquer::binary_search(std::vector<int>& vec, int target)//数组必须是升序排列
{
	int low = 0;
	int high = vec.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (vec[mid] > target)
		{
			high = mid - 1;
		}
		else if (vec[mid] < target)
		{
			low = mid + 1;
		}
		else if (vec[mid] == target)
		{
			return mid;
		}
	}

	return -1;
}
