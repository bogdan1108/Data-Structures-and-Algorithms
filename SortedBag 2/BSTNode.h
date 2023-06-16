#pragma once

typedef int TComp;
const int NULL_TCOMP = -99999999;

class BSTNode {
private:
    TComp value;
    int leftSon;
    int rightSon;
public:
    BSTNode(TComp value = NULL_TCOMP, int leftSon = -1, int rightSon = -1);
    TComp getValue() const;
    void setValue(TComp value);
    int getLeftSon() const;
    void setLeftSon(int leftSon);
    int getRightSon() const;
    void setRightSon(int rightSon);
    bool isNull();
    bool isLeaf();
};