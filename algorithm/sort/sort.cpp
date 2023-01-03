#include <algorithm>

#include "sort.h"

sort::sort(std::vector<int> vec)
{
    this->vec = vec;
}

void sort::bubble()
{
    for (int i = vec.size() - 1; i > 0; i--)
    {
        bool flag = true;//判断数组是否有序
        for (int j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                flag = false;//如果发生了交换，则数组仍然无序
            }
        }
        if (flag) break;//如果数组已经有序，则跳出循环
    }
}

void sort::select()
{
    for (int i = 0; i < vec.size(); i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[min_idx] > vec[j])
            {
                min_idx = j;
            }
        }
        std::swap(vec[min_idx], vec[i]);
    }
}

void sort::insert()
{
    for (int i = 1; i < vec.size(); i++)//无序区
    {
        for (int j = 0; j < i; j++)//有序区
        {
            if (vec[i] < vec[j])
            {
                int tmp = vec[i];
                for (int k = i - 1; k >= j; k--)
                {
                    vec[k + 1] = vec[k];//整体后移
                }
                vec[j] = tmp;
                break;
            }
        }
    }
}

void sort::shell()
{
    for (int gap = vec.size() / 2; gap > 0; gap /= 2)//分组
    {
        for (int i = 0; i < gap; i++)//对每组进行插入排序
        {
            shell_insert(vec, i, gap);
        }
    }
}

void sort::shell_insert(std::vector<int>& vec, int start, int gap)
{
    for (int i = start + gap; i < vec.size(); i += gap)//无序区
    {
        for (int j = start; j < i; j += gap)//有序区
        {
            if (vec[i] < vec[j])
            {
                int tmp = vec[i];
                for (int k = i - gap; k >= j; k -= gap)
                {
                    vec[k + gap] = vec[k];//整体后移
                }
                vec[j] = tmp;
                break;
            }
        }
    }
}

void sort::count()
{
    int max_val = *std::max_element(vec.begin(), vec.end());
    int* arr = new int[max_val + 1] {0};//创建新数组存放原数组中每个元素出现的次数
    for (auto& v : vec)
    {
        arr[v]++;//根据下标统计原数组中每个元素出现的次数
    }
    vec.clear();
    for (int i = 0; i <= max_val; i++)//按照下标依次取出新数组中的值大于0的下标
    {
        while (arr[i])
        {
            vec.push_back(i);
            arr[i]--;
        }
    }
    delete[]arr;
}

void sort::bucket()
{
    int max_val = *std::max_element(vec.begin(), vec.end());
    int min_val = *std::min_element(vec.begin(), vec.end());
    int bucket_num = (max_val - min_val) / vec.size() + 1;//桶的数量，+1是为了向上取整
    std::vector<std::vector<int>> buckets(bucket_num);
    for (auto& v : vec)//按照每个元素的取值范围进行分桶
    {
        int idx = (v - min_val + 1) / vec.size();//计算分桶编号
        buckets[idx].push_back(v);
    }
    for (auto& v : buckets)//桶内排序
    {
        std::sort(v.begin(), v.end());
    }
    vec.clear();
    for (auto& v : buckets)//遍历输出每个桶内的元素
    {
        for (auto& vv : v)
        {
            vec.push_back(vv);
        }
    }
}

void sort::heap()
{
    for (int i = vec.size() / 2 - 1; i >= 0; i--)//构建最大堆
    {
        build_heap(vec, i, vec.size());
    }

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        std::swap(vec[0], vec[i]);//第一个与最后一个交换
        build_heap(vec, 0, i);//重建堆
    }
}

void sort::build_heap(std::vector<int>& vec, int start, int end)
{
    int cur = start;
    int child = 2 * cur + 1;
    while (child < end)
    {
        if ((child + 1 < end) and (vec[child] < vec[child + 1])) child++;//查看左右子树的最大节点
        if (vec[cur] > vec[child]) break;//如果父节点大于左右子树的最大节点，则跳出循环
        std::swap(vec[cur], vec[child]);//否则，交换父子节点
        cur = child;
        child = 2 * cur + 1;
    }
}

void sort::quick(int left, int right)
{
    if (left >= right) return;

    //默认最左侧元素为基准元素
    int pivot = vec[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        while ((i < j) and (vec[j] > pivot)) j--;//从右向左找比pivot小的值
        if (i < j) vec[i++] = vec[j];
        while ((i < j) and (vec[i] < pivot)) i++;//从左向右找比pivot大的值
        if (i < j) vec[j--] = vec[i];
    }
    vec[i] = pivot;
    quick(left, i - 1);
    quick(i + 1, right);
}

void sort::merge(int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge(left, mid);//递归分解
    merge(mid + 1, right);
    _merge(left, right, mid);//合并排序
}

void sort::_merge(int left, int right, int mid)
{
    int* tmp = new int[right - left + 1];

    int i = left;
    int j = mid + 1;
    int idx = 0;
    while ((i <= mid) and (j <= right))
    {
        if (vec[i] <= vec[j]) tmp[idx++] = vec[i++];//比较左右两个数组的元素大小，较小的元素放入tmp数组
        else tmp[idx++] = vec[j++];
    }
    while (i <= mid) tmp[idx++] = vec[i++];//将剩余的元素放入tmp数组
    while (j <= mid) tmp[idx++] = vec[j++];//将剩余的元素放入tmp数组

    for (int i = 0; i < idx; i++) vec[left + i] = tmp[i];

    delete[]tmp;
}
