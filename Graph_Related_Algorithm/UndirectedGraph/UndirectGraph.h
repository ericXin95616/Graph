//
// Created by xinbochao on 18-7-12.
//

#ifndef GRAPH_UNDIRECTGRAPH_H
#define GRAPH_UNDIRECTGRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <LinkedList.h>

using std::string;
using std::vector;

class undirectGraph {
public:
    explicit undirectGraph(unsigned int Vertices);
    explicit undirectGraph(std::istream& input);
    unsigned int getV() const { return numOfV; } // get the number of vertices
    unsigned int getE() const { return numOfE; } // get the number of edges
    void addEdge(int v, int w); // add edge between vertices v&w
    LinkedList<int> adj(int v); // return the adjacent vertices of v
    string toString() const;

private:
    unsigned int numOfV;
    unsigned int numOfE;
    vector<LinkedList<int>> adjacentList;
};

#endif //GRAPH_UNDIRECTGRAPH_H
