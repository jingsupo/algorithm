#include <vector>

class sort
{
public:
    std::vector<int> vec;

    sort(std::vector<int> vec) :vec(vec) {};

    //冒泡排序
    //时间复杂度：O(n^2)
    //空间复杂度：O(1)
    //稳定性：稳定
    void bubble();

    //选择排序
    //时间复杂度：O(n^2)
    //空间复杂度：O(1)
    //稳定性：不稳定
    void select();

    //插入排序
    //时间复杂度：O(n^2)
    //空间复杂度：O(1)
    //稳定性：稳定
    void insert();

    //希尔排序/缩小增量排序
    //时间复杂度：O(nlogn)
    //空间复杂度：O(1)
    //稳定性：不稳定
    void shell();
    void shell_insert(std::vector<int>& vec, int start, int gap);

    //计数排序
    //时间复杂度：O(n+m)
    //空间复杂度：O(m)
    //稳定性：稳定
    void count();

    //桶排序
    //时间复杂度：O(n+m)
    //空间复杂度：O(n+m)
    //稳定性：稳定
    void bucket();

    //堆排序
    //时间复杂度：O(nlogn)
    //空间复杂度：O(1)
    //稳定性：不稳定
    void heap();
    void build_heap(std::vector<int>& vec, int start, int end);

    //快速排序
    //时间复杂度：O(nlogn)
    //空间复杂度：O(logn)
    //稳定性：不稳定
    void quick(int left, int right);

    //归并排序
    //时间复杂度：O(nlogn)
    //空间复杂度：O(n)
    //稳定性：稳定
    void merge(int left, int right);
    void _merge(int left, int right, int mid);
};
