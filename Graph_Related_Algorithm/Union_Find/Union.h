//
// Created by xinbochao on 18-6-17.
//

#ifndef UNION_FIND_UNION_H
#define UNION_FIND_UNION_H

#include <vector>
#include <iostream>

using std::vector;
using std::size_t;

// this Union is implemented using weighted quick-union
// find ~ Olog(n)
// union ~ Olog(n)
class WeightedQuickUF {
 public:
  explicit WeightedQuickUF(unsigned int size);
  int getCC() const;
  bool isConnected(size_t p, size_t q) const;
  size_t find(size_t p) const;
  void Union(size_t p, size_t q);
  friend std::ostream& operator<<(std::ostream& os, const WeightedQuickUF& UF);

 private:
  int height(size_t p);
  vector<long> disjointSet;
  int numOfCC; // CC stands for Connected Component
};

#endif //UNION_FIND_UNION_H
