#include <vector>

class divide_conquer
{
public:
	std::vector<int> vec;

	divide_conquer(std::vector<int> vec);

	//���ֲ���
	//ʱ�临�Ӷȣ�O(logn)
	//�ռ临�Ӷȣ�O(1)
	int binary_search(std::vector<int>& vec, int target);
};
