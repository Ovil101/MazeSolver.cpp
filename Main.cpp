#include <iostream>
#include <vector>
#include "headers/Converter.h"
#include "headers/Solver.h" // Node.h is included in this header

int main(int argc, char *argv[]){
    if (argc == 1){ // check if exe is only argument
        std::cout << "FATAL: Image path must be specified" << std::endl;
    }
    else{
        std::string path = argv[1];
        Converter convert(path); // convert image to something Solver can use

        std::vector<std::vector<Node>> nodes = convert.to2Darray();

        for (std::vector<Node> row : nodes){
            for (Node node : row){
                std::cout << node.getRow() << " " << node.getCol() << std::endl;
            }
            std::cout << std::endl;
        }

        Solver solve();
    }
}