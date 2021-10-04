#include <iostream>
#include "abc.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    clock_t startTime,endTime;
    startTime = clock();//计时开始
    abc();
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
