#ifndef NODE_H
#define NODE_H

#include <vector>

class Node{
    private:
        double f, g, h;
        int row, col;
        bool isAWall;
        std::vector<Node> neighbors;
        Node *previous;

    public:
        Node(int r, int c, bool isWall);
        Node();
        int getRow();
        int getCol();
        double getF();
        double getG();
        double getH();
        void setF(double f);
        void setG(double g);
        void setH(double h);
        bool isWall();
        void setIsWall(bool isWall);
        void addNeighbor(Node b);
        void setPrevious(Node n);
        Node getPrevious();
        void setDim(int r, int c);
};
#endif