/*
Responsible for solving maze
*/
#include <cmath>
#include "headers/Solver.h" // node is included here
#include <opencv4/opencv2/core.hpp>

Solver::Solver(std::vector<std::vector<Node>> nodeGraph){
    graph = nodeGraph;
}

std::vector<Node> Solver::aStar(Node start, Node finsh){
    // ignore warning from this line for now
    std::vector<Node> nodes;
    return nodes;
}

double Solver::heuristic(Node end, Node finish){
    int y1 = end.getCol();
    int x1 = end.getRow();
    int y2 = finish.getCol();
    int x2 = finish.getRow();
    return std::abs(x2 - x1) + std::abs(y2 - y1); // taxicab distance
    //return std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); // Euclidean distance
}