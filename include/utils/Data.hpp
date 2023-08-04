#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

#define MAX (0x7FFFFFFF)
#define MIN -1
class Data {
protected:
    int paramsNumber;
    int numVertices;
    std::string instanceName;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::list<std::list<int>> adjacencyList;
    std::vector<int> degreeSequence;
    
public:
    Data(int params, char* instance);

    void readData();
    void addEdge(int, int);
    void removeEdge(int, int);
	void printAdjacencyMatrix();
    void printAdjacencyList();
    void computeMaxDegree();
    void computeMinDegree();
    void printDegreeSequence();
    int getNumVertices();
    void setNumVertices(int);
};

#endif // DATA_HPP