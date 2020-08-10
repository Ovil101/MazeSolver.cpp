/*
Converting image->node[] and node[]->image
*/ 
#include "headers/Converter.h"
#include <vector>
#include <iostream>
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

    for (int i = 0; i < width; i++){ // initialization
        std::vector<Node> row(height);
        for (int j = 0; j < height; j++){
            row[j].setDim(i,j);
        }
        nodes[i] = row;
    }
    const cv::Vec3b BLACK(0, 0, 0);
    const cv::Vec3b WHITE(255,255,255);
    for (int i = 0; i < width; i++){
        std::vector<Node> row = nodes[i];
        for (int j = 0; j < height; j++){
            cv::Vec3b pixel = img.at<cv::Vec3b>(i,j); // in BGR format
            if (pixel == BLACK){ // thank God C++ has operator overloading
                row[j].setIsWall(true); // segfault
            }
            else if (pixel == WHITE){
                row[j].setIsWall(false);
            }
            else{
                throw std::invalid_argument("Found non white or black pixel in image");
            }
        }
        
        nodes.erase(nodes.begin() + i); // remove old row
        nodes.insert(nodes.begin() + i, row); // add new row
    }

    for (int row = 0; row < width; row++){
        std::vector<Node> vec = nodes[row];
        for (int col = 0; col < width; col++){
            try{
                
            }
            catch(std::out_of_range e){

            }
        }
    }
    return nodes;
}