#pragma once
#include "SortedBag.h"
#include <stack>

class SortedBag;
typedef int TComp;

class SortedBagIterator {
    friend class SortedBag;

private:
    const SortedBag& sb;
    int currentNode;
    std::stack<int> stack;
    SortedBagIterator(const SortedBag& sb);

public:
    void first();
    void next();
    bool valid() const;
    TComp getCurrent() const;
};