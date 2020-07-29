/*
Converting image->node[] and node[]->image
*/ 
#include "headers/Converter.h"
using namespace cv;

Converter::Converter(std::string path){
    img = imread(path, IMREAD_COLOR);

    if(! img.data ){ // check if file can be read
        throw std::logic_error("Image could not be read; check file path");
    }
    
    // get dimensions
    width = img.cols;
    height = img.rows;
}

