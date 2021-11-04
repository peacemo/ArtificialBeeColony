#include <iostream>
#include "headers/Constants.h"
#include "classes/Food.h"
#include "headers/head.h"
#include "headers/init.h"
#include "headers/abc.h"
//#include "headers/geneticAlgro.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    clock_t startTime,endTime;
    startTime = clock();//计时开始
    abc();
//    geneticAgro();
//    std::cout << sizeof (double ) << std::endl;
    endTime = clock();//计时结束
    std::cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;

//    test
//    int a[5] = {1, 2, 3, 4, 5};
//
//    for (int i = 0; i < 5; ++i) {
//        srand(int(time(0)));
//        int r=rand()%(5-i)+i;
//        int temp = a[i];
//        a[i] = a[r];
//        a[r] = temp;
//    }
//
//    for (int i = 0; i < 5; ++i) {
//        cout << a[i] << ",";
//    }


    return 0;
}
