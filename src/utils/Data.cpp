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
    std::cout << "Number of vertices: " << numVertices << std::endl;
    adjacencyMatrix.assign(numVertices, std::vector<int>(numVertices, 0));

    for (int i = 0; i < this->numVertices; ++i) {
        for (int j = 0; j < this->numVertices; ++j) {
            inputData >> this->adjacencyMatrix[i][j];
        }
    }

    inputData.close();
    std::cout << "Data read successfully! \n" << std::endl;
}

std::string Data::getInstanceName() {
    return instanceName;
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
    std::cout << "Adjacency Matrix: \n";
    for (int i = 0; i < this->numVertices; ++i) {
        for (int j = 0; j < this->numVertices; ++j) {
            std::cout << this->adjacencyMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

std::list<std::list<int>> Data::getAdjacencyList() {
    for (int i = 0; i < numVertices; ++i) {
        std::list<int> neighbors;
        for (int j = 0; j < numVertices; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                neighbors.push_back(j+1);
            }
        }

        adjacencyList.push_back(neighbors);
    }

    return adjacencyList;
}

void Data::printAdjacencyList() {
    adjacencyList = getAdjacencyList();
    int vertex = 0;
    
    std::cout << "Adjacency List: \n";
    for (const auto& neighbors : adjacencyList) {
        std::cout << vertex+1 << " --> ";
        for (int neighbor : neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
        ++vertex;
    }
}

void Data::computeMaxDegree() {
    int maxDegree = MIN;

    for (int i = 0; i < this->numVertices; ++i) {
        int degree = 0;

        for (int j = 0; j < this->numVertices; ++j) {
            if (this->adjacencyMatrix[i][j] == 1) {
                ++degree;
            }
        }

        if (degree > maxDegree) {
            maxDegree = degree;
        }
    }

    std::cout << "\nGraph's maximum degree: " << maxDegree << std::endl;
}

void Data::computeMinDegree() {
    int minDegree = MAX;

    for (int i = 0; i < this->numVertices; ++i) {
        int degree = 0;

        for (int j = 0; j < this->numVertices; ++j) {
            if (this->adjacencyMatrix[i][j] == 1) {
                ++degree;
            }
        }

        if (degree < minDegree) {
            minDegree = degree;
        }
    }

    std::cout << "\nGraph's minimum degree: " << minDegree << std::endl;
}

std::vector<int> Data::printDegrees() {
    for (int i = 0; i < this->numVertices; ++i) {
        int numEdges = 0;
        for (int j = 0; j < this->numVertices; ++j) {
            if (this->adjacencyMatrix[i][j] == 1) {
                ++numEdges;
            }
        }
        degreesSequence.push_back(numEdges);
    }

    std::sort(degreesSequence.begin(), degreesSequence.end());

    return degreesSequence;
}

bool Data::isNeighbors() {
    std::cout << "\nWhat vertices do you want to verify?" << std::endl;

    int i;
    int j;
    std::cin >> i;
    std::cin >> j;

    for (int k = 0; k < this->numVertices; ++k) {
        if (this->adjacencyMatrix[i][j] == 1) {
            std::cout << i << " and " << j << " are neighbors." << std::endl;
            return true;
        }
    }
    
    std::cout << i << " and " << j << " are not neighbors." << std::endl;
    return false;
} 

void Data::determineDegreeOpenClosedNeighbor() {
    int vertex;
    int degree = 0;
    int i = 1;

    std::cout << "\nInsert the vertex: " << std::endl;
    std::cin >> vertex;

    for(auto it = this->adjacencyList.begin() ; it != this->adjacencyList.end() ; ++it){
        if (i == vertex) {
            std::cout << "Degree: " << it->size() << std::endl;
            std::cout << "Neighborhood: (";

            std::list<int>::iterator ptr = it->begin();

            for (int k = 0; k < (it->size()-1); ++k) {
                std::cout << *ptr << ", ";
                advance(ptr, 1);
            }
            std::cout << *ptr << ")\t [";

            ptr = it->begin();

            for (int k = 0; k < (it->size()-1); ++k) {
                if (k == vertex-1) {
                    std::cout << k+1 << ", ";
                }
                std::cout << *ptr << ", ";
                advance(ptr, 1);
             }
             std::cout << *ptr << "]\t" << std::endl;
        }
        
        i++;
    }
}

void Data::isRegular() {
    int degree = 0;
    int degreeAux = 0;

    for (int i = 0; i < this->numVertices; ++i) {
        for (int j = 0; j < this->numVertices; ++j) {
            if (this->adjacencyMatrix[i][j] == 1) {
                ++degree;
            }
        }

        if (degreeAux == 0) {
            degreeAux = degree;
        }

        if (degree != degreeAux) {
            std::cout << "\nGraph is not regular." << std::endl;
            return;
        }

        degree = 0;
    }

    std::cout << "\nGraph is regular." << std::endl;
    std::cout << "And his degree is: " << degreeAux << std::endl;
}

void Data::isComplete() {
    int maxEdges = (this->numVertices * (this->numVertices - 1)) / 2;
    int numEdges = 0;

    for (int i = 0; i < this->numVertices; ++i) {
        for (int j = 0; j < this->numVertices; ++j) {
            if (this->adjacencyMatrix[i][j] == 1) {
                ++numEdges;
            }
        }
    }

    if (numEdges == maxEdges) {
        std::cout << "\nThe given graph is complete." << std::endl;
    } else {
        std::cout << "\nThe given graph is not complete." << std::endl;
    }
}

void Data::isUniversalVertex() {
    for (int i = 0; i < this->adjacencyList.size(); ++i) {
        if (this->adjacencyList.size() == this->numVertices -1) {
            std::cout << "\nVertex " << i << " is universal." << std::endl;
        } else {
            std::cout << "Vertex " << i << " is not universal." << std::endl;
        }
    }
}

void Data::isIsolatedVertex() {
    for (int i = 0; i < this->adjacencyList.size(); ++i) {
        if (this->adjacencyList.size() == 0) {
            std::cout << "\nVertex " << i << " is isolated." << std::endl;
        } else {
            std::cout << "Vertex " << i << " is not isolated." << std::endl;
        }
    }
}

void Data::isWalk() {
    for (int i = 0; i < this->numVertices; ++i) {
        for (int j = 0; j < this->numVertices; ++j) {
            if (this->adjacencyMatrix[i][j] == 1) {
            }

        }

    }

}

void Data::isTrail() {}