#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <unordered_set>

#define MAX (0x7FFFFFFF)
#define MIN -1
class Data {
protected:
    int paramsNumber;
    int numVertices;
    std::string instanceName;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<std::vector<int>> adjacencyComplementMatrix;
    std::list<std::list<int>> adjacencyList;
    std::vector<int> degreesSequence;

public:
    Data(int params, char* instance);

    void readData();
    std::string getInstanceName();
    std::vector<std::vector<int>> getAdjacencyComplementMatrix();
    void addEdge(int, int);
    void removeEdge(int, int);
    std::list<std::list<int>> getAdjacencyList();
	void printAdjacencyMatrix();
    void printAdjacencyList();
    void computeMaxDegree();
    void computeMinDegree();
    std::vector<int> printDegrees();
    void determineDegreeOpenClosedNeighbor();
    bool isAdjacency(int, int);
    void isNeighbors();
    void isRegular();
    void isComplete();
    void isUniversalVertex();
    void isIsolatedVertex();
    void isSubgraph();
    void isWalk();
    void isPath();
    void isCycle();
    void isTrail();
    bool isClique();
    void isCliqueMaximal(); // TODO
    void generateComplement();
    void isIndependentSet(); // TODO
};

#endif // DATA_HPP