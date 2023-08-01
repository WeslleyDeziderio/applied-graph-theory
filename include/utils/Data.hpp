#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

#define MAX (0x7FFFFFFF)

class Data {
private:
    int paramsNumber;
    int numVertices;
    std::string instanceName;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::list<std::list<int>> adjacencyList;
public:
    Data(int params, char* instance);

    void readData();
    void addEdge(int, int);
    void removeEdge(int, int);
	void printAdjacencyMatrix();
    void printAdjacencyList();
};

#endif // DATA_HPP