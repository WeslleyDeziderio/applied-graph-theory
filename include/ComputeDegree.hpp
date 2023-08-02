#ifndef COMPUTEDEGREE_HPP
#define COMPUTEDEGREE_HPP

#include "../include/utils/Data.hpp"

class ComputeDegree : public Data {
public:
    ComputeDegree();

    void computeMaxDegree();
    void computeMinDegree();
};

#endif // COMPUTEDEGREE_HPP