#include <algorithm>
#include <iostream>
#include <vector>

#include "divide_conquer/divide_conquer.h"
#include "dynamic_programming/dynamic_programming.h"
#include "sort/sort.h"

void printVec(const std::vector<int>& vec)
{
    for (auto& v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = { 4, 6, 17, 3, 10, 15 };
    //排序算法
    //sort s(vec);
    //s.bubble();
    //printVec(s.vec);
    //s.select();
    //printVec(s.vec);
    //s.insert();
    //printVec(s.vec);
    //s.shell();
    //printVec(s.vec);
    //s.count();
    //printVec(s.vec);
    //s.bucket();
    //printVec(s.vec);
    //s.heap();
    //printVec(s.vec);
    //s.quick(0, s.vec.size() - 1);
    //printVec(s.vec);
    //s.merge(0, s.vec.size() - 1);
    //printVec(s.vec);
    //分治算法
    //divide_conquer dc(vec);
    //std::sort(dc.vec.begin(), dc.vec.end());//二分查找前必须先对数组排序
    //int target = 10;
    //std::cout << "要查找的元素 " << target << " 在数组中的索引为 " << dc.binary_search(dc.vec, target) << std::endl;
    //dc.hannuota(5, 'A', 'B', 'C');
    //动态规划算法
    dynamic_programming dp;
    char str1[] = "1AB2345CD";
    char str2[] = "12345EF";
    std::cout << str1 << " 和 " << str2 << " 最长公共子串：" << dp.longest_common_substring(str1, str2) << std::endl;
}
