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
        bool flag = true;//�ж������Ƿ�����
        for (int j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                flag = false;//��������˽�������������Ȼ����
            }
        }
        if (flag) break;//��������Ѿ�����������ѭ��
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
    for (int i = 1; i < vec.size(); i++)//������
    {
        for (int j = 0; j < i; j++)//������
        {
            if (vec[i] < vec[j])
            {
                int tmp = vec[i];
                for (int k = i - 1; k >= j; k--)
                {
                    vec[k + 1] = vec[k];//�������
                }
                vec[j] = tmp;
                break;
            }
        }
    }
}

void sort::shell()
{
    for (int gap = vec.size() / 2; gap > 0; gap /= 2)//����
    {
        for (int i = 0; i < gap; i++)//��ÿ����в�������
        {
            shell_insert(vec, i, gap);
        }
    }
}

void sort::shell_insert(std::vector<int>& vec, int start, int gap)
{
    for (int i = start + gap; i < vec.size(); i += gap)//������
    {
        for (int j = start; j < i; j += gap)//������
        {
            if (vec[i] < vec[j])
            {
                int tmp = vec[i];
                for (int k = i - gap; k >= j; k -= gap)
                {
                    vec[k + gap] = vec[k];//�������
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
    int* arr = new int[max_val + 1] {0};//������������ԭ������ÿ��Ԫ�س��ֵĴ���
    for (auto& v : vec)
    {
        arr[v]++;//�����±�ͳ��ԭ������ÿ��Ԫ�س��ֵĴ���
    }
    vec.clear();
    for (int i = 0; i <= max_val; i++)//�����±�����ȡ���������е�ֵ����0���±�
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
    int bucket_num = (max_val - min_val) / vec.size() + 1;//Ͱ��������+1��Ϊ������ȡ��
    std::vector<std::vector<int>> buckets(bucket_num);
    for (auto& v : vec)//����ÿ��Ԫ�ص�ȡֵ��Χ���з�Ͱ
    {
        int idx = (v - min_val + 1) / vec.size();//�����Ͱ���
        buckets[idx].push_back(v);
    }
    for (auto& v : buckets)//Ͱ������
    {
        std::sort(v.begin(), v.end());
    }
    vec.clear();
    for (auto& v : buckets)//�������ÿ��Ͱ�ڵ�Ԫ��
    {
        for (auto& vv : v)
        {
            vec.push_back(vv);
        }
    }
}

void sort::heap()
{
    for (int i = vec.size() / 2 - 1; i >= 0; i--)//��������
    {
        build_heap(vec, i, vec.size());
    }

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        std::swap(vec[0], vec[i]);//��һ�������һ������
        build_heap(vec, 0, i);//�ؽ���
    }
}

void sort::build_heap(std::vector<int>& vec, int start, int end)
{
    int cur = start;
    int child = 2 * cur + 1;
    while (child < end)
    {
        if ((child + 1 < end) and (vec[child] < vec[child + 1])) child++;//�鿴�������������ڵ�
        if (vec[cur] > vec[child]) break;//������ڵ�����������������ڵ㣬������ѭ��
        std::swap(vec[cur], vec[child]);//���򣬽������ӽڵ�
        cur = child;
        child = 2 * cur + 1;
    }
}
