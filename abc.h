//
// Created by shikamaru on 2021/9/21.
//

#ifndef ABC_ABC_H
#define ABC_ABC_H

#include "classes/Food.h"
#define LIMIT 10
#define MAXITERTIME 2000
Food currentBestFood;


/*!
 * 复制 Food
 * @param sFood 源 Food
 * @param tFood 目标 Food
 */
void fdcpy(Food &sFood, Food &tFood) {
    for (int i = 0; i < GoodsNum; ++i) {
        // 将 sFood 序列的每一个值依次赋值给 tFood
        // 这样做的目的是防止该属性的指针直接赋值，否则对复制 Food 修改时，源 Food 也会改变
        tFood.setSequence(i, sFood.getSequence(i));
    }
    // 其他属性的复制
    tFood.setFitness(sFood.getFitness());
    tFood.setSeqLen(sFood.getSeqLen());
    tFood.setCounts(sFood.getCounts());
}

/*!
 * 计算第一次交叉之后的每一个食物源访问的概率
 * @param _foods 所有的已经交叉之后的食物源
 * @return 每一个食物源访问概率的数组
 */
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

/*!
 * 交叉操作：
 * 对于当前的食物源 f1，随机选取另外一个食物源 f2，从 f2 中选取其序列 s2 的三分之一 g2，
 * 再从 f1 的序列 s1 中剔除掉与 g2 相同的序列，最后将 g2 连接到 s1 的后面
 * @param foods 所有食物源
 * @param j 当前食物源的index
 */
void hybrid(Food *foods, int j) {// 两个时间序列进行交叉，遗传下一代，交叉的个体数量为总数量的三分之一（取整）
    // copy food[j] to tempFood and avoid using the same address of the time sequence
    Food tempFood;
    fdcpy(foods[j], tempFood);

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

        if (foods[j].getFitness() < currentBestFood.getFitness()) {
            // 每次交叉之后如果有更新，则与当前 Best 比较是否更新 Best
            fdcpy(foods[j], currentBestFood);
        }
    } else {
        foods[j].updateCounts();
    }
}

/*!
 * ABC算法主体
 */
void abc() {
    int empBeeNum = FoodsNum; // 引领蜂
    int onLookBeeNum = FoodsNum; // 跟随蜂

    Food foods[FoodsNum];
    fdcpy(foods[0], currentBestFood); // 初始化将第一个食物源设置为 Best

    for (int i = 0; i < FoodsNum; ++i) {
        std::cout << foods[i] << std::endl;
        if (foods[i].getFitness() < currentBestFood.getFitness()) { // 第一轮迭代，找到当前 Best
            fdcpy(foods[i], currentBestFood);
        }
    }

    std::cout << "*****************************" << std::endl;

    for (int i = 0; i < MAXITERTIME; ++i) {  // 总迭代次数

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
        for (int j = 0; j < empBeeNum; ++j) {  // 引领蜂采集阶段
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
            if (foods[s].getCounts() > LIMIT) {
                foods[s].stirSequence();
                foods[s].calFitness();
                foods[s].setCounts(0);
            }
        }

//        std::cout << currentBestFood.getFitness() << std::endl;
        if (currentBestFood.getFitness() == 0) break;
    }

    for (int i = 0; i < FoodsNum; ++i) {
        std::cout << foods[i] << std::endl;
    }

    std::cout << "*****************************" << std::endl;
    std::cout << "The best ever: " << currentBestFood << std::endl;

}

#endif //ABC_ABC_H
