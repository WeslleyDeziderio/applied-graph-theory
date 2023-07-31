#include "../../include/utils/Data.hpp"

//Inicializador
Data::Data(int qtParam, char * instance):

i(NULL),
j(NULL)
{
	instanceName = instance;
	paramsNumber = qtParam;
}

Data::~Data() {
	delete [] i;
	delete [] j;
}

void Data::readData() {
	std::ifstream inputData(instanceName, std::ios::in);

	if (!inputData) {
		std::cout << "File not found" << std::endl;
		exit(1);
	}
}