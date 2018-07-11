//
// Created by xinbochao on 18-6-17.
//
#include "Union.h"

WeightedQuickUF::WeightedQuickUF(unsigned int size) : disjointSet(size), numOfCC(size) {
  // initialize disjointSet
  // index begins from 0 to size - 1
  for (int i = 0; i < size; ++i)
    disjointSet.at(i) = i;
}

int WeightedQuickUF::getCC() const {
  return numOfCC;
}

std::size_t WeightedQuickUF::find(size_t p) const {
  long rootIndex = disjointSet.at(p);

  while(rootIndex != p && rootIndex >= 0) {
    p = static_cast<size_t >(rootIndex);
    rootIndex = disjointSet.at(p);
  }

  return p;
}

bool WeightedQuickUF::isConnected(size_t p, size_t q) const {
  return find(p) == find(q);
}

int WeightedQuickUF::height(size_t p) {
  // index p is gaurantee to be the root of tree
  if(disjointSet.at(p) >= 0)
    return 0;
  return -(disjointSet.at(p));
}

void WeightedQuickUF::Union(size_t p, size_t q) {
  // if p and q is already connected,
  // we do nothing
  size_t rootOfP = find(p);
  size_t rootOfQ = find(q);
  if(rootOfP == rootOfQ) return;

  int htOfP = height(rootOfP);
  int htOfQ = height(rootOfQ);

  if(htOfP > htOfQ)
    disjointSet.at(rootOfQ) = rootOfP;
  else {
    disjointSet.at(rootOfP) = rootOfQ;
    // if htOfP == htOfQ, we need to increase htOfQ by 1
    if(htOfP == htOfQ) {
      if(htOfQ == 0) disjointSet.at(rootOfQ) = -1;
      else --disjointSet.at(rootOfQ);
    }
  }
  --numOfCC;
}

std::ostream& operator<<(std::ostream &os, const WeightedQuickUF &UF) {
  for (auto it = UF.disjointSet.cbegin(), end = UF.disjointSet.cend(); it != end ; ++it) {
    os << *it << " ";
  }
  return os;
}








