#pragma once
#include "SortedBagIterator.h"
#include "BSTNode.h"

typedef int TComp;
typedef bool(*Relation)(TComp, TComp);
typedef int TElem;

class SortedBagIterator;

class SortedBag {
    friend class SortedBagIterator;

private:
    BSTNode *tree;
    int root;
    int numberOfElements;
    int capacity;
    int firstFree;
    Relation r;

    void changeFirstFree();
    bool mustBeResized();
    void resize();
    TComp getMaximum(int startingRoot);
    int removeRecursively(int node, TComp e, bool &removed);

public:
    SortedBag(Relation r);
    void add(TComp e);
    bool remove(TComp e);
    bool search(TComp e) const;
    int nrOccurrences(TComp e) const;
    int size() const;
    SortedBagIterator iterator() const;
    bool isEmpty() const;
    ~SortedBag();
};