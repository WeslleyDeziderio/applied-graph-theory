#include "../include/ComputeDegree.hpp"

ComputeDegree::ComputeDegree() : Data (2, nullptr){}

void ComputeDegree::computeMaxDegree() {
    int maxDegree = -1;

    for (int i = 0; i < this->getNumVertices(); ++i) {
        int degree = 0;

        for (int j = 0; j < this->getNumVertices(); ++j) {
            if (this->adjacencyMatrix[i][j] == 1) {
                ++degree;
            }
        }

        if (degree > maxDegree) {
            maxDegree = degree;
        }
    }

    std::cout << "Maximum degree: " << maxDegree << std::endl;
}

void ComputeDegree::computeMinDegree() {
    int minDegree = MAX;

    for (int i = 0; i < this->getNumVertices(); ++i) {
        int degree = 0;

        for (int j = 0; j < this->getNumVertices(); ++j) {
            if (this->adjacencyMatrix[i][j] == 1) {
                ++degree;
            }
        }

        if (degree < minDegree) {
            minDegree = degree;
        }
    }

    std::cout << "Minimum degree: " << minDegree << std::endl;
}