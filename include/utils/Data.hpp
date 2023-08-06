#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

#define MAX (0x7FFFFFFF)
#define MIN -1
class Data {
protected:
    int paramsNumber;
    int numVertices;
    std::string instanceName;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::list<std::list<int>> adjacencyList;
    std::vector<int> degreesSequence;

public:
    Data(int params, char* instance);

    void readData();
    std::string getInstanceName();
    void addEdge(int, int);
    void removeEdge(int, int);
    std::list<std::list<int>> getAdjacencyList();
	void printAdjacencyMatrix();
    void printAdjacencyList();
    void computeMaxDegree();
    void computeMinDegree();
    std::vector<int> printDegrees();
    void determineDegreeOpenClosedNeighbor();
    bool isNeighbors();
    void isRegular();
    void isComplete();
    void isUniversalVertex();
    void isIsolatedVertex();
    void isSubgraph(); // TODO
    void isWalk(); // TO FIX
    void isTrail();
};

#endif // DATA_HPP