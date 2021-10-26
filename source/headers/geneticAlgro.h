#ifndef _GENETICALGRO_H_
#define _GENETICALGRO_H_

//#define MAXITERTIME 500
#define ENDPOINT 1000

double P[FoodsNum] = {0.0}; // 存储每一个个体选择概率
Food bestFood; // 所有世代中表现最优的食物源
Food crossFood;

/*!
 * 根据适应度值计算每一个食物源被选中的比例概率
 * @param foods 当前的食物源种群
 */
void calSelectionProb(Food *foods) {
    normalization(P, foods);
}

/*!
 * 轮盘赌选择出一个食物源（通过累积概率）
 * @return 选择出的个体下标
 */
int RouletteWheelSelection() {
    // 轮盘选择
    double randProb = (rand() % 1000 + 1) / 1000.0; // 产生一个[0.001, 1]的随机概率
//    cout << randProb << endl;
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
 * 两个食物源的杂交操作：
 * 1. 选择一个杂交长度 L，本函数中表现是 GoodsNum / 50
 * 2. 随机选择一个序列的起始位置 randIndex，则需要杂交的序列片段在食物源中的位置就是 [randeIndex, randIndex + L]
 * 3. 将第一个食物源与第二个食物源的杂交片段交换（过程中需要去除掉杂交之后的重复值），产生两个新的食物源
 * @param f1 第一个食物源在所有的食物源中的位置
 * @param f2 第二个食物源在所有的食物源中的位置
 * @param foods
 * @return
 */
Food* cross(int f1, int f2, Food *foods) {
//    Food childrenFoods[2];
    Food* childrenFoods = new Food[2];

    fdcpy(foods[f1], childrenFoods[0]); // 将父代的两个食物源先赋值给临时变量，杂交的时候对临时变量进行操作
    fdcpy(foods[f2], childrenFoods[1]);

    fdcpy(foods[f1], crossFood);  // 临时保存 f1，用于变量交换的中间变量

    int randIndex = rand() % ((GoodsNum - GoodsNum / 50) - 0 + 1) + 0; // 随机选取交叉序列的起始位置[0, (GoodsNum - GoodsNum / 3)]
    int endIndex = randIndex + (GoodsNum / 50);

    // 首先将 f2 的相应序列给到 f1
    for (int iter = randIndex; iter < endIndex; ++iter) { // 取出从随机位置开始，向后至“总数的三分之一”个元素
        int currentElement = childrenFoods[1].getSequence(iter);
        childrenFoods[0].removeFromSequence(currentElement); // (CODE_LENTH^2) 从自身的序列中删除交叉对象的该元素
//        hybridFood.addToEndOfSequence(currentElement); // 再将其置于序列的末尾
        childrenFoods[0].addIntoSequence(iter, currentElement); // 再将其置于序列的相应位置
    }
    enSimpleCode(childrenFoods[0]); // 计算新食物的适应度值
    if (childrenFoods[0].getFitness() > foods[f1].getFitness()) { // 只保留适应度好的那一个
        fdcpy(foods[f1], childrenFoods[0]);
    }

    // 再将 temp( f1的值 )的相应序列给到 f2，与上面过程相同
    for (int iter = randIndex; iter < endIndex; ++iter) { // 取出从随机位置开始，向后至“总数的三分之一”个元素
        int currentElement = crossFood.getSequence(iter);
        childrenFoods[1].removeFromSequence(currentElement); // (CODE_LENTH^2) 从自身的序列中删除交叉对象的该元素
//        hybridFood.addToEndOfSequence(currentElement); // 再将其置于序列的末尾
        childrenFoods[1].addIntoSequence(iter, currentElement); // 再将其置于序列的相应位置
    }
    enSimpleCode(childrenFoods[1]);
    if (childrenFoods[1].getFitness() > foods[f2].getFitness()) {
        fdcpy(foods[f2], childrenFoods[1]);
    }

    return childrenFoods;

}

/*!
 * 交换数组中的两个下标对应的值
 * @param indexA 下标 1
 * @param indexB 下标 2
 * @param food
 */
void swap(int indexA, int indexB, Food &food) {
    int temp = food.getSequence(indexA);
    food.setSequence(indexA, food.getSequence(indexB));
    food.setSequence(indexB, temp);

}

/*!
 * 通过父代种群产生新的子代种群
 * @param foods
 */
void generateNewFoods(Food *foods) {
//    Food newFoods[FoodsNum];
    Food *newFoods = new Food[FoodsNum];
    int newFoodsLength = 0;

    while(newFoodsLength < FoodsNum) {  // 在子代规模达到种群大小之前，不断地产生新的子代，并添加进入子代集
        // 选择两个不同的个体
        int selection1 = RouletteWheelSelection();
        int selection2 = selection1;
        while(selection2 == selection1) { // 确保选择的两个个体不同
            selection2 = RouletteWheelSelection();
        }
//        cout << selection1 << ", " << selection2 << endl;
        // TODO: 两个个体的交叉逻辑
        Food *children = cross(selection1, selection2, foods);
        newFoods[newFoodsLength] = children[0];
        newFoodsLength++;
        newFoods[newFoodsLength] = children[1];
        newFoodsLength++;

        delete[] children;

    }

    // TODO: 变异逻辑 -> 随机选择一些货物进行调换
    for (int i = 0; i < FoodsNum; ++i) {
        double randProb = (rand()%1000 + 1) / 1000.0; // 产生一个[0.001, 1]的随机概率
        double variationProb = 0.3;
        if (randProb < variationProb) {
            for (int j = 0; j < (FoodsNum / 5); ++j) {
                int rdFdIndexA = rand()%( (FoodsNum - 1) - 0 + 1) + 0; // [0, FoodsNum-1]
                int rdFdIndexB = rand()%( (FoodsNum - 1) - 0 + 1) + 0; // [0, FoodsNum-1]
                swap(rdFdIndexA, rdFdIndexB, newFoods[i]);
            }
            enSimpleCode(newFoods[i]);
        }
    }

    // 用子代替换父代
    for (int i = 0; i < FoodsNum; ++i) {
        foods[i] = newFoods[i];
        if (newFoods[i].getFitness() < bestFood.getFitness()) { // 顺便寻找最佳的食物源
            fdcpy(newFoods[i], bestFood);
        }
    }
    bestFood.updateCounts();

    delete[] newFoods;

}

void geneticAgro() {

//    CS_swap();//随机货位
    Food foods[FoodsNum]; // 生成食物源的初始种群
    enCode(foods); // 计算种群的适应度值
    fdcpy(foods[0], bestFood);
    vector<int> fitnessGrid;

    for (int i = 0; i < MAXITERTIME; ++i) {
        enCode(foods); // 计算种群的适应度值

        calSelectionProb(foods);

        generateNewFoods(foods);


        fitnessGrid.push_back(bestFood.getFitness());
        std::cout << "Gen " << i + 1 << ": ";
        std::cout << fitnessGrid.back() << std::endl;
        if (bestFood.getCounts() >= ENDPOINT) break;
    }
    std::cout << bestFood << std::endl;

}

#endif