#include "SortedBag.h"

// Constructor for the SortedBag class
SortedBag::SortedBag(Relation r): root{-1}, numberOfElements{0}, capacity{16}, firstFree{0}, r{r}
{
    // Create a new array of BSTNode objects with initial capacity 16
    tree = new BSTNode[16];
}
// O(1)


// Add an element to the sorted bag
void SortedBag::add(TComp e) {
    // Check if the array needs to be resized
    if (mustBeResized()) {
        resize();
    }
    // Set the value of the first free node to the given element
    tree[firstFree].setValue(e);
    // Set the left and right sons of the first free node to -1 (indicating no children)
    tree[firstFree].setLeftSon(-1);
    tree[firstFree].setRightSon(-1);
    int current = root, parent = -1;
    // Traverse the tree to find the correct position for the new element
    while (current != -1) {
        parent = current;
        // Compare the new element with the value of the current node and move left or right accordingly
        if (r(e, tree[current].getValue()))
            current = tree[current].getLeftSon();
        else
            current = tree[current].getRightSon();
    }
    // Update the parent node to point to the new element
    if (root == -1)
        root = firstFree;
    else if (r(e, tree[parent].getValue()))
        tree[parent].setLeftSon(firstFree);
    else
        tree[parent].setRightSon(firstFree);
    // Update the index of the first free node
    changeFirstFree();
    // Increment the number of elements in the bag
    ++numberOfElements;
}
// avg: O(log n), worst: O(n)


// Update the index of the first free node in the tree array
void SortedBag::changeFirstFree() {
    ++firstFree;
    while (firstFree < capacity && !tree[firstFree].isNull())
        ++firstFree;
}
// O(n)


// Remove an element from the sorted bag
bool SortedBag::remove(TComp e) {
    bool removed = false;
    // Recursively remove the element from the tree starting from the root node
    root = removeRecursively(root, e, removed);
    // Decrement the number of elements if the element was successfully removed
    if (removed)
        --numberOfElements;
    return removed;
}
// avg: O(log n), worst: O(n)


// Search for an element in the sorted bag
bool SortedBag::search(TComp e) const {
    int currentNode = root;
    // Traverse the tree until the element is found or the end of the tree is reached
    while (currentNode != -1) {
        if (tree[currentNode].getValue() == e)
            return true;
        if (r(e, tree[currentNode].getValue())) {
            currentNode = tree[currentNode].getLeftSon();
        }
        else {
            currentNode = tree[currentNode].getRightSon();
        }
    }
    // The element was not found
    return false;
}
// avg: O(log n), worst: O(n)


// Get the number of occurrences of an element in the sorted bag
int SortedBag::nrOccurrences(TComp e) const {
    int currentNode = root;
    int counter = 0;
    // Traverse the tree and count the occurrences of the element
    while (currentNode != -1) {
        if (tree[currentNode].getValue() == e)
            ++counter;
        if (r(e, tree[currentNode].getValue())) {
            currentNode = tree[currentNode].getLeftSon();
        }
        else {
            currentNode = tree[currentNode].getRightSon();
        }
    }
    return counter;
}
// avg: O(log n), worst: O(n)


// Get the number of elements in the sorted bag
int SortedBag::size() const {
    return numberOfElements;
}

// Create and return an iterator for the sorted bag
SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}

// Check if the sorted bag is empty
bool SortedBag::isEmpty() const {
    return numberOfElements == 0;
}

// Destructor for the SortedBag class
SortedBag::~SortedBag() {
    delete[] tree;
}

// Check if the array needs to be resized
bool SortedBag::mustBeResized() {
    return firstFree >= capacity;
}

// Resize the array by doubling its capacity
void SortedBag::resize() {
    auto *newTree = new BSTNode[capacity * 2];
    for (int i = 0; i < capacity; ++i) {
        newTree[i].setValue(tree[i].getValue());
        newTree[i].setLeftSon(tree[i].getLeftSon());
        newTree[i].setRightSon(tree[i].getRightSon());
    }
    delete[] tree;
    tree = newTree;
    firstFree = capacity;
    capacity *= 2;
}
// O(n)


// Get the maximum element in the subtree rooted at the given starting root
TComp SortedBag::getMaximum(int startingRoot) {
    int currentNode = startingRoot, maxNode = startingRoot;
    TComp maximum;
    // Traverse the right subtree to find the maximum element
    while (currentNode != -1) {
        maximum = tree[currentNode].getValue();
        maxNode = currentNode;
        currentNode = tree[currentNode].getRightSon();
    }
    return maxNode;
}
// avg: O(log n), worst: O(n)


// Recursively remove an element from the subtree rooted at the given node
int SortedBag::removeRecursively(int node, TComp e, bool &removed) {
    if (node == -1)
        return node;
    if (e == tree[node].getValue()) {
        removed = true;
        // If the node has no left child, replace it with its right child
        if (tree[node].getLeftSon() == -1) {
            int rightSon = tree[node].getRightSon();
            tree[node] = BSTNode{NULL_TCOMP, -1, -1};
            return rightSon;
        }
        // If the node has no right child, replace it with its left child
        else if (tree[node].getRightSon() == -1) {
            int leftSon = tree[node].getLeftSon();
            tree[node] = BSTNode{NULL_TCOMP, -1, -1};
            return leftSon;
        }
        // If the node has both left and right children, replace it with the maximum element from the left subtree
        int maxNode = getMaximum(tree[node].getLeftSon());
        tree[node].setValue(tree[maxNode].getValue());
        tree[node].setLeftSon(removeRecursively(tree[node].getLeftSon(), tree[maxNode].getValue(), removed));
    }
    // Recursively remove the element from the left or right subtree
    else if (r(e, tree[node].getValue())) {
        tree[node].setLeftSon(removeRecursively(tree[node].getLeftSon(), e, removed));
    }
    else {
        tree[node].setRightSon(removeRecursively(tree[node].getRightSon(), e, removed));
    }
    return node;
}
// avg: O(log n), worst: O(n)