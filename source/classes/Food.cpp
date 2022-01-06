//
// Created by shikamaru on 2021/9/21.
//
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <string>
#include <list>
#include "Food.h"
#include "../headers/Constants.h"

void randomIndex(int G[],int len) { // 对数组进行洗牌操作
    // 打乱序列元素
    srand((double)clock());//设置随机种子
    for(int i = 0; i < len; i++){
        int sit = rand()%(len-1) +1; // 产生一个随机位置
        int temp =G[i];	// 交换当前位置的编码和随机位置的编码
        G[i] = G[sit];
        G[sit] = temp;
    }
}

void Food::opt2() {
//    std::cout << "2-opt called" << std::endl;
    srand((unsigned)time(NULL));
    int start, end;
    start = rand()%( (GoodsNum - GoodsNum / 3) - 0 + 1) + 0; // 起始位置[0, (GoodsNum - GoodsNum / 3)]
    end = start + (GoodsNum/3);
    for(int i = start, j = end - 1; i < j; i++, j--) {
        int t = this->getSequenceAddress()[i];
        this->getSequenceAddress()[i] = this->getSequenceAddress()[j];
        this->getSequenceAddress()[j] = t;
    }
}

Food::Food() {
    // todo leak
    this->sequence = new int[GoodsNum];
    this->seqLen = GoodsNum;
    this->fitness = -1;
    this->counts = 0;
    this->timeSpan = 0;
    this->fre = rand()%( 20 - 5 + 1) + 5;
    this->stirSequence();
    this->calFitness();
}

int Food::getSequence(int index) const {
    if(index >= this->seqLen) return -1;
    return sequence[index];
}

void Food::setSequence(int index, int target) {
    if(index >= this->seqLen || index < 0) return;
    this->sequence[index] = target;
}

int Food::getSeqLen() const {
    return seqLen;
}

void Food::setSeqLen(int seqLen) {
    Food::seqLen = seqLen;
}

double Food::getFitness() const {
    return fitness;
}

void Food::setFitness(double fitness) {
    Food::fitness = fitness;
}

int Food::getCounts() const {
    return counts;
}

void Food::setCounts(int counts) {
    Food::counts = counts;
}

double Food::getTimeSpan() const {
    return timeSpan;
}

void Food::setTimeSpan(double timeSpan) {
    Food::timeSpan = timeSpan;
}

int Food::getFre() const {
    return fre;
}

void Food::setFre(int fre) {
    Food::fre = fre;
}

/*!
 * 打乱数组中的元素
 */
void Food::stirSequence() {

    for(int j = 0; j < GoodsNum; j++){ // 初始化货物 1~GoodsNum
        this->sequence[j] = j+1;
    }
    randomIndex(this->getSequenceAddress(), GoodsNum); // 将货物序列打乱

}

/*!
 * 计算序列的适应度值
 */
void Food::calFitness() {
    double fit = 0;
    for (int i = 0; i < GoodsNum; ++i) {
        fit += (double)(abs(this->sequence[i] - (i+1)));
    }
    this->setFitness(fit);
}

/*!
 * 从序列中删除指定的元素
 * @param target 需要删除的元素的值
 */
void Food::removeFromSequence(int target) {
    if(seqLen <= 0) return;
    for (int i = 0; i < this->seqLen; ++i) {
        if (this->sequence[i] == target) {
            for (int j = i; j < this->seqLen; ++j) {
                this->sequence[j] = this->sequence[j+1];
            }
            this->seqLen = this->seqLen - 1;
            return;
        }
    }
    return;

}

/*!
 * 向序列的末尾添加一个元素
 * @param target 待添加元素的值
 */
void Food::addToEndOfSequence(int target) {
    if(seqLen == GoodsNum) return;
    this->sequence[GoodsNum - 1] = target;
    this->seqLen++;
}

void Food::updateCounts() {
    this->counts++;
}

/*!
 * 重载 ‘<<’ 用算符，格式化输出对象
 * @param os
 * @param food
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Food &food) {
    std::string tempSeq = {};
    for (int i = 0; i < GoodsNum; ++i) {
        if (i == 0) {
            tempSeq += "[" +std::to_string(food.sequence[i]) + ", ";
        } else if (i == GoodsNum - 1) {
            tempSeq += std::to_string(food.sequence[i]) + "]";
        } else {
            tempSeq += std::to_string(food.sequence[i]) + ", ";
        }
    }
    os << "seq: " << tempSeq << "\tseqLen: " << food.seqLen << "\tfitness: " << food.fitness << "\tcounts: "
       << food.counts << "\ttime: " << food.timeSpan << "\tfre: " << food.fre;
    return os;
}

/*!
 * 获取序列（数组）的地址
 * @return 返回数组首个元素的位置，
 */
int *Food::getSequenceAddress() const {
    return sequence;
}

/*!
 * 将一个数插入数组的对应位置
 * @param index 插入的位置的下标
 * @param target 插入的值
 */
void Food::addIntoSequence(int index, int target) {
    if (this->seqLen == GoodsNum) return;
    for (int i = (this->seqLen -1); i >= index; i--) {
        this->sequence[i+1] = this->sequence[i];
    }
    this->sequence[index] = target;
    this->seqLen++;
}

Food::~Food() {

}




