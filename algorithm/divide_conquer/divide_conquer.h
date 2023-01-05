#include <vector>

class divide_conquer
{
public:
	std::vector<int> vec;

	divide_conquer(std::vector<int> vec) :vec(vec) {};

	//二分查找
	//时间复杂度：O(logn)
	//空间复杂度：O(1)
	int binary_search(std::vector<int>& vec, int target);
};
