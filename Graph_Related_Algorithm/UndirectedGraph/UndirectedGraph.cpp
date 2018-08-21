//
// Created by xinbochao on 18-7-12.
//
#include "UndirectGraph.h"

undirectGraph::undirectGraph(unsigned int Vertices): numOfV(Vertices), numOfE(0), adjacentList(Vertices) {}

/*
 * Here is the input format we assume:
 * first line: number of vertices
 * second line: number of edges
 * 3 ~ 3+numOfV lines: describe edges by listing two vertices
 */
undirectGraph::undirectGraph(std::istream &input) {
    input >> numOfV >> numOfE;
    // initialize adjacent list
    for (int i = 0; i < numOfV; ++i) { adjacentList.emplace_back(LinkedList<int>()); }

    int v1, v2;
    for (int i = 0; i < numOfE; ++i) {
        input >> v1 >> v2;
        adjacentList[v1].push(v2);
        adjacentList[v2].push(v1);
    }
}

void undirectGraph::addEdge(int v, int w) {
    adjacentList[v].push(w);
    adjacentList[w].push(v);
    ++numOfE;
}

LinkedList<int> undirectGraph::adj(int v) {
    return adjacentList[v];
}

string undirectGraph::toString() const {
    string output, temp;
    stringstream ss;

    ss << numOfV;
    ss >> temp;
    ss.clear();
    output = temp + " vertices, ";

    ss << numOfE;
    ss >> temp;
    ss.clear();
    output = output + temp + " edges\n";

    for (int i = 0; i < numOfV; ++i) {
        ss << i;
        ss >> temp;
        ss.clear();
        output = output + temp + ": ";
        output = output + adjacentList[i].toString() + "\n";
    }

    return output;
}











