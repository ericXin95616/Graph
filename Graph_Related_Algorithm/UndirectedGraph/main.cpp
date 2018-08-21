//
// Created by xinbochao on 18-8-21.
//

#include <iostream>
#include <fstream>
#include "UndirectGraph.h"

// argc = 2, argv[1] = input file name
int main(int argc, char* argv[]) {
    std::ifstream input(argv[1]);

    if(!input) {
        std::cout << "Fail to open the input file \"" << argv[1] << "\".\n";
        return 0;
    }

    undirectGraph G(input);
    std::cout << G.toString();
}