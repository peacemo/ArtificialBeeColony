#include <iostream>
#include "abc.h"
#include "geneticAlgro.h"

//void removeFromSequence(int *array, int target) {
//    for (int i = 0; i < 10; ++i) {
//        if (array[i] == target) {
//            for (int j = i; j < 10; ++j) {
//                array[j] = array[j+1];
//            }
//            return;
//        }
//    }
//    return;
//}
//void addIntoSequence(int *array, int index, int target) {
//    for (int i = (10 - 1 - 1); i >= index; i--) {
//        array[i+1] = array[i];
//    }
//    array[index] = target;
//
//}

int main() {
    std::cout << "Hello, World!" << std::endl;

    clock_t startTime,endTime;
    startTime = clock();//计时开始
    abc();
//    geneticAgro();
    endTime = clock();//计时结束
    std::cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;



    /** Test */
//    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int b[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//    for (int i = 3; i < 5; i++) {
//        removeFromSequence(a, b[i]);
//        addIntoSequence(a, i, b[i]);
//    }
//    for (int i = 0; i < 10; ++i) {
//        cout << a[i] << " ";
//    }

    return 0;
}
