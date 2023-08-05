#include <iostream>
#include "../include/utils/Data.hpp"

int main(int argc, char** argv) {
    Data data(argc, argv[1]);

    data.readData();
    data.printAdjacencyMatrix();
    data.printAdjacencyList();
    data.computeMaxDegree();
    data.computeMinDegree();

    std::vector<int> degreeSequence = data.printDegrees();

    std::cout << "Degree sequence: ";
    for (int degree : degreeSequence) {
        std::cout << degree << " ";
    }
    std::cout << std::endl;

    data.isNeighbors();
    data.determineDegreeOpenClosedNeighbor();
    data.isRegular();
    data.isComplete();

    return 0;
}