#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <fstream>

class Data {
private:
    std::string instanceName;
    int paramsNumber;
    int *i;
    int *j;
public:
    Data(int, char*);
    ~Data();

    void readData();
	void printMatrixDist();
};

#endif // DATA_HPP