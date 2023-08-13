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

std::vector<std::vector<int>> Data::getAdjacencyComplementMatrix() {
    return adjacencyComplementMatrix;
}

void Data::addEdge(int i, int j) {
    this->adjacencyMatrix[i][j] = 1;
    this->adjacencyMatrix[j][i] = 1;
}

void Data::removeEdge(int i, int j) {
    this->adjacencyMatrix[i][j] = 0;
    this->adjacencyMatrix[j][i] = 0;
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

void Data::isNeighbors() {
    int i;
    int j;
    std::cout << "\nWhat vertices do you want to verify adjacency?" << std::endl;
    std::cin >> i;
    std::cin >> j;

    if (this->adjacencyMatrix[i][j] == 1) {
        std::cout << i << " and " << j << " are neighbors." << std::endl;
        return;
    }
    
    std::cout << i << " and " << j << " are not neighbors." << std::endl;
} 

bool Data::isAdjacency(int i, int j) {
    if (this->adjacencyMatrix[i][j] == 1) {
        return true;
    }
    
    return false;
} 

bool Data::isAdjacencyComplement(int i, int j) {
    if (this->adjacencyComplementMatrix[i][j] == 1) {
        return true;
    }
    
    return false;
} 

void Data::determineDegreeOpenClosedNeighbor() {
    int vertex;
    int degree = 0;
    int i = 1;

    std::cout << "\nInsert the vertex to verify open closed adjacency: " << std::endl;
    std::cin >> vertex;

    for (auto it = this->adjacencyList.begin(); it != this->adjacencyList.end(); ++it) {
        if (i == vertex) {
            std::cout << "Degree: " << it->size() << std::endl;
            std::cout << "Open neighborhood: (";

            std::list<int>::iterator ptr = it->begin();

            for (int k = 0; k < (it->size()-1); ++k) {
                std::cout << *ptr << ", ";
                advance(ptr, 1);
            }
            std::cout << *ptr << ")\t Closed neighborhood: [";

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

    for (int i = 0; i < this->numVertices; i++) {
        for (int j = 0; j < this->numVertices; j++) {
            if (this->adjacencyMatrix[i][j] == 1) {
                ++numEdges;
            }
        }
    }

    std::string ans = numEdges/2 == maxEdges ? "\nThe given graph is complete.\n" : "\nThe given graph is not complete.\n";
    std::cout << ans;
}

void Data::isUniversalVertex() {
    int i = 1;

    for (auto it = this->adjacencyList.begin(); it != this->adjacencyList.end(); ++it) {
        if (it->size() == this->numVertices-1) {
            std::cout << "\nVertex " << i << " is universal.";
        } else {
            std::cout << "\nVertex " << i << " is not universal.";
        }
        i++;
    }
}

void Data::isIsolatedVertex() {
    int i = 1;

    for (auto it = this->adjacencyList.begin(); it != this->adjacencyList.end(); ++it) {
        if (it->size() == 0) {
            std::cout << "\nVertex " << i << " is isolated.";
        } else {
            std::cout << "\nVertex " << i << " is not isolated.";
        }
        i++;
    }
}

void Data::isSubgraph() {
    int verticesSequenceSize;
    int vertexToInsert;
    std::list<int> verticesList;
    int numSublists;
    int edgesSequenceSize;
    std::list<std::list<int>> edgesList;

    std::cout << "\nSubgraph" << std::endl;
    std::cout << "Insert the length of the sequence of vertices: ";
    std::cin >> verticesSequenceSize;

    std::cout << "\nInsert the length of the sequence of edges: ";
    std::cin >> numSublists;

    for (int i = 1; i <= verticesSequenceSize; ++i) {
        std::cout << "Insert the vertex " << i << ": ";
        std::cin >> vertexToInsert;
        verticesList.push_back(vertexToInsert-1);
    }

    for (int j = 0; j < numSublists; ++j) {
        int sublistSize;
        std::cout << "Insert the size of sublist " << j+1 << ": ";
        std::cin >> sublistSize;
       
        std::list<int> sublist;

        std::cout << "Enter " << sublistSize << " values for sublist " << j+1 << ", ";
        for (int k = 1; k <= sublistSize; ++k) {
            std::cout << "insert the value " << k << ": ";
            int value;
            std::cin >> value;
            sublist.push_back(value-1);
        }

        edgesList.push_back(sublist);

    }

     for (const std::list<int>& innerList : edgesList) {
        for (int value : innerList) {
            std::cout << value+1 << " ";
        }
        std::cout << std::endl;
     }

     for (std::list<int> edge : edgesList) {
        if (edge.size() != 2) {
            std::cout << "\nThe given sequence does not form a valid edge!" << std::endl;
            return;
        }

        if (std::find(verticesList.begin(), verticesList.end(), edge.front()) == verticesList.end() ||
            std::find(verticesList.begin(), verticesList.end(), edge.back()) == verticesList.end()) {
            std::cout << "\nThe given sequence contains vertices not present in the vertex list!" << std::endl;
            return;
        }
    }

    std::cout << "\nThe given sequence forms a valid subgraph!" << std::endl;
}

void Data::isWalk() {
    int walkListSize;
    int vertexToInsert;
    std::vector<int> walkSequence;

    std::cout << "\n\nInsert the lenght of the list of vertices to determine if forms a walk: ";
    std::cin >> walkListSize;

    for (int i = 1; i <= walkListSize; ++i) {
        std::cout << "\nInsert the vertex " << i << ": ";
        std::cin >> vertexToInsert;
        walkSequence.push_back(vertexToInsert-1);
    }

    for (int i = 0; i < walkListSize-1; ++i) {
        if (this->adjacencyMatrix[walkSequence[i]][walkSequence[i+1]] != 1) {
            std::cout << "\nThe given sequence does not form a walk." << std::endl;
            return;
        }
    }
    std::cout << "\nThe given sequence form a walk!" << std::endl;
}

void Data::isPath() {
    int pathSize;
    int vertexToInsert;
    std::vector<int> pathSequence;
    std::vector<bool> vertexUsed(this->adjacencyMatrix.size(), false);
    std::cout << "\nInsert the sequence of vertices to determine if forms a path: ";
    std::cin >> pathSize;

    for (int i = 1; i <= pathSize; ++i) {
        std::cout << "Insert the vertex " << i << ": ";
        std::cin >> vertexToInsert;
        pathSequence.push_back(vertexToInsert-1);
    }

    for (int i = 0; i < pathSize-1; ++i) {
        if (i > 0 && !this->adjacencyMatrix[pathSequence[i-1]][pathSequence[i]]) {
            std::cout << "\nThe given sequence does not form a path!" << std::endl;
            return;
        }

        if (vertexUsed[pathSequence[i]]) {
            std::cout << "\nThe given sequence does not form a path! Repeated vertex!" << std::endl;
            return;
        }

        vertexUsed[pathSequence[i]] = true;
    }

    std::cout << "\nThe given sequence form a path!" << std::endl;
}

void Data::isCycle() {
    int cycleSize;
    int vertexToInsert;
    std::vector<int> cycleSequence;

    std::cout << "\nInsert the sequence of vertices to determine if forms a cycle: ";
    std::cin >> cycleSize;

    for (int i = 1; i <= cycleSize; ++i) {
        std::cout << "Insert the vertex " << i << ": ";
        std::cin >> vertexToInsert;

        if (i > 1 && i < cycleSize && std::find(cycleSequence.begin(), cycleSequence.end(), vertexToInsert) != cycleSequence.end()) {
            std::cout << "\nRepeated vertex found! The sequence does not form a cycle." << std::endl;
            return;
        }
        cycleSequence.push_back(vertexToInsert-1);
    }

    std::cout << "\nThe given sequence forms a cycle." << std::endl;
}

void Data::isTrail() {
    int trailSize;
    int vertexToInsert;
    std::vector<int> trailSequence;
    std::cout << "\nInsert the sequence of vertices to determine if forms a trail: ";
    std::cin >> trailSize;

    if (vertexToInsert <= 0) {
        return;
    }

    for (int i = 1; i <= trailSize; ++i) {
        std::cout << "Insert the vertex " << i << ": ";
        std::cin >> vertexToInsert;
        trailSequence.push_back(vertexToInsert-1);
    }

    for (int i = 0; i < trailSize-1; ++i) {
        if (this->adjacencyMatrix[trailSequence[i]][trailSequence[i+1]] != 1) {
            std::cout << "\nThe given sequence does not form a trail!" << std::endl;
            return;
        }
    }

    std::vector<bool> visited(numVertices, false);

    for (int i = 0; i < trailSequence.size(); ++i) {        
        if (visited[trailSequence[i]]) {
            std::cout << "\nThe given sequence does not form a trail!" << std::endl;
            return;
        }

        visited[trailSequence[i]] = true;
    }
    
    std::cout << "\nThe given sequence form a trail!" << std::endl;
}

bool Data::isClique() {
    int cliqueSize;
    int vertexToInsert;
    std::vector<int> cliqueSequence;

    std::cout << "\nInsert the length of the sequence of edges to verify if is clique: ";
    std::cin >> cliqueSize;

    for (int i = 1; i <= cliqueSize; ++i) {
        std::cout << "Insert the vertex " << i << ": ";
        std::cin >> vertexToInsert;
        cliqueSequence.push_back(vertexToInsert-1);
    }

    for (int i = 0; i < cliqueSequence.size(); i++) {
        for (int j = i+1; j < cliqueSequence.size(); j++) {
            if (!isAdjacency(cliqueSequence[i], cliqueSequence[j])) {
                std::cout << "\nThe given sequence does not form a clique!" << std::endl;
                return false;
            }
        }
    }

    std::cout << "\nThe given sequence form a clique!" << std::endl;
    return true;
}


bool Data::isCliqueComplement() {
    int cliqueSize;
    int vertexToInsert;
    std::vector<int> cliqueSequence;

    std::cout << "\nInsert the length of the sequence of edges to verify if is clique: ";
    std::cin >> cliqueSize;

    for (int i = 1; i <= cliqueSize; ++i) {
        std::cout << "Insert the vertex " << i << ": ";
        std::cin >> vertexToInsert;
        cliqueSequence.push_back(vertexToInsert-1);
    }

    for (int i = 0; i < cliqueSequence.size(); i++) {
        for (int j = i+1; j < cliqueSequence.size(); j++) {
            if (!isAdjacencyComplement(cliqueSequence[i], cliqueSequence[j])) {
                std::cout << "\nThe given sequence does not form a clique!" << std::endl;
                return false;
            }
        }
    }

    std::cout << "\nThe given sequence form a clique!" << std::endl;
    return true;
}

void Data::isCliqueMaximal() {
    int cliqueSize;
    int vertexToInsert;
    std::vector<int> cliqueSequence;

    std::cout << "\nInsert the length of the sequence of edges to verify if is clique maximal: ";
    std::cin >> cliqueSize;

    for (int i = 1; i <= cliqueSize; ++i) {
        std::cout << "Insert the vertex " << i << ": ";
        std::cin >> vertexToInsert;
        cliqueSequence.push_back(vertexToInsert-1);
    }

    bool flag;

    for (int count = 0; count <= this->numVertices; ++count) {
        if (!(std::find(cliqueSequence.begin(), cliqueSequence.end(), count) != cliqueSequence.end())) {
            cliqueSequence.push_back(count);
            for (int i = 0; i < cliqueSequence.size(); i++) {
                flag = false;
                for (int j = i+1; j < cliqueSequence.size(); j++) {
                    if (!isAdjacency(cliqueSequence[i], cliqueSequence[j])) {
                        flag = true;
                        break;
                    }
                }
                
                if (flag) {
                    break;
                }

                if (i == cliqueSequence.size()-1) {
                    std::cout << "\nThe given sequence does not form a maximum clique!" << std::endl;
                    return;
                }
            } 
            cliqueSequence.pop_back();
        }
    }

    std::cout << "\nThe given sequence form a maximum clique!" << std::endl;
}

void Data::generateComplement() {
    std::cout << "\nOriginal graph" << std::endl;
    this->printAdjacencyMatrix();

    std::cout << "\nComplement:" << std::endl;
    this->adjacencyComplementMatrix.assign(numVertices, std::vector<int>(numVertices, 0));
    for (int i = 0; i < this->numVertices; ++i) {
        for (int j = 0; j < this->numVertices; ++j) {
            if (this->adjacencyMatrix[i][j] == 1) {
                this->adjacencyComplementMatrix[i][j] = 0;
                this->adjacencyComplementMatrix[j][i] = 0;
            }
             else if (i != j) {
                this->adjacencyComplementMatrix[i][j] = 1;
                this->adjacencyComplementMatrix[j][i] = 1;
            }
        }
    }

    for (int k = 0; k < this->numVertices; ++k) {
        for (int l = 0; l < this->numVertices; ++l) {
            std::cout << this->adjacencyComplementMatrix[k][l] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Data::isIndependentSet() {
    std::cout << "\nIndependent set" << std::endl;
    if (isCliqueComplement()) {
        std::cout << "\nThe given sequence form an independent set!" << std::endl;
        return;
    }

    std::cout << "\nThe given sequence  form an independent set!" << std::endl;
}