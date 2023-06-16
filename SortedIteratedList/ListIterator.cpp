#include "ListIterator.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	//TODO - Implementation
	currentIndex = list.dllaList.head;
} // Theta(1)

void ListIterator::first(){
	//TODO - Implementation
	currentIndex = list.dllaList.head;
} // Theta(1)

void ListIterator::next(){
	//TODO - Implementation
	if (this->currentIndex == -1)
        throw exception();
    this->currentIndex = this->list.dllaList.next[this->currentIndex];
} // Theta(1)

bool ListIterator::valid() const{
	//TODO - Implementation
	if (this->currentIndex == -1)
	    return false;
    return true;
} // Theta(1)

TComp ListIterator::getCurrent() const{
	//TODO - Implementation
	if (this->currentIndex == -1)
        throw exception();
	return this->list.dllaList.elements[this->currentIndex];
} // Theta(1)

TComp ListIterator::remove() {
    if (this->currentIndex == -1)
        throw exception();

	TComp elem = this->list.dllaList.elements[this->currentIndex];

    return elem;
} // Theta(1)
