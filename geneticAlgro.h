#ifndef _GENETICALGRO_H_
#define _GENETICALGRO_H_

void geneticAgro() {

    CS_swap();//随机货位
    Food foods[FoodsNum]; // 生成食物源的初始种群
    enCode(foods); // 计算种群的适应度值

    for (int i = 0; i < FoodsNum; ++i) {
        cout << foods[i] << endl;
    }

}

#endif