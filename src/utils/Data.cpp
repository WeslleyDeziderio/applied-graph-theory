#include "../../include/utils/Data.hpp"

Data::Data(int params, char* instance) {
    paramsNumber = params;
    instanceName = instance;
}

Data::~Data() {}

void Data::readData() {
	std::ifstream inputData(instanceName, std::ios::in);

	if (!inputData) {
		std::cout << "File not found!" << std::endl;
	}

    std::string line;

    while (std::getline(inputData, line)) {
        std::cout << line << std::endl;
    }

}

void Data::printAdjacencyMatrix() {

}

void Data::printAdjacencyList() {

}