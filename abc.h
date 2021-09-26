//
// Created by shikamaru on 2021/9/21.
//

#ifndef ABC_ABC_H
#define ABC_ABC_H

#include "classes/Food.h"
#define ITERLIMIT 5
#define MAXITERTIME 500

double* calAccessProb(Food _foods[FoodsNum]) {
    static double P[FoodsNum] = {0};
    double total = 0;
    for (int i = 0; i < FoodsNum; ++i) {
        total += _foods[i].getFitness();
    }
    for (int i = 0; i < FoodsNum; ++i) {
        P[i] = _foods[i].getFitness() / total;
    }
    return P;
}

void hybrid(Food *foods, int j) {// 两个时间序列进行交叉，遗传下一代，交叉的个体数量为总数量的三分之一（取整）
//    Food tempFood = foods[j];
    Food tempFood;
    // copy food[j] to tempFood and avoid using the same address of the time sequence
    for (int i = 0; i < GoodsNum; ++i) { //将 foods[j] 序列的每一个值依次赋值给 tempFood
        tempFood.setSequence(i, foods[j].getSequence(i));
    }
    tempFood.setFitness(foods[j].getFitness());
    tempFood.setSeqLen(foods[j].getSeqLen());
    tempFood.setCounts(foods[j].getCounts());

    int r = rand()%( (GoodsNum - GoodsNum / 3) - 0 + 1) + 0; // 随机选取交叉序列的起始位置[0, 7]
    int rdFdIndex = rand()%( (FoodsNum - 1) - 0 + 1) + 0; // [0, FoodsNum-1]
    Food randomFood = foods[rdFdIndex]; // 随机选取一个食物源交叉

    for (int k = r; k < r + (GoodsNum/3); ++k) { // 取出从随机位置开始，向后至“总数的三分之一”个元素
        /**
         *  全部迭代完后的效果就是
         *  从 food2 中选取一段序列
         *  从 food1 中删除掉这些序列中的值
         *  再将这些值拼接到 food1 的末尾
         * */
        int currentElement = randomFood.getSequence(k);
        tempFood.removeFromSequence(currentElement); // (n^2) 从自身的序列中删除交叉对象的该元素
        tempFood.addIntoSequence(currentElement); // 再将其置于序列的末尾
    }
    tempFood.calFitness(); // 交叉完后重新计算适应度值
    if (tempFood.getFitness() < foods[j].getFitness()) { // 比较前后的适应度值，并选择是否更新
        foods[j] = tempFood;
        foods[j].calFitness();
        foods[j].setCounts(0);
    } else {
        foods[j].updateCounts();
    }
}

void abc() {

    int empBeeNum = FoodsNum; //引领蜂
    int onLookBeeNum = FoodsNum; //跟随蜂
    int fitness[FoodsNum] = {0};

    Food foods[FoodsNum];

    for (int i = 0; i < FoodsNum; ++i) {
        std::cout << foods[i] << std::endl;
    }

    std::cout << "*****************************" << std::endl;

    for (int i = 0; i < MAXITERTIME; ++i) {  //总迭代次数

        /**
         * 引领蜂对于每一个食物源进行访问（采集）
         * 采集过程为：
         *  . 对于该食物源 food1 ，选择邻域内的另外一个食物源 food2 进行交叉，产生一个新的食物源 food3
         *  . 对比该食物源 food1 与新食物源 food3 的适应度值 fit1 与 fit3
         *  . food1 = fit1 < fit3 ? food1 : food3
         *  . 若 food1 的值进行了更新，则将采集次数 count 置 0，否则 count + 1
         *      （此部的目的是为了模拟食物源采集之后的消耗，若采集次数增加到一定数目 Limit，则舍弃该食物源，并生成一个新的食物源）
         * 直到所有的食物源都被采集
         * */
        for (int j = 0; j < empBeeNum; ++j) {  //引领蜂采集阶段
            hybrid(foods, j);
        }

        double *accessProb; // 计算决策概率集
        accessProb = calAccessProb(foods);

        /**
         * 跟随蜂阶段，蜜蜂对食物源随机进行访问
         * */
        int currentFood = 0;
        for (int k = 0; k < onLookBeeNum; ++k) {
            double randProb = (rand()%(30 - 10 + 1) + 10) / 100;
            if (currentFood >= (FoodsNum - 1)) { currentFood = 1; }
            for (int j = currentFood; j < FoodsNum; ++j) {
                if (randProb > accessProb[j]) {
                    hybrid(foods, j);
                } else {
                    continue;
                }
            }

        }


        /**
         * 侦查蜂阶段，蜜蜂抛弃不新鲜的食物源
         * */
        for (int s = 0; s < FoodsNum; ++s) {
            if (foods[s].getCounts() > 10) {
                foods[s].stirSequence();
                foods[s].calFitness();
                foods[s].setCounts(0);
            }
        }
    }

    for (int i = 0; i < FoodsNum; ++i) {
        std::cout << foods[i] << std::endl;
    }

}

#endif //ABC_ABC_H
