/*
Converting image->node[] and node[]->image
*/ 
#include "headers/Converter.h"
#include <vector>
// can't use using namespace cv becuase cv has a Node object

Converter::Converter(std::string path){
    img = cv::imread(path, cv::IMREAD_COLOR);

    this->path = path;

    if(!img.data){ // check if file can be read
        throw std::logic_error("Image could not be read; check file path");
    }
    
    // get dimensions
    width = img.cols;
    height = img.rows;
}

// actually returns a vector but close enough
std::vector<std::vector<Node>> Converter::to2Darray(){
    std::vector<std::vector<Node>> nodes(width);

    for (int i = 0; i < width; i++){
        std::vector<Node> row(height);
        for (int j = 0; j < height; j++){
            row[j].setDim(i,j);
        }
        nodes.push_back(row);
    }
    return nodes;
}