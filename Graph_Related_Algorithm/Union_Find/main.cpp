#include <iostream>
#include "Union.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  unsigned int size = 0, numOfOperation = 0;
  cin >> size >> numOfOperation;
  WeightedQuickUF UF(size);

  size_t p = 0, q = 0;
  for (int i = 0; i < numOfOperation; ++i) {
    cin >> p >> q;
    UF.Union(p, q);
    cout << UF.getCC() << endl;
    cout << UF << endl;
  }
}