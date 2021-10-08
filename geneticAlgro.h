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

Food* cross(int f1, int f2, Food *foods) {
    Food tempFood;
    Food childrenFoods[2];

    fdcpy(foods[f1], childrenFoods[0]); // 将父代的两个食物源先赋值给临时变量，杂交的时候对临时变量进行操作
    fdcpy(foods[f2], childrenFoods[1]);

    fdcpy(foods[f1], tempFood);  // 临时保存 f1，用于变量交换的中间变量

    int randIndex = rand() % ((GoodsNum - GoodsNum / 3) - 0 + 1) + 0; // 随机选取交叉序列的起始位置[0, (GoodsNum - GoodsNum / 3)]

    // 首先将 f2 的相应序列给到 f1
    for (int iter = randIndex; iter < randIndex + (GoodsNum / 3); ++iter) { // 取出从随机位置开始，向后至“总数的三分之一”个元素
        /**
         *  全部迭代完后的效果就是
         *  从 food2 中选取一段序列
         *  从 food1 中删除掉这些序列中的值
         *  再将这些值拼接到 food1 的末尾
         * */
        int currentElement = childrenFoods[1].getSequence(iter);
        childrenFoods[0].removeFromSequence(currentElement); // (CODE_LENTH^2) 从自身的序列中删除交叉对象的该元素
//        tempFood.addToEndOfSequence(currentElement); // 再将其置于序列的末尾
        childrenFoods[0].addIntoSequence(iter, currentElement); // 再将其置于序列的相应位置
    }
    enSimpleCode(childrenFoods[0]);

    // 再将 temp( f1的值 )的相应序列给到 f2
    for (int iter = randIndex; iter < randIndex + (GoodsNum / 3); ++iter) { // 取出从随机位置开始，向后至“总数的三分之一”个元素
        /**
         *  全部迭代完后的效果就是
         *  从 food2 中选取一段序列
         *  从 food1 中删除掉这些序列中的值
         *  再将这些值拼接到 food1 的末尾
         * */
        int currentElement = tempFood.getSequence(iter);
        childrenFoods[1].removeFromSequence(currentElement); // (CODE_LENTH^2) 从自身的序列中删除交叉对象的该元素
//        tempFood.addToEndOfSequence(currentElement); // 再将其置于序列的末尾
        childrenFoods[1].addIntoSequence(iter, currentElement); // 再将其置于序列的相应位置
    }
    enSimpleCode(childrenFoods[1]);

    return childrenFoods;

}

/*!
 * 通过父代种群产生新的子代种群
 * @param foods
 */
void generateNewFoods(Food *foods) {
    Food newFoods[FoodsNum];
    int newFoodsLength = 0;

    while(newFoodsLength < FoodsNum) {  // 在子代规模达到种群大小之前，不断地产生新的子代，并添加进入子代集
        // 选择两个不同的个体
        int selection1 = RouletteWheelSelection();
        int selection2 = selection1;
        while(selection2 == selection1) { // 确保选择的两个个体不同
            selection2 = RouletteWheelSelection();
        }
        cout << selection1 << ", " << selection2 << endl;
        // TODO: 两个个体的交叉逻辑
        Food *children = cross(selection1, selection2, foods);
        newFoods[newFoodsLength] = children[0];
        newFoodsLength++;
        newFoods[newFoodsLength] = children[1];
        newFoodsLength++;

    }

    // TODO: 变异逻辑



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