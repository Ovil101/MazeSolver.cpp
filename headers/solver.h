#include <vector>
#include "node.h"

class Solver{
    private:
        std::vector<std::vector<Node>> graph;
        double heuristic(Node end, Node finish);
    public:
        Solver(std::vector<std::vector<Node>> graph);
        std::vector<Node> aStar(Node start, Node finish);
};