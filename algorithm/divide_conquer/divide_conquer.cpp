#include <iostream>

#include "divide_conquer.h"

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

void divide_conquer::hannuota(int num, char a, char b, char c)//num代表塔的层数，abc代表三根柱子，a为起点，b为过渡，c为终点
{
	if (num == 1)
	{
		std::cout << "第 1 个盘子从 " << a << " -> " << c << std::endl;
		return;
	}

	hannuota(num - 1, a, c, b);//假如有两个盘子，把最上面的盘子移动到b，移动过程中会用到c
	std::cout << "第 " << num << " 个盘子从 " << a << " -> " << c << std::endl;//把最下面的盘子移动到c
	hannuota(num - 1, b, a, c);//把b的盘子移动到c，移动过程中会用到a
}
