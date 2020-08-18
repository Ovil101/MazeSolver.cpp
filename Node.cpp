/*
For storing Node data
*/
#include <vector>
#include "headers/Node.h"

Node::Node(int r, int c, bool isWall){
    row = r;
    col = c;
    isAWall = isWall;
}

Node::Node(){} // for the Node 2D array

int Node::getRow(){
    return row;
}

int Node::getCol(){
    return col;
}

double Node::getF() {
    return f;
}

double Node::getG() {
    return g;
}

double Node::getH() {
   return h;
}

void Node::setF(double f) {
    this->f = f;
}

void Node::setG(double g) {
    this->g = g;
}

void Node::setH(double h) {
    this->h = h;
}

bool Node::isWall() {
    return isAWall;
}

void Node::setIsWall(bool isWall) {
    this->isAWall = isWall;
}

void Node::addNeighbor(Node b) {
    neighbors.push_back(b);
}

void Node::setPrevious(Node n) {
    *previous = n;
}

Node Node::getPrevious() {
    return *previous;
}

void Node::setDim(int r, int c){
    row = r;
    col = c;
}