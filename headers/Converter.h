#include <string>
#include "headers/Node.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/core.hpp>

class Converter{
    private:
        std::string path;
        cv::Mat img;
        int height, width;
        
    public:
        Converter(std::string path);
        
};