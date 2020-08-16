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
    std::vector<std::vector<Node>> nodes(width, std::vector<Node>(height));

    for (int i = 0; i < width; i++){ // initialization
        for (int j = 0; j < height; j++){
            nodes[i][j].setDim(i,j);
        }
    }

    const cv::Vec3b BLACK(0, 0, 0);
    const cv::Vec3b WHITE(255,255,255);

    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            cv::Vec3b pixel = img.at<cv::Vec3b>(i,j); // in BGR format, doesn't matter though
            if (pixel == BLACK){ // thank God C++ has operator overloading
                nodes[i][j].setIsWall(true);
            }
            else if (pixel == WHITE){
                nodes[i][j].setIsWall(false);
            }
            else{
                throw std::invalid_argument("Found non white or black pixel in image");
            }
        }
    }

    for (int row = 0; row < width; row++){
        for (int col = 0; col < width; col++){
            // use at().at() becuase at() throws exceptions while operator[] doesn't
            try {
                //    vvvvvvvvv should always work    vvvvvvvvvv might not work
                nodes[row][col].addNeighbor(nodes.at(row - 1).at(col)); // Node to the top
            }
            catch (const std::out_of_range& e) {
                nodes[row][col].addNeighbor(Node(-1, -1, false));
            }

            try {
                nodes[row][col].addNeighbor(nodes.at(row).at(col + 1)); // Node to the right
            }
            catch (const std::out_of_range& e) {
                nodes[row][col].addNeighbor(Node(-1, -1, false));
            }

            try {
                nodes[row][col].addNeighbor(nodes.at(row + 1).at(col)); // Node to the bottom
            }
            catch (const std::out_of_range& e) {
                nodes[row][col].addNeighbor(Node(-1, -1, false));
            }

            try {
                nodes[row][col].addNeighbor(nodes.at(row).at(col - 1)); // Node to the left
            }
            catch (const std::out_of_range& e) {
                nodes[row][col].addNeighbor(Node(-1, -1, false));
            }
        }
    }
    return nodes;
}