#include <iostream>
#include "headers/Constants.h"
#include "classes/Food.h"
#include "headers/head.h"
#include "headers/init.h"
#include "headers/abc.h"
#include "headers/geneticAlgro.h"

void loadCargo() {
    cout << "startCargo..." << endl;
    startCargo(16224,7,13,19,26);
    getCargo("output/mCargo1_first.txt","output/mCargo2_first.txt");
    cout << "candidate..." << endl;
    candidate();
    getCandidate();
    cout << "selectCargo..." << endl;
    selectCargo(20211220);
    cargoRule("R","S","H","C");
    //updateCargo();
    getCargo("output/mCargo1.txt","output/mCargo2.txt");
    getCargo_now("output/Cargo_now1.txt","output/Cargo_now2.txt");
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    //loadCargo();
    abc();
//    geneticAgro();
//    std::cout << sizeof (double ) << std::endl;
    endTime = clock();//计时结束
    std::cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
    ofstream mainout;
    mainout.open("output/best.txt",ios::app); 
    mainout<< "\nThe run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" <<endl;
    mainout.close();

    system("pause");
    return 0;
}
