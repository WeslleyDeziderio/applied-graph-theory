#include "../../include/utils/Data.hpp"

Data::Data(int params, char* instance) {
    if (params != 2) {
        std::cerr << "ERROR: Missing parameters!" << std::endl;
        std::cout << "Usage: ./concepts <Instance>" << std::endl;
        exit(1);
    }

    instanceName = instance;
    numVertices = 0;
}

void Data::readData() {
	std::ifstream inputData(instanceName, std::ios::in);

	if (!inputData) {
		std::cerr << "ERROR: File not found!" << std::endl;
        exit(1);
	}

    inputData >> numVertices;
    adjacencyMatrix.assign(numVertices, std::vector<int>(numVertices, 0));

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            inputData >> adjacencyMatrix[i][j];
        }
    }

    inputData.close();
    std::cout << "Data read successfully!" << std::endl;
}

void Data::addEdge(int i, int j) {
    adjacencyMatrix[i][j] = 1;
    adjacencyMatrix[j][i] = 1;
}

void Data::removeEdge(int i, int j) {
    adjacencyMatrix[i][j] = 0;
    adjacencyMatrix[j][i] = 0;
}

void Data::printAdjacencyMatrix() {    
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

void Data::printAdjacencyList() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << " --> ";
        for (int j = 0; j < numVertices; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                std::cout << j << " ";
            }
        }
        std::cout << "\n";
    }

}