#include <iostream>
#include <vector>

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
    std::vector<int> vec = { 4,6,17,3,10,15 };
    sort s(vec);
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
    s.heap();
    printVec(s.vec);
}
