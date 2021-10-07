#ifndef _GENETICALGRO_H_
#define _GENETICALGRO_H_

#define MAXITERTIME 1
double P[FoodsNum] = {0.0}; // 存储每一个个体选择概率

/*!
 * 根据适应度值计算每一个食物源被选中的比例概率
 * @param foods 当前的食物源种群
 */
void calSelectionProb(Food *foods) {
    int totalFitness = 0;
    // 计算每一个个体的选择概率
    for (int i = 0; i < FoodsNum; ++i) {
        totalFitness += foods[i].getFitness();
    }
    for (int j = 0; j < FoodsNum; ++j) {
        P[j] += foods[j].getFitness() / (totalFitness * 1.0);
    }
}

/*!
 * 轮盘赌选择出一个食物源（通过累积概率）
 * @return 选择出的个体下标
 */
int RouletteWheelSelection() {
    // 轮盘选择
    double randProb = (rand() % 1000 + 1) / 1000.0; // 产生一个[0.001, 1]的随机概率
    cout << randProb << endl;
    double probabilityTotal = 0;
    int Selection = 0;
    for (int i = 0; i < FoodsNum; i++) // SIZE是个体数量的大小
    {
        probabilityTotal = probabilityTotal + P[i];
        if (probabilityTotal >= randProb) {
            Selection = i;
            break;
        }
    }

    return Selection;
}

/*!
 * 通过父代种群产生新的子代种群
 * @param foods
 */
void generateNewFoods(Food *foods) {
    Food newFoods[FoodsNum];
    int newFoodsLength = 0;

    while(newFoodsLength < FoodsNum) {
        // 选择两个不同的个体
        int selection1 = RouletteWheelSelection();
        int selection2 = selection1;
        while(selection2 == selection1) { // 确保选择的两个个体不同
            selection2 = RouletteWheelSelection();
        }
        cout << selection1 << ", " << selection2 << endl;

        // TODO: 两个个体的交叉逻辑
        cross(selection1, selection2);
    }




}

void geneticAgro() {

    CS_swap();//随机货位
    Food foods[FoodsNum]; // 生成食物源的初始种群

    for (int i = 0; i < MAXITERTIME; ++i) {
        enCode(foods); // 计算种群的适应度值

        calSelectionProb(foods);

        generateNewFoods(foods);
    }

}

#endif