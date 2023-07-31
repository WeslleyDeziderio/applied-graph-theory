#include <iostream>
#include "../include/utils/Data.hpp"

int main(int argc, char** argv) {
    Data *data = new Data(argc, argv[1]);
    data->readData();
    
    return 0;
}