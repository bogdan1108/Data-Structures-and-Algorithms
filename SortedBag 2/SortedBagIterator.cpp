#include <stdexcept>
#include "SortedBagIterator.h"

// Constructor for the SortedBagIterator class
SortedBagIterator::SortedBagIterator(const SortedBag &sb): sb{sb}, stack{std::stack<int>{}} {
    // Call the first() function to initialize the iterator
    first();
}
// O(log n)

// Move the iterator to the first element of the sorted bag
void SortedBagIterator::first() {
    // Set the current node to the root of the sorted bag
    currentNode = sb.root;
    // Traverse down the left subtree of the current node and push the nodes onto the stack
    while (currentNode != -1) {
        stack.push(currentNode);
        currentNode = sb.tree[currentNode].getLeftSon();
    }
    // If the stack is not empty, set the current node to the top of the stack
    if (!stack.empty()) {
        currentNode = stack.top();
    }
    // Otherwise, set the current node to -1 indicating the end of the bag
    else {
        currentNode = -1;
    }
}
// O(log n)


// Move the iterator to the next element in the sorted bag
void SortedBagIterator::next() {
    // If the iterator is not valid, throw a runtime error
    if (!valid()) {
        throw std::runtime_error{""};
    }
    // Get the current node from the top of the stack
    int node = stack.top();
    stack.pop();
    // If the current node has a right subtree, traverse down its left subtree and push the nodes onto the stack
    if (sb.tree[node].getRightSon() != -1) {
        node = sb.tree[node].getRightSon();
        while (node != -1) {
            stack.push(node);
            node = sb.tree[node].getLeftSon();
        }
    }
    // If the stack is not empty, set the current node to the top of the stack
    if (!stack.empty()) {
        currentNode = stack.top();
    }
    // Otherwise, set the current node to -1 indicating the end of the bag
    else {
        currentNode = -1;
    }
}
// O(log n)


// Check if the iterator is valid (i.e., pointing to a valid element)
bool SortedBagIterator::valid() const {
    return currentNode != -1;
}
// O(1)


// Get the current element from the sorted bag
TComp SortedBagIterator::getCurrent() const {
    // If the iterator is not valid, throw a runtime error
    if (!valid()) {
        throw std::runtime_error{""};
    }
    // Return the value of the current node
    return sb.tree[currentNode].getValue();
}
// O(1)