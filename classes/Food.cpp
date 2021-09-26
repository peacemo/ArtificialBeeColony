//
// Created by shikamaru on 2021/9/21.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <time.h>
#include <memory.h>
#include <string>
#include <random>
#include <functional>
#include <list>
// #include<windows.h>
#include<bits/stdc++.h>
#include "Food.h"

void randomArr(int G[],int len) {    // 对数组进行洗牌操作
    for(int i = 0; i < len; i++){
        int sit = rand()%(len-1) +1;//随机位置
        int temp =G[i];		//交换当前位置的编码和随机位置的编码
        G[i] = G[sit];
        G[sit] = temp;
    }
}

Food::Food() {
    this->sequence = new int[GoodsNum];
    this->seqLen = GoodsNum;
    this->fitness = -1;
    this->counts = 0;
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

void Food::stirSequence() {
    // 打乱序列元素
    int temSeq[GoodsNum] = {0};
    srand((double)clock());//设置随机种子

    for(int j = 0; j < GoodsNum; j++){
        temSeq[j] = j+1;
    }
    randomArr(temSeq, GoodsNum);
    for(int m = 0; m < GoodsNum; m++) {//写入到种群
        this->sequence[m] = temSeq[m];
    }

}

void Food::calFitness() {
    // 计算序列的适应度值
//    int target[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double fit = 0;
    for (int i = 0; i < GoodsNum; ++i) {
//        int a = this->seq[i];
        int a = this->sequence[i];
//        int b = target[i];
        fit += (double)(abs(a - (i+1)));
    }
    this->setFitness(fit);
}

void Food::removeFromSequence(int target) { // 从序列中删除一个元素
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

void Food::addIntoSequence(int target) { // 向序列的末尾添加一个元素
    if(seqLen == GoodsNum) return;
    this->seqLen++;
    this->sequence[GoodsNum - 1] = target;
}

void Food::updateCounts() {
    this->counts++;
}

std::ostream &operator<<(std::ostream &os, const Food &food) {
    std::string tempSeq = {};
    for (int i = 0; i < GoodsNum; ++i) {
        tempSeq += std::to_string(food.sequence[i]) + ", ";
    }
    os << "seq: " << tempSeq << "\tseqLen: " << food.seqLen << "\tfitness: " << food.fitness << "\tcounts: "
       << food.counts;
    return os;
}


