#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

#define MAX (0x7FFFFFFF)

class Data {
private:
    std::string instanceName;
    int paramsNumber;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::list<std::list<int>> adjacencyList;
public:
    Data(int params, char* instance);
    ~Data();

    void readData();
	void printAdjacencyMatrix();
    void printAdjacencyList();
};

#endif // DATA_HPP