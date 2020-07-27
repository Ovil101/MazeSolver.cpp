#include <iostream>
#include "headers/Converter.h"
#include "headers/Node.h"

int main(int argc, char *argv[]){
    
    if (argc == 1){ // check if exe is only argument
        std::cout << "FATAL: Image path must be specified" << std::endl;
    }
    else{
        std::string path = argv[1];
        Converter convert(path);
    }
}