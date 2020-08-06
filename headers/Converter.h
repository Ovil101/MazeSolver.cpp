#include <string>
#include "Node.h"
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>

class Converter{
    private:
        std::string path;
        cv::Mat img;
        int height, width;
        
    public:
        Converter(std::string path);
        std::vector<std::vector<Node>> to2Darray();
        void toImage(std::vector<std::vector<Node>> graph, std::vector<Node> solution);
        Node getEndNode();
        Node getStartNode();
};