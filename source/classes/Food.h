//
// Created by shikamaru on 2021/9/21.
//

#ifndef ABC_FOOD_H
#define ABC_FOOD_H

#include <ostream>
#include <vector>

class Food {
private:
    int *sequence;
    int seqLen;
    double fitness;
    int counts;
    double timeSpan;
    int fre;
public:

    virtual ~Food();

    Food();

    int *getSequenceAddress() const;

    int getSequence(int index) const;

    void setSequence(int index, int target);

    int getSeqLen() const;

    void setSeqLen(int seqLen);

    double getFitness() const;

    void setFitness(double fitness);

    int getCounts() const;

    void setCounts(int updateCounts);

    double getTimeSpan() const;

    void setTimeSpan(double timeSpan);

    void setFre(int fre);

    int getFre() const;

    friend std::ostream &operator<<(std::ostream &os, const Food &food);

    //user funcs
    void opt2();
    void stirSequence();
    void calFitness();
    void updateCounts();
    void removeFromSequence(int target);
    void addToEndOfSequence(int target);
    void addIntoSequence(int index, int target);

};


#endif //ABC_FOOD_H
