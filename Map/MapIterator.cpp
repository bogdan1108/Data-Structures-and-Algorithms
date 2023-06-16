#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	//TODO - Implementation
	this->current = d.head;
}
// Theta(1)


void MapIterator::first() {
	//TODO - Implementation
	// set the iterator to the first element of the container
	this->current = map.head;

}
// Theta(1)


void MapIterator::next() {
	//TODO - Implementation
	// move the iterator to the next element
	// throws exception if the iterator is not valid
	if (!valid())
		throw exception();
	this->current = this->current->next;

}
// Theta(1)


TElem MapIterator::getCurrent(){
	//TODO - Implementation
	// returns the current element from the iterator
	// throws exception if the iterator is not valid
	if (!valid())
		throw exception();
	TElem e = this->current->elem;
	return e;
}
// Theta(1)


bool MapIterator::valid() const {
	//TODO - Implementation
	// checks if the iterator is valid
	return (this->current != nullptr);
}
// Theta(1)



