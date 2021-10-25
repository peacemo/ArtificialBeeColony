#include <iostream>
#include "headers/Constants.h"
#include "classes/Food.h"
#include "headers/head.h"
#include "headers/init.h"
#include "headers/abc.h"
#include "headers/geneticAlgro.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    clock_t startTime,endTime;
    startTime = clock();//计时开始
    abc();
//    genesticAgro();
//    std::cout << sizeof (double ) << std::endl;
    endTime = clock();//计时结束
    std::cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;

    return 0;
}
