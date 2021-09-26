#include <iostream>
#include "classes/Food.h"
#include "abc.h"


void calFitness() {
    // 计算序列的适应度值
    int seq[10] = {4, 5, 3, 2, 6, 1, 10, 7, 9, 8};
    int target[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double fit = 0;
    for (int i = 0; i < 10; ++i) {
        int a = seq[i];
        int b = target[i];
        fit += (double)(abs(a-b));
    }
    std::cout<<fit;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    abc();
//    calFitness();
    return 0;
}
