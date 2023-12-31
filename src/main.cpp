#include "../include/utils/Data.hpp"
#include <iostream>

int main(int argc, char **argv) {
  Data data(argc, argv[1]);
  std::string instanceName = data.getInstanceName();
  std::cout << "Reading: " << instanceName << std::endl;

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
  data.isUniversalVertex();
  data.isIsolatedVertex();
  data.isSubgraph();
  data.isWalk();
  data.isPath();
  /* data.isCycle(); */
  data.isTrail();
  data.isClique();
  data.isCliqueMaximal();
  data.generateComplement();
  data.isIndependentSet();

  return 0;
}
